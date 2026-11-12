#include <string>
#include  "../../include/usuario/jogador.hpp"

    Jogador::Jogador(int id, std::string nome, std::string username, std::string senha, double saldoInicial = 0.0):
    Usuario(id, nome, username, senha), _saldo(saldoInicial){}
    Jogador::~Jogador(){}

    // Associa um novo cartão de crédito à conta
    void Jogador::addCartao(const Cartao& cartao){}

    // Descadastra um cartão a partir de seu número
    void Jogador::removerCartao(const std::string& numero){}

    // Incrementa a carteira digital com créditos em R$
    void Jogador::addSaldo(double valor){}

    // Registra gêneros de preferência para motor de recomendação
    void Jogador::addGeneroFav(const std::string& genero){}

    // Escreve uma avaliação para um jogo que possui
    void Jogador::avaliarJogo(Item* jogo, int nota, const std::string& comentario){}

    // Processa a compra de um item da Loja, debitando saldo e adicionando à Biblioteca
    bool Jogador::comprarJogo(Item* jogo){}

    // Adiciona um troféu conquistado à coleção do perfil
    void Jogador::conqTrofeu(const Trofeu& trofeu){}

    // Envia solicitação de amizade a outro Jogador
    void Jogador::solicitarAmizade(Jogador* amigo){}

    // Rejeita pedido de amizade pendente
    void Jogador::negarAmizade(Jogador* amigo){}

    // Adiciona o jogador solicitante à lista de amigos
    void Jogador::aceitarAmizade(Jogador* amigo){}

    // Exibe a lista de conquistas obtidas
    void Jogador::listarTrofeu() const{}

    // Recebe e adiciona uma notificação na caixa de entrada
    void Jogador::receberNotif(const Notificacao& notif){}

    double Jogador::getSaldo() const { 
        return _saldo; 
    }
    Biblioteca& Jogador::getBiblioteca() { 
        return _biblioteca; 
    }
    const std::vector<Jogador*>& Jogador::getAmigos() const { 
        return _amigos; 
    }
    const std::vector<Trofeu>& Jogador::getTrofeus() const { 
        return _trofeusConc; 
    }