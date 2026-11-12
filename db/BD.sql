-- Banco de dados: CONSOLEUI (MySQL)

DROP DATABASE IF EXISTS CONSOLEUI;
CREATE DATABASE CONSOLEUI
    CHARACTER SET utf8mb4
    COLLATE utf8mb4_unicode_ci;
USE CONSOLEUI;

-- TEMA (composição de Usuario)

CREATE TABLE TEMA (
    idTema INT UNSIGNED NOT NULL AUTO_INCREMENT,
    fonte VARCHAR(50) NOT NULL,
    corDetalhe VARCHAR(20) NOT NULL,
    sonsAtivos VARCHAR(100) NOT NULL,
    PRIMARY KEY (idTema)
) ENGINE=InnoDB;

-- USUARIO (classe base) + especializações

CREATE TABLE USUARIO (
    idUsuario INT UNSIGNED NOT NULL AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    username VARCHAR(150) NOT NULL,
    senha VARCHAR(255) NOT NULL,
    idTema INT UNSIGNED NOT NULL,
    PRIMARY KEY (idUsuario),
    CONSTRAINT fk_usuario_tema FOREIGN KEY (idTema)
        REFERENCES TEMA (idTema)
) ENGINE=InnoDB;

CREATE TABLE JOGADOR (
    idUsuario INT UNSIGNED NOT NULL,
    saldo DECIMAL(10,2) NOT NULL,
    PRIMARY KEY (idUsuario),
    CONSTRAINT fk_jogador_usuario FOREIGN KEY (idUsuario)
        REFERENCES USUARIO (idUsuario) ON DELETE CASCADE
) ENGINE=InnoDB;

CREATE TABLE DESENVOLVEDOR (
    idUsuario INT UNSIGNED NOT NULL,
    PRIMARY KEY (idUsuario),
    CONSTRAINT fk_desenvolvedor_usuario FOREIGN KEY (idUsuario)
        REFERENCES USUARIO (idUsuario) ON DELETE CASCADE
) ENGINE=InnoDB;

-- COMPOSIÇÕES DE JOGADOR: Configuracoes, Cartao, Notificacao, Biblioteca

CREATE TABLE CONFIGURACOES (
    idConfiguracoes INT UNSIGNED NOT NULL AUTO_INCREMENT,
    idJogador INT UNSIGNED NOT NULL,
    notificacoes BOOLEAN NOT NULL,
    PRIMARY KEY (idConfiguracoes),
    CONSTRAINT fk_configuracoes_jogador FOREIGN KEY (idJogador)
        REFERENCES JOGADOR (idUsuario) ON DELETE CASCADE
) ENGINE=InnoDB;

CREATE TABLE CARTAO (
    idCartao INT UNSIGNED NOT NULL AUTO_INCREMENT,
    idJogador INT UNSIGNED NOT NULL,
    numero VARCHAR(25) NOT NULL,
    titular VARCHAR(100) NOT NULL,
    PRIMARY KEY (idCartao),
    CONSTRAINT fk_cartao_jogador FOREIGN KEY (idJogador)
        REFERENCES JOGADOR (idUsuario) ON DELETE CASCADE
) ENGINE=InnoDB;

CREATE TABLE NOTIFICACAO (
    idNotificacao INT UNSIGNED NOT NULL AUTO_INCREMENT,
    idJogador INT UNSIGNED NOT NULL,
    mensagem VARCHAR(255) NOT NULL,
    dataHora DATETIME NOT NULL,
    lida BOOLEAN NOT NULL,
    PRIMARY KEY (idNotificacao),
    CONSTRAINT fk_notificacao_jogador FOREIGN KEY (idJogador)
        REFERENCES JOGADOR (idUsuario) ON DELETE CASCADE
) ENGINE=InnoDB;

CREATE TABLE BIBLIOTECA (
    idBiblioteca INT UNSIGNED NOT NULL AUTO_INCREMENT,
    idJogador INT UNSIGNED NOT NULL,
    PRIMARY KEY (idBiblioteca),
    CONSTRAINT fk_biblioteca_jogador FOREIGN KEY (idJogador)
        REFERENCES JOGADOR (idUsuario) ON DELETE CASCADE
) ENGINE=InnoDB;

-- GENERO (usado por Item.genero e Jogador.generosFav)

CREATE TABLE GENEROITEM (
    idGenero INT UNSIGNED NOT NULL AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    PRIMARY KEY (idGenero)
) ENGINE=InnoDB;

CREATE TABLE JOGADOR_GENERO_FAV (
    idJogador INT UNSIGNED NOT NULL,
    idGenero INT UNSIGNED NOT NULL,
    PRIMARY KEY (idJogador, idGenero),
    CONSTRAINT fk_jogadorgenerofav_jogador FOREIGN KEY (idJogador)
        REFERENCES JOGADOR (idUsuario) ON DELETE CASCADE,
    CONSTRAINT fk_jogadorgenerofav_genero FOREIGN KEY (idGenero)
        REFERENCES GENERO (idGenero) ON DELETE CASCADE
) ENGINE=InnoDB;

-- AMIZADE (auto-relacionamento de Jogador)

CREATE TABLE AMIZADE (
    idSolicitante INT UNSIGNED NOT NULL,
    idDestinatario INT UNSIGNED NOT NULL,
    status ENUM('pendente','aceita','negada') NOT NULL,
    PRIMARY KEY (idSolicitante, idDestinatario),
    CONSTRAINT fk_amizade_solicitante FOREIGN KEY (idSolicitante)
        REFERENCES JOGADOR (idUsuario) ON DELETE CASCADE,
    CONSTRAINT fk_amizade_destinatario FOREIGN KEY (idDestinatario)
        REFERENCES JOGADOR (idUsuario) ON DELETE CASCADE
) ENGINE=InnoDB;

-- LOJA

CREATE TABLE LOJA (
    idLoja INT UNSIGNED NOT NULL AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    PRIMARY KEY (idLoja)
) ENGINE=InnoDB;

-- ITEM (classe abstrata) + JogoJogavel / JogoMidia

CREATE TABLE ITEM (
    idItem INT UNSIGNED NOT NULL AUTO_INCREMENT,
    idDev INT UNSIGNED NOT NULL,
    idLoja INT UNSIGNED NOT NULL,
    idGenero INT UNSIGNED NOT NULL,
    nome VARCHAR(150) NOT NULL,
    armazenamento DECIMAL(10,2) NOT NULL,
    preco DECIMAL(10,2) NOT NULL,
    faixaEtaria TINYINT UNSIGNED NOT NULL,
    emprestado BOOLEAN NOT NULL,
    tipo ENUM('jogavel','midia') NOT NULL,
    PRIMARY KEY (idItem),
    CONSTRAINT fk_item_dev FOREIGN KEY (idDev)
        REFERENCES DESENVOLVEDOR (idUsuario),
    CONSTRAINT fk_item_loja FOREIGN KEY (idLoja)
        REFERENCES LOJA (idLoja),
    CONSTRAINT fk_item_genero FOREIGN KEY (idGenero)
        REFERENCES GENERO (idGenero)
) ENGINE=InnoDB;

CREATE TABLE JOGOJOGAVEL (
    idItem INT UNSIGNED NOT NULL,
    PRIMARY KEY (idItem),
    CONSTRAINT fk_jogojogavel_item FOREIGN KEY (idItem)
        REFERENCES ITEM (idItem) ON DELETE CASCADE
) ENGINE=InnoDB;

CREATE TABLE JOGOMIDIA (
    idItem INT UNSIGNED NOT NULL,
    PRIMARY KEY (idItem),
    CONSTRAINT fk_jogomidia_item FOREIGN KEY (idItem)
        REFERENCES ITEM (idItem) ON DELETE CASCADE
) ENGINE=InnoDB;

-- BIBLIOTECA <-> ITEM (jogosAdquiridos + jogosInstalados)

CREATE TABLE BIBLIOTECA_ITEM (
    idBiblioteca INT UNSIGNED NOT NULL,
    idItem INT UNSIGNED NOT NULL,
    instalado BOOLEAN NOT NULL,
    PRIMARY KEY (idBiblioteca, idItem),
    CONSTRAINT fk_bibliotecaitem_biblioteca FOREIGN KEY (idBiblioteca)
        REFERENCES BIBLIOTECA (idBiblioteca) ON DELETE CASCADE,
    CONSTRAINT fk_bibliotecaitem_item FOREIGN KEY (idItem)
        REFERENCES ITEM (idItem) ON DELETE CASCADE
) ENGINE=InnoDB;

-- TROFEU (composição de Item) + conquistas do jogador

CREATE TABLE TROFEU (
    idTrofeu INT UNSIGNED NOT NULL AUTO_INCREMENT,
    idItem INT UNSIGNED NOT NULL,
    nome VARCHAR(100) NOT NULL,
    descricao VARCHAR(255) NOT NULL,
    objetivo VARCHAR(255) NOT NULL,
    PRIMARY KEY (idTrofeu),
    CONSTRAINT fk_trofeu_item FOREIGN KEY (idItem)
        REFERENCES ITEM (idItem) ON DELETE CASCADE
) ENGINE=InnoDB;

CREATE TABLE JOGADOR_TROFEU (
    idJogador INT UNSIGNED NOT NULL,
    idTrofeu INT UNSIGNED NOT NULL,
    PRIMARY KEY (idJogador, idTrofeu),
    CONSTRAINT fk_jogadortrofeu_jogador FOREIGN KEY (idJogador)
        REFERENCES JOGADOR (idUsuario) ON DELETE CASCADE,
    CONSTRAINT fk_jogadortrofeu_trofeu FOREIGN KEY (idTrofeu)
        REFERENCES TROFEU (idTrofeu) ON DELETE CASCADE
) ENGINE=InnoDB;

-- AVALIACAO (composição de Item, autor é Jogador)

CREATE TABLE AVALIACAO (
    idAvaliacao INT UNSIGNED NOT NULL AUTO_INCREMENT,
    idItem INT UNSIGNED NOT NULL,
    idAutor INT UNSIGNED NOT NULL,
    nota TINYINT UNSIGNED NOT NULL,
    comentario VARCHAR(500) NULL,
    PRIMARY KEY (idAvaliacao),
    CONSTRAINT fk_avaliacao_item FOREIGN KEY (idItem)
        REFERENCES ITEM (idItem) ON DELETE CASCADE,
    CONSTRAINT fk_avaliacao_autor FOREIGN KEY (idAutor)
        REFERENCES JOGADOR (idUsuario) ON DELETE CASCADE
) ENGINE=InnoDB;

-- EMPRESTIMO (dono e receptor são Jogadores)

CREATE TABLE EMPRESTIMO (
    idEmprestimo INT UNSIGNED NOT NULL AUTO_INCREMENT,
    idItem INT UNSIGNED NOT NULL,
    idDono INT UNSIGNED NOT NULL,
    idReceptor INT UNSIGNED NOT NULL,
    dataInicio DATETIME NOT NULL,
    dataFim DATETIME NOT NULL,
    devolvido BOOLEAN NOT NULL,
    PRIMARY KEY (idEmprestimo),
    CONSTRAINT fk_emprestimo_item FOREIGN KEY (idItem)
        REFERENCES ITEM (idItem),
    CONSTRAINT fk_emprestimo_dono FOREIGN KEY (idDono)
        REFERENCES JOGADOR (idUsuario),
    CONSTRAINT fk_emprestimo_receptor FOREIGN KEY (idReceptor)
        REFERENCES JOGADOR (idUsuario)
) ENGINE=InnoDB;
