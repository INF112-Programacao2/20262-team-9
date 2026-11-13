#include "../../include/item/jogojogavel.hpp"
#include <string>
#include <vector>

JogoJogavel::JogoJogavel(int id, Desenvolvedor* dev, std::string nome, double armazenamento,
std::string genero, double preco, int faixaEtaria)
:Item(id, dev, nome, armazenamento, genero, preco, faixaEtaria){}

bool JogoJogavel::executar(){

}
