#include "../../include/social/emprestimo.hpp"
#include <string>
#include <vector>

Emprestimo::Emprestimo(Item* jogo, Jogador* dono, Jogador* receptor, std::tm inicio, std::tm fim)
:_jogoEmprestado(jogo), _donojogador(dono), _receptor(receptor), _dataInicio(inicio), _dataFim(fim){}
Emprestimo::~Emprestimo(){}
// Inicia o empréstimo do jogo para o jogador receptor.
bool Emprestimo::emprestar(){

}
// Finaliza o empréstimo e devolve o jogo ao proprietário.
bool Emprestimo::devolver(){
    
}
// Retorna o jogo associado ao empréstimo.
Item* Emprestimo::getJogoEmprestado()const{
    return _jogoEmprestado;
}
// Retorna o proprietário original do jogo.
Jogador* Emprestimo::getDono()const{
    return _donojogador;
}
// Retorna o jogador que recebeu o empréstimo.
Jogador* Emprestimo::getReceptor()const{
    return _receptor;
}