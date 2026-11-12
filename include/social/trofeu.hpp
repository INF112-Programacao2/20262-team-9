#ifndef TROFEU_HPP
#define TROFEU_HPP

#include <string>

/* Representa uma conquista/troféu obtido dentro de um jogo.
 * Interações no Diagrama:
 * - Associação 0..* com Item (lista de troféus disponíveis no jogo).
 * - Associação 0..* com Jogador (troféus efetivamente desbloqueados).
 */
class Trofeu {
private:
    std::string nome;
    std::string descricao;
    std::string objetivo;

public:
    Trofeu(std::string nome, std::string descricao, std::string objetivo);
    ~Trofeu() = default;

    std::string getNome() const {
        return nome;
    }
    std::string getDescricao() const {
        return descricao;
    }
    std::string getObjetivo() const {
        return objetivo;
    }
};

#endif