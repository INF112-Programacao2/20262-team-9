#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <vector>
#include "Usuario.hpp"
#include "Biblioteca.hpp"
#include "Trofeu.hpp"
#include "Cartao.hpp"
#include "Configuracoes.hpp"
#include "Notificacao.hpp"

class Item; 

/* Subclasse de Usuario focada no consumidor final (jogar, comprar, interagir).
 * Interações no Diagrama:
 * - Herda de Usuario (repassando id, nome, username e senha)[cite: 5].
 * - Possui Biblioteca, Configuracoes, vetores de Trofeu, Cartao, Notificacao e lista de amigos (Jogador*)[cite: 5].
 * - Realiza compras na Loja e faz/recebe Emprestimo[cite: 5].
 */
class Jogador : public Usuario {
private:
    double saldo;
    std::vector<std::string> generosFav;
    std::vector<Trofeu> trofeusConc;
    std::vector<Jogador*> amigos;
    Biblioteca biblioteca;
    std::vector<Cartao> cartoes;
    Configuracoes config;
    std::vector<Notificacao> caixaNotif;

public:
    Jogador(int id, std::string nome, std::string username, std::string senha, double saldoInicial = 0.0);
    ~Jogador() override = default;

    // Associa um novo cartão de crédito à conta
    void addCartao(const Cartao& cartao);

    // Descadastra um cartão a partir de seu número
    void removerCartao(const std::string& numero);

    // Incrementa a carteira digital com créditos em R$
    void addSaldo(double valor);

    // Registra gêneros de preferência para motor de recomendação
    void addGeneroFav(const std::string& genero);

    // Escreve uma avaliação para um jogo que possui
    void avaliarJogo(Item* jogo, int nota, const std::string& comentario);

    // Processa a compra de um item da Loja, debitando saldo e adicionando à Biblioteca
    bool comprarJogo(Item* jogo);

    // Adiciona um troféu conquistado à coleção do perfil
    void conqTrofeu(const Trofeu& trofeu);

    // Envia solicitação de amizade a outro Jogador
    void solicitarAmizade(Jogador* amigo);

    // Rejeita pedido de amizade pendente
    void negarAmizade(Jogador* amigo);

    // Adiciona o jogador solicitante à lista de amigos
    void aceitarAmizade(Jogador* amigo);

    // Exibe a lista de conquistas obtidas
    void listarTrofeu() const;

    // Recebe e adiciona uma notificação na caixa de entrada
    void receberNotif(const Notificacao& notif);

    double getSaldo() const { return saldo; }
    Biblioteca& getBiblioteca() { return biblioteca; }
    const std::vector<Jogador*>& getAmigos() const { return amigos; }
    const std::vector<Trofeu>& getTrofeus() const { return trofeusConc; }
};

#endif