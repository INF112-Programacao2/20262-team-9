#include "Configuracoes.hpp"

Configuracoes::Configuracoes(bool notificacoesAtivas)
    : _notificacoes(notificacoesAtivas) {}

Configuracoes::~Configuracoes() {}

void Configuracoes::ativarNotif() {
    _notificacoes = true;
}

void Configuracoes::desativarNotif() {
    _notificacoes = false;
}

bool Configuracoes::getNotificacoes() const {
    return _notificacoes;
}