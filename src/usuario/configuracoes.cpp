#include "../../include/usuario/configuracoes.hpp"

Configuracoes::Configuracoes(){ 
    _notificacoes = true;
}

Configuracoes::~Configuracoes(){}

void Configuracoes::ativarNotif() {
    _notificacoes = true;
}

void Configuracoes::desativarNotif() {
    _notificacoes = false;
}

bool Configuracoes::getNotificacoes() const {
    return _notificacoes;
}