#ifndef DESENVOLVEDOR_HPP
#define DESENVOLVEDOR_HPP

#include <vector>
#include "usuario.hpp"
#include "item.hpp"

/* Subclasse de Usuario referente a estúdios/criadores de jogos.
 * Interações no Diagrama:
 * - Herda de Usuario.
 * - Publica e gerencia seus objetos Item na Loja.
 */
class Desenvolvedor : public Usuario {
private:
    std::vector<Item*> jogosPublicados;

public:
    Desenvolvedor(int id, std::string nome);
    ~Desenvolvedor() override = default;

    // Insere um novo jogo no catálogo público da Loja
    void publicarJogo(Item* jogo);

    // Retira um jogo de circulação do catálogo da Loja
    void removerJogo(Item* jogo);

    const std::vector<Item*>& getJogosPublicados() const { 
        return jogosPublicados; 
    }
};

#endif