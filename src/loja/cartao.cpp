#include "../../include/loja/cartao.hpp"
#include <string>
#include <vector>

// Armazena os dados do cartão.
Cartao::Cartao(std::string numero, std::string titular)
:_numero(numero), _titular(titular){}
Cartao::~Cartao(){}

// Retorna o número do cartão.
std::string Cartao::getNumero()const {
    return _numero;
}
// Retorna o nome do titular.
std::string Cartao::getTitular()const {
    return _titular;
}