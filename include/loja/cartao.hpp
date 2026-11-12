#ifndef CARTAO_HPP
#define CARTAO_HPP

#include <string>

/* Modela os dados de um cartão de crédito cadastrado para pagamentos. 
 * Interações no Diagrama:
 * - Associação 0..* com Jogador (um Jogador pode possuir vários cartões).
 */
class Cartao {
private:
    std::string _numero;
    std::string _titular;

public:
    Cartao(std::string numero, std::string titular);
    ~Cartao();

    std::string getNumero() const;
    std::string getTitular() const;
};

#endif