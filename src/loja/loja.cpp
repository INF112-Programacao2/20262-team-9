#include "../../include/loja/loja.hpp"
#include <string>
#include <vector>

Loja::Loja(int id): _idLoja(id){}
Loja::~Loja(){}

void Loja::listarJogos() const{

}
std::vector<Item*> Loja::filtrarGenero(const std::string& genero) const{

}
Item* Loja::buscarJogo(const std::string& nome) const{

}
std::vector<Item*> Loja::recomendar(const Jogador* Jogador) const{

}
void Loja::adicionarAoCatalogo(Item* jogo){

}
const std::vector<Item*>& Loja::getCatalogo() const{
    return _catalogo;
}