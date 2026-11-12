#include "../../include/usuario/desenvolvedor.hpp"
#include <string>
#include <vector>

Desenvolvedor::Desenvolvedor(int id, std::string nome, std::string username, std::string senha)
: Usuario(id,nome,username,senha){}
Desenvolvedor::~Desenvolvedor(){}

// Publica um novo jogo para o sistema
void Desenvolvedor::publicarJogo(Item* jogo){}

// Remove um jogo adicionado do sistema
void Desenvolvedor::removerJogo(Item* jogo){}


const std::vector<Item*>& Desenvolvedor::getJogosPublicados() const {
    return _jogosPublicados;
}
