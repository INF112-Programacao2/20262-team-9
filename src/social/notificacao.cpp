#include "../../include/social/notificacao.hpp"
#include <string>
#include <ctime>
#include <vector>

Notificacao::Notificacao(std::string mensagem):
    _mensagem(mensagem) { 
    std::time_t tempo = std::time(NULL);
    _dataHora = *std::localtime(&tempo);
    _lida = false;
};
Notificacao::~Notificacao(){};

// Marca a notificação como lida.
void Notificacao::marcarComoLida(){
    _lida = true;
}

// Retorna o texto da notificação.
std::string Notificacao::getMensagem()const {
    return _mensagem;
}

// Informa se a notificação já foi lida.
bool Notificacao::isLida()const{
   return _lida;
}