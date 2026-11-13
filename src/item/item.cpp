#include "../../include/item/item.hpp"
#include <string>
#include <vector>

Item::Item(int id, Desenvolvedor* dev, std::string nome, double armazenamento,
std::string genero, double preco, int faixaEtaria)
:idItem(id), dev(dev), nome(nome), armazenamento(armazenamento), genero(genero),
preco(preco), faixaEtaria(faixaEtaria), emprestado(false){}
Item::~Item(){}

void Item::mostrarAvaliacao() const{

}
void Item::adicionarAvaliacao(Avaliacao* av){

}
double Item::calcularMedia()const {

}