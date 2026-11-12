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
    Item* _jogoEmprestado;
    Jogador* _donojogador;
    Jogador* _receptor;
    std::tm _dataInicio;
    std::tm _dataFim;

public:
    Emprestimo(Item* jogo, Jogador* dono, Jogador* receptor, std::tm inicio, std::tm fim);
    ~Emprestimo();

    // Transfere temporariamente a permissão de execução para o receptor
    bool emprestar();

    // Finaliza a cessão e devolve o acesso total ao proprietário original
    bool devolver();

    Item* getJogoEmprestado() const;
    Jogador* getDono() const;
    Jogador* getReceptor() const; 
};

#endif