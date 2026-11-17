#ifndef PEDIDOAMIZADE_H
#define PEDIDOAMIZADE_H

#include <string>
#include "notificacao.hpp"

class Jogador;

class PedidoAmizade : Notificacao{
    private:
    Jogador* _rementente;
    Jogador* _destinatario;

    public:
    PedidoAmizade(std::string mensagem, Jogador* rementente , Jogador* destinatario);
    ~PedidoAmizade();

    Jogador* get_remetente();
    Jogador* get_destinatario();
};

#endif;