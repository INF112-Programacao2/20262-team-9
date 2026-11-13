#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <vector>
#include "item.hpp"

class Item;

/**
 * @brief Gerencia o acervo pessoal do Jogador, separando jogos comprados e instalados.
 * 
 * Interações no Diagrama:
 * - Pertence a 1 Jogador (Composição/Agregação forte).
 * - Armazena ponteiros para objetos do tipo Item.
 */
class Biblioteca {
private:
    int _idBiblioteca;
    std::vector<Item*> _jogosAdquiridos;
    std::vector<Item*> _jogosInstalados;

public:
    Biblioteca(int id = 0);
    ~Biblioteca();

    // Aloca o jogo no espaço de armazenamento (SSD do console)
    bool instalar(Item* jogo);

    // Libera o espaço do jogo no SSD sem removê-lo dos jogos adquiridos
    bool desinstalar(Item* jogo);

    int getIdBiblioteca() const;
    const std::vector<Item*>& getJogosAdquiridos() const;
    const std::vector<Item*>& getJogosInstalados() const;
    void adicionarJogo(Item* jogo);
    void adicionarAvaliacaoJogo(Item* jogo, Avaliacao* avaliacao);
};

#endif