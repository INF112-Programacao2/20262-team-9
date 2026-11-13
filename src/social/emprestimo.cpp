#include "../../include/social/emprestimo.hpp"
#include <string>
#include <vector>

Emprestimo::Emprestimo(Item* jogo, Jogador* dono, Jogador* receptor, std::tm inicio, std::tm fim)
:_jogoEmprestado(jogo), _donojogador(dono), _receptor(receptor), _dataInicio(inicio), _dataFim(fim){}
Emprestimo::~Emprestimo(){}

bool Emprestimo::emprestar(){

}
bool Emprestimo::devolver(){

}
Item* Emprestimo::getJogoEmprestado()const{
    return _jogoEmprestado;
}
Jogador* Emprestimo::getDono()const{
    return _donojogador;
}
Jogador* Emprestimo::getReceptor()const{
    return _receptor;
}