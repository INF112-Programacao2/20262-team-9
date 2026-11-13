#include "../../include/loja/biblioteca.hpp"
#include <string>
#include <vector>

Biblioteca::Biblioteca(int id):_idBiblioteca(id){}
Biblioteca::~Biblioteca(){}

bool Biblioteca::instalar(Item* jogo){

}
bool Biblioteca::desinstalar(Item*jogo){

}
int Biblioteca::getIdBiblioteca()const{
    return _idBiblioteca;
}
const std::vector<Item*>& Biblioteca::getJogosAdquiridos() const{
    return _jogosAdquiridos;
}
const std::vector<Item*>& Biblioteca::getJogosInstalados() const{
    return _jogosInstalados;
}
void Biblioteca::adicionarJogo(Item* jogo){

}
void Biblioteca::adicionarAvaliacaoJogo(Item* jogo, Avaliacao* avaliacao){

}