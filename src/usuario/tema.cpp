#include "Tema.hpp"

Tema::Tema(int id, std::string fonte, std::string cor, std::string SonsAtivos)
    : _idTema(id), _fonte(fonte), _corDetalhe(cor), _SonsAtivos(SonsAtivos) {}

void Tema::mudarFonte(const std::string& novaFonte) {
    if (!novaFonte.empty()) {
        _fonte = novaFonte;
    }
}

void Tema::mudarCor(const std::string& novaCor) {
    if (!novaCor.empty()) {
        _corDetalhe = novaCor;
    }
}

void Tema::mudarEstSons(const std::string& novoEstilo) {
    if (!novoEstilo.empty()) {
        _SonsAtivos = novoEstilo;
    }
}

int Tema::getIdTema() const {
    return _idTema;
}

std::string Tema::getFonte() const {
    return _fonte;
}

std::string Tema::getCorDetalhe() const {
    return _corDetalhe;
}

std::string Tema::getSonsAtivos() const {
    return _SonsAtivos;
}