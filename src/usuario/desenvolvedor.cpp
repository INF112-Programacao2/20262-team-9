#include "../../include/usuario/desenvolvedor.hpp"
#include <string>
#include <vector>
#include <stdexcept>

Desenvolvedor::Desenvolvedor(int id, std::string nome, std::string username, std::string senha)
: Usuario(id,nome,username,senha){}
Desenvolvedor::~Desenvolvedor(){}

// Publica um novo jogo para o catalogo da Loja
void Desenvolvedor::publicarJogo(Item* jogo){
    if(jogo == nullptr)
        throw std::invalid_argument("O jogo nao pode estar vazio");
    for(Item* publicado : _jogosPublicados){
        if(publicado == jogo)
        return; //ja esta na lista
    }
    _jogosPublicados.push_back(jogo);
}

// Remove um jogo adicionado ao catalogo da Loja
void Desenvolvedor::removerJogo(Item* jogo){
    if(jogo == nullptr)
        throw std::invalid_argument("O jogo nao pode estar vazio");
    
}

const std::vector<Item*>& Desenvolvedor::getJogosPublicados() const {
    return _jogosPublicados;
}
