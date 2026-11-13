#include "../../include/social/trofeu.hpp"
#include <string>
#include <vector>

Trofeu::Trofeu(std::string nome, std::string descricao, std::string objetivo)
: _nome(nome), _descricao(descricao), _objetivo(objetivo) {}
Trofeu::~Trofeu() {}

// Retorna o nome do troféu.
std::string Trofeu::getNome()const{
    return _nome;
}
// Retorna a descrição do troféu.
std::string Trofeu::getDescricao()const{
    return _descricao;
}

// Retorna o objetivo necessário para obter o troféu.
std::string Trofeu::getObjetivo()const{
    return _objetivo;
}