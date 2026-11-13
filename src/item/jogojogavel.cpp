#include "../../include/item/jogojogavel.hpp"
#include <string>
#include <vector>

// Inicializa o jogo digital com os dados comuns de Item.
JogoJogavel::JogoJogavel(int id, Desenvolvedor* dev, std::string nome, double armazenamento,
std::string genero, double preco, int faixaEtaria)
:Item(id, dev, nome, armazenamento, genero, preco, faixaEtaria){}

// Executa o jogo digital instalado.
bool JogoJogavel::executar(){

}
