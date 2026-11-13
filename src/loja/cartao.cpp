#include "../../include/loja/cartao.hpp"
#include <string>
#include <vector>

Cartao::Cartao(std::string numero, std::string titular)
:_numero(numero), _titular(titular){}
Cartao::~Cartao(){}

std::string Cartao::getNumero()const {
    return _numero;
}
std::string Cartao::getTitular()const {
    return _titular;
}