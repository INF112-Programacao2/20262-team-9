#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <vector>
#include "item.hpp"

/**
 * @brief Gerencia o acervo pessoal do Jogador, separando jogos comprados e instalados.
 * 
 * Interações no Diagrama:
 * - Pertence a 1 Jogador (Composição/Agregação forte).
 * - Armazena ponteiros para objetos do tipo Item.
 */
class Biblioteca {
private:
    int idBiblioteca;
    std::vector<Item*> jogosAdquiridos;
    std::vector<Item*> jogosInstalados;

public:
    Biblioteca(int id = 0);
    ~Biblioteca() = default;

    // Aloca o jogo no espaço de armazenamento (SSD do console)
    bool instalar(Item* jogo);

    // Libera o espaço do jogo no SSD sem removê-lo dos jogos adquiridos
    bool desinstalar(Item* jogo);

    int getIdBiblioteca() const {
         return idBiblioteca; 
    }
    const std::vector<Item*>& getJogosAdquiridos() const { 
        return jogosAdquiridos; 
    }
    const std::vector<Item*>& getJogosInstalados() const { 
        return jogosInstalados; 
    }
    void adicionarJogo(Item* jogo) { 
        jogosAdquiridos.push_back(jogo); 
    }
};

#endif