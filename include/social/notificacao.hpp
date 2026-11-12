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
    std::string _mensagem;
    std::tm _dataHora;
    bool _lida;

public:
    Notificacao(std::string mensagem, std::tm dataHora);
    ~Notificacao();

    // Altera o estado da notificação para visualizada
    void marcarComoLida();

    std::string getMensagem() const;

    bool isLida() const;
};

#endif