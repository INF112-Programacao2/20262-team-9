#include <memory>
#include <string>
#include "../../include/social/pedidoAmizade.hpp"

PedidoAmizade::PedidoAmizade(std::string mensagem, Jogador* remetente , Jogador* destinatario) :
 Notificacao(mensagem), _rementente(remetente), _destinatario(destinatario){}

PedidoAmizade::~PedidoAmizade(){}

Jogador* PedidoAmizade::get_remetente(){
    return _rementente;
}
Jogador* PedidoAmizade::get_destinatario(){
    return _destinatario;
}