#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <vector>
#include "trofeu.hpp"

// Declarações antecipadas
class Desenvolvedor;
class Avaliacao;

/* Classe base abstrata para todos os jogos/mídias cadastrados na loja.
 * Interações no Diagrama:
 * - Classe pai (Herança) de JogoJogavel e JogoMidia.
 * - Relacionada a Desenvolvedor (autor/publicador do item).
 * - Armazena listas de Avaliacao e Trofeu.
 * - Gerenciada pela Loja e pela Biblioteca.
 */
class Item {
protected:
    int idItem;
    Desenvolvedor* dev;
    std::string nome;
    double armazenamento;
    std::string genero;
    double preco;
    int faixaEtaria;
    std::vector<Avaliacao*> avaliacoes;
    bool emprestado;
    std::vector<Trofeu> listaTrofeus;

public:
    Item(int id, Desenvolvedor* dev, std::string nome, double armazenamento,
         std::string genero, double preco, int faixaEtaria);
    virtual ~Item();

    // Exibe no terminal/GUI todas as avaliações recebidas pelo item
    void mostrarAvaliacao() const;

    // Adiciona uma nova nota/comentário ao vetor de avaliações
    void adicionarAvaliacao(Avaliacao* av);

    // Retorna a nota média baseada nas avaliações recebidas
    double calcularMedia() const;

    // Método polimórfico abstrato: define como o jogo é inicializado
    virtual bool executar() = 0;

    int getIdItem() const {
        return idItem; 
    }
    std::string getNome() const {
        return nome; 
    }
    double getArmazenamento() const { 
        return armazenamento; 
    }
    std::string getGenero() const { 
        return genero; 
    }
    double getPreco() const { 
        return preco; 
    }
    int getFaixaEtaria() const { 
        return faixaEtaria; 
    }
    bool isEmprestado() const { 
        return emprestado; 
    }

    void setEmprestado(bool valor) { 
        emprestado = valor; 
    }
};

#endif