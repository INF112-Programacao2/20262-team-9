#ifndef DESENVOLVEDOR_HPP
#define DESENVOLVEDOR_HPP

#include <string>
#include <vector>
#include "usuario.hpp"
#include "item.hpp"

/* Subclasse de Usuario referente a estúdios/criadores de jogos.
 * Interações no Diagrama:
 * - Herda de Usuario (repassando id, nome, username e senha)[cite: 5].
 * - Publica e gerencia seus objetos Item na Loja[cite: 5].
 */
class Desenvolvedor : public Usuario {
private:
    std::vector<Item*> _jogosPublicados;

public:
    Desenvolvedor(int id, std::string nome, std::string username, std::string senha);
    ~Desenvolvedor() override;

    // Insere um novo jogo no catálogo público da Loja
    void publicarJogo(Item* jogo);

    // Retira um jogo de circulação do catálogo da Loja
    void removerJogo(Item* jogo);

    const std::vector<Item*>& getJogosPublicados() const;
};

#endif