#ifndef PEDIDOAMIZADE_H
#define PEDIDOAMIZADE_H

#include <string>
#include "notificacao.hpp"

class Jogador;

class PedidoAmizade : public Notificacao{
    private:
    Jogador* _rementente;
    Jogador* _destinatario;

    public:
    PedidoAmizade(Jogador* rementente , Jogador* destinatario);
    ~PedidoAmizade();

    Jogador* getRemetente();
    Jogador* getDestinatario();
};

#endif;