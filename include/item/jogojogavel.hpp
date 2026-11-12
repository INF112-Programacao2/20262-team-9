#ifndef JOGOJOGAVEL_HPP
#define JOGOJOGAVEL_HPP

#include "item.hpp"

/* Subclasse de Item referente a jogos em formato digital executáveis direto do SSD.
 * Interações no Diagrama:
 * - Herda de Item.
 * - Instanciado na Biblioteca e vendido na Loja.
 */
class JogoJogavel : public Item {
public:
    JogoJogavel(int id, Desenvolvedor* dev, std::string nome, double armazenamento,
                std::string genero, double preco, int faixaEtaria);
    ~JogoJogavel() override = default;

    // Sobrescrita polimórfica: carrega o executável digital do jogo
    bool executar() override;
};

#endif