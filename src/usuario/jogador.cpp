#include <string>
#include <vector>
#include "../../include/usuario/jogador.hpp"
#include "../../include/loja/cartao.hpp"
#include "../../include/social/avaliacao.hpp"
#include "../../include/social/notificacao.hpp"
#include "../../include/social/pedidoAmizade.hpp"

    Jogador::Jogador(int id, std::string nome, std::string username, std::string senha, double saldoInicial = 0.0):
    Usuario(id, nome, username, senha), _saldo(saldoInicial){}
    Jogador::~Jogador(){}

    // Associa um novo cartão de crédito à conta
    void Jogador::addCartao(const Cartao& cartao){
        _cartoes[_cartoes.size()] = cartao;
    }

    // Descadastra um cartão a partir de seu número
    void Jogador::removerCartao(const std::string& numero){
        for(int i=0; i < _cartoes.size(); i++)
            if(_cartoes[i].getNumero() == numero)
                _cartoes.erase(_cartoes.begin() + i);
    }

    // Incrementa a carteira digital com créditos em R$
    void Jogador::addSaldo(double valor){
        _saldo += valor;
    }

    // Registra gêneros de preferência para motor de recomendação
    void Jogador::addGeneroFav(const std::string& genero){
        _generosFav.push_back(genero);
    }

    // Escreve uma avaliação para um jogo que possui
    Avaliacao Jogador::avaliarJogo(int nota, const std::string& comentario){
        Avaliacao avaliacao(nota, comentario, this);
        return avaliacao;
    }

    // Processa a compra de um item da Loja, debitando saldo e adicionando à Biblioteca
    bool Jogador::comprarJogo(Item* jogo){
        if(_saldo - jogo->getPreco() >= 0){
            _saldo -= jogo->getPreco();
            _biblioteca.adicionarJogo(jogo);
            return true;
        }
        else
            return false;
    }

    // Adiciona um troféu conquistado à coleção do perfil
    void Jogador::conqTrofeu(const Trofeu& trofeu){
        _trofeusConc.push_back(trofeu);
    }

    // Envia solicitação de amizade a outro Jogador
    void Jogador::solicitarAmizade(Jogador* amigo){
        PedidoAmizade pedido(this, amigo);
        amigo->receberPedido(pedido);
    }

    // Rejeita pedido de amizade pendente
    void Jogador::negarAmizade(PedidoAmizade* pedido){
        for(int i = 0; i < size(_pedidosAmizade); i++)
            if(_pedidosAmizade[i].getRemetente() == pedido->getRemetente() 
            && _pedidosAmizade[i].getDestinatario() == pedido->getDestinatario())
                _pedidosAmizade.erase(_pedidosAmizade.begin() + i);
    }

    // Adiciona o jogador solicitante à lista de amigos
    void Jogador::aceitarAmizade(PedidoAmizade* pedido){
        for(int i = 0; i < size(_pedidosAmizade); i++)

            if(_pedidosAmizade[i].getRemetente() == pedido->getRemetente() 
               && _pedidosAmizade[i].getDestinatario() == pedido->getDestinatario()){

                pedido->getRemetente()->addAmigo(pedido->getDestinatario());
                pedido->getDestinatario()->addAmigo(pedido->getRemetente());

                _pedidosAmizade.erase(_pedidosAmizade.begin() + i);
            }
    }

    // Exibe a lista de conquistas obtidas
    void Jogador::listarTrofeu() const{}

    // Recebe e adiciona uma notificação na caixa de entrada
    void Jogador::receberNotif(const Notificacao& notif){
        _caixaNotif.push_back(notif);
    }

    void Jogador::receberPedido(const PedidoAmizade& pedido){
        _pedidosAmizade.push_back(pedido);
    }

    void Jogador::addAmigo(Jogador* amigo){
        _amigos.push_back(amigo);
    }

    double Jogador::getSaldo() const { 
        return _saldo; 
    }
    Biblioteca& Jogador::getBiblioteca(){ 
        return _biblioteca; 
    }
    const std::vector<Jogador*>& Jogador::getAmigos() const{ 
        return _amigos; 
    }
    const std::vector<Trofeu>& Jogador::getTrofeus() const{ 
        return _trofeusConc; 
    }