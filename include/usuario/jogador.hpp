#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <vector>
#include "usuario.hpp"
#include "../biblioteca.hpp"
#include "../trofeu.hpp"
#include "../cartao.hpp"
#include "../configuracoes.hpp"
#include "../notificacao.hpp"

class Item; 

/* Subclasse de Usuario focada no consumidor final (jogar, comprar, interagir).
 * Interações no Diagrama:
 * - Herda de Usuario (repassando id, nome, username e senha)[cite: 5].
 * - Possui Biblioteca, Configuracoes, vetores de Trofeu, Cartao, Notificacao e lista de amigos (Jogador*)[cite: 5].
 * - Realiza compras na Loja e faz/recebe Emprestimo[cite: 5].
 */
class Jogador : public Usuario {
private:
    double _saldo;
    std::vector<std::string> _generosFav;
    std::vector<Trofeu> _trofeusConc;
    std::vector<Jogador*> _amigos;
    Biblioteca _biblioteca;
    std::vector<Cartao> _cartoes;
    Configuracoes _config;
    std::vector<Notificacao> _caixaNotif;

public:
    Jogador(int id, std::string nome, std::string username, std::string senha, double saldoInicial = 0.0);
    ~Jogador() override;

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

    double getSaldo() const;
    Biblioteca& getBiblioteca();
    const std::vector<Jogador*>& getAmigos() const;
    const std::vector<Trofeu>& getTrofeus() const;
};

#endif