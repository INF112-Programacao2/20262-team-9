#include "../../include/social/notificacao.hpp"
#include <string>
#include <vector>

Notificacao::Notificacao(std::string mensagem, std::tm datahora)
:_mensagem(mensagem), _dataHora(datahora){};
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