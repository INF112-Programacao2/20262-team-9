#include "../../include/item/item.hpp"
#include <string>
#include <vector>

// Inicializa os dados do item e define seu estado inicial de empréstimo.
Item::Item(int id, Desenvolvedor* dev, std::string nome, double armazenamento,
std::string genero, double preco, int faixaEtaria)
:idItem(id), dev(dev), nome(nome), armazenamento(armazenamento), genero(genero),
preco(preco), faixaEtaria(faixaEtaria), emprestado(false){}
Item::~Item(){}

// Exibe as avaliações associadas ao item.
void Item::mostrarAvaliacao() const{

}

// Adiciona uma avaliação ao item.
void Item::adicionarAvaliacao(Avaliacao* av){

}

// Calcula a média das avaliações do item.
double Item::calcularMedia()const {

}