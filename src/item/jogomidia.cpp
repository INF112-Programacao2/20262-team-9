#include "../../include/item/jogomidia.hpp"
#include <string>
#include <vector>

JogoMidia::JogoMidia(int id, Desenvolvedor* dev, std::string nome, double armazenamento,
std::string genero, double preco, int faixaEtaria)
:Item(id, dev, nome, armazenamento, genero, preco, faixaEtaria){}

bool JogoMidia::executar(){}