#ifndef LOJA_HPP
#define LOJA_HPP

#include <vector>
#include <string>
#include "item.hpp"

class Jogador; 
/* Cataloga todos os jogos disponíveis para compra e busca. 
 * Interações no Diagrama:
 * - Mantém a coleção principal de ponteiros para Item do sistema.
 * - Consultada por Jogador e atualizada por Desenvolvedor.
 */
class Loja {
private:
    int idLoja;
    std::vector<Item*> catalogo;

public:
    Loja(int id = 1);
    ~Loja() = default;

    // Imprime/lista todos os itens cadastrados no catálogo
    void listarJogos() const;

    // Retorna uma lista de jogos filtrados por categoria (RPG, Ação, etc.)
    std::vector<Item*> filtrarGenero(const std::string& genero) const;

    // Realiza busca de um jogo por nome aproximado ou ID
    Item* buscarJogo(const std::string& nome) const;

    // Gera lista de sugestões baseada nos gêneros favoritos do Jogador
    std::vector<Item*> recomendar(const Jogador* jogador) const;

    void adicionarAoCatalogo(Item* jogo) { 
        catalogo.push_back(jogo); 
    }
    const std::vector<Item*>& getCatalogo() const { 
        return catalogo;
    }
};

#endif