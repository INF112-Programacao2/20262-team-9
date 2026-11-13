#include "../../include/social/trofeu.hpp"
#include <string>
#include <vector>

Trofeu::Trofeu(std::string nome, std::string descricao, std::string objetivo)
:_nome(nome), _descricao(descricao), _objetivo(objetivo){}
Trofeu::~Trofeu(){}

std::string Trofeu::getNome()const{
    return _nome;
}
std::string Trofeu::getDescricao()const{
    return _descricao;
}
std::string Trofeu::getObjetivo()const{
    return _objetivo;
}