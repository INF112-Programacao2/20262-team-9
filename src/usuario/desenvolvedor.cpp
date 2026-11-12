#include "../../include/usuario/desenvolvedor.hpp"
#include <string>
#include <vector>

Desenvolvedor::Desenvolvedor(int id, std::string nome, std::string username, std::string senha)
: Usuario(id,nome,username,senha){}
Desenvolvedor::~Desenvolvedor(){}

void Desenvolvedor::publicarJogo(Item* jogo){}

