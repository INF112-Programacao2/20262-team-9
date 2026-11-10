#ifndef JOGOMIDIA_HPP
#define JOGOMIDIA_HPP

#include "item.hpp"

/* Subclasse de Item referente a jogos físicos (disco/cartucho).
 * Interações no Diagrama:
 * - Herda de Item.
 * - Suporta fluxo especial de verificação de inserção de mídia física/empréstimo.
 */
class JogoMidia : public Item {
public:
    JogoMidia(int id, Desenvolvedor* dev, std::string nome, double armazenamento,
              std::string genero, double preco, int faixaEtaria);
    ~JogoMidia() override = default;

    // Sobrescrita polimórfica: valida a presença do disco/mídia física antes de rodar
    bool executar() override;
};

#endif