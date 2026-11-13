#include "../../include/social/avaliacao.hpp"
#include <string>
#include <vector>

Avaliacao::Avaliacao(int nota, std::string comentario, Jogador* autor)
:_nota(nota), _comentario(comentario), _autor(autor){}
Avaliacao::~Avaliacao(){}

// Retorna a nota atribuída.
int Avaliacao::getNota() const{
    return _nota;
}

// Retorna o comentário da avaliação.
std::string Avaliacao::getComentario() const{
    return _comentario;
}

// Retorna o jogador que escreveu a avaliação.
Jogador* Avaliacao::getAutor() const{
    return _autor;
}