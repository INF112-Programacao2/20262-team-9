#include "../../include/loja/loja.hpp"
#include <string>
#include <vector>

Loja::Loja(int id): _idLoja(id){}
Loja::~Loja(){}

// Lista os itens disponíveis no catálogo.
void Loja::listarJogos() const{

}
// Retorna os itens que correspondem ao gênero informado.
std::vector<Item*> Loja::filtrarGenero(const std::string& genero) const{

}
// Busca um item pelo nome.
Item* Loja::buscarJogo(const std::string& nome) const{

}
// Recomenda itens ao jogador.
std::vector<Item*> Loja::recomendar(const Jogador* Jogador) const{

}
// Adiciona um item ao catálogo.
void Loja::adicionarAoCatalogo(Item* jogo){

}
const std::vector<Item*>& Loja::getCatalogo() const{
    return _catalogo;
}