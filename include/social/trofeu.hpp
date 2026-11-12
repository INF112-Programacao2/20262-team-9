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
    std::string _nome;
    std::string _descricao;
    std::string _objetivo;

public:
    Trofeu(std::string nome, std::string descricao, std::string objetivo);
    ~Trofeu();

    std::string getNome() const;
    std::string getDescricao() const;
    std::string getObjetivo() const;
};

#endif