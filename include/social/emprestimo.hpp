#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include <ctime>

// Declarações antecipadas
class Item;
class Jogador;

/* Controla o fluxo de empréstimo temporário de jogos entre Jogadores.
 * Interações no Diagrama:
 * - Conecta 1 Item com 2 objetos Jogador (Dono e Receptor).
 */
class Emprestimo {
private:
    Item* jogoEmprestado;
    Jogador* donojogador;
    Jogador* receptor;
    std::tm dataInicio;
    std::tm dataFim;

public:
    Emprestimo(Item* jogo, Jogador* dono, Jogador* receptor, std::tm inicio, std::tm fim);
    ~Emprestimo() = default;

    // Transfere temporariamente a permissão de execução para o receptor
    bool emprestar();

    // Finaliza a cessão e devolve o acesso total ao proprietário original
    bool devolver();

    Item* getJogoEmprestado() const { 
        return jogoEmprestado; 
    }
    Jogador* getDono() const { 
        return donojogador; 
    }
    Jogador* getReceptor() const { 
        return receptor; 
    }
};

#endif