#ifndef CONFIGURACOES_HPP
#define CONFIGURACOES_HPP

/* Gerencia as preferências de sistema do perfil (ex: exibição de alertas).
 * Interações no Diagrama:
 * - Composição 1:1 mantida dentro da classe Jogador.
 */
class Configuracoes {
private:
    bool notificacoes;

public:
    Configuracoes(bool notificacoesAtivas = true);
    ~Configuracoes() = default;

    // Habilita a exibição de pop-ups e alertas no console
    void ativarNotif();

    // Silencia os alertas durante o uso
    void desativarNotif();

    bool getNotificacoes() const {
        return notificacoes;
    }
};

#endif