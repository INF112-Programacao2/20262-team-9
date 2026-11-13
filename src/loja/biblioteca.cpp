#include "../../include/loja/biblioteca.hpp"
#include <string>
#include <vector>

Biblioteca::Biblioteca(int id):_idBiblioteca(id){}
Biblioteca::~Biblioteca(){}

// Instala um jogo adquirido.
bool Biblioteca::instalar(Item* jogo){

}
// Remove a instalação sem remover o jogo da biblioteca.
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
// Adiciona um jogo à coleção adquirida.
void Biblioteca::adicionarJogo(Item* jogo){

}
// Registra uma avaliação para um jogo da biblioteca.
void Biblioteca::adicionarAvaliacaoJogo(Item* jogo, Avaliacao* avaliacao){

}