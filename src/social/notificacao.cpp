#include "../../include/social/notificacao.hpp"
#include <string>
#include <vector>

Notificacao::Notificacao(std::string mensagem, std::tm datahora)
:_mensagem(mensagem), _dataHora(datahora){};
Notificacao::~Notificacao(){};

void Notificacao::marcarComoLida(){

}
std::string Notificacao::getMensagem()const {

}
bool Notificacao::isLida()const{
   
}