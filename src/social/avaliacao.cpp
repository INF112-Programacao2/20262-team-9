#include "../../include/social/avaliacao.hpp"
#include <string>
#include <vector>

Avaliacao::Avaliacao(int nota, std::string comentario, Jogador* autor)
:_nota(nota), _comentario(comentario), _autor(autor){}
Avaliacao::~Avaliacao(){}

int Avaliacao::getNota() const{
    return _nota;
}
std::string Avaliacao::getComentario() const{
    return _comentario;
}
Jogador* Avaliacao::getAutor() const{
    return _autor;
}