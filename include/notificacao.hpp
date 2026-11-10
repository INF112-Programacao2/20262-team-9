#ifndef NOTIFICACAO_HPP
#define NOTIFICACAO_HPP

#include <string>
#include <ctime>

/* Armazena mensagens do sistema, convites de amizade e conquistas.
 * Interações no Diagrama:
 * - Associação 0..* com a caixa de notificações do Jogador.
 */
class Notificacao {
private:
    std::string mensagem;
    std::tm dataHora;
    bool lida;

public:
    Notificacao(std::string mensagem, std::tm dataHora);
    ~Notificacao() = default;

    // Altera o estado da notificação para visualizada
    void marcarComoLida();

    std::string getMensagem() const {
        return mensagem; }

    bool isLida() const {
        return lida; }
};

#endif