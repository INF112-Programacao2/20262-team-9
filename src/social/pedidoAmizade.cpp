#include <memory>
#include <string>
#include "../../include/social/pedidoAmizade.hpp"
#include "../../include/usuario/jogador.hpp"

PedidoAmizade::PedidoAmizade(Jogador* remetente , Jogador* destinatario) :
    Notificacao("Voce recebeu um pedido de amizade de " + remetente->getNome()),
    _rementente(remetente), _destinatario(destinatario){}

PedidoAmizade::~PedidoAmizade(){}

Jogador* PedidoAmizade::getRemetente(){
    return _rementente;
}
Jogador* PedidoAmizade::getDestinatario(){
    return _destinatario;
}