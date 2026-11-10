#ifndef CARTAO_HPP
#define CARTAO_HPP

#include <string>

/* Modela os dados de um cartão de crédito cadastrado para pagamentos. 
 * Interações no Diagrama:
 * - Associação 0..* com Jogador (um Jogador pode possuir vários cartões).
 */
class Cartao {
private:
    std::string numero;
    std::string titular;

public:
    Cartao(std::string numero, std::string titular);
    ~Cartao() = default;

    std::string getNumero() const { 
        return numero;
    }
    std::string getTitular() const {
        return titular;
    }
};

#endif