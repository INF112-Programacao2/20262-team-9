#ifndef TEMA_HPP
#define TEMA_HPP

#include <string>

/* Representa o tema visual e auditivo de personalização do console.
 * Interações no Diagrama:
 * - Composição 1:1 com a classe Usuario (cada usuário possui um Tema).
 */
class Tema {
private:

    int idTema;
    std::string fonte;
    std::string corDetalhe;

public:
    Tema(int id = 1, std::string fonte = "Default", std::string cor = "Azul");
    ~Tema() = default;

    // Altera a fonte de texto da interface visual
    void mudarFonte(const std::string& novaFonte);

    // Altera a cor de destaque da interface gráfica
    void mudarCor(const std::string& novaCor);

    // Atualiza o conjunto de efeitos sonoros de navegação
    void mudarEstSons();

    int getIdTema() const { 
        return idTema;
    }
    std::string getFonte() const {
        return fonte;
    }
    std::string getCorDetalhe() const {
        return corDetalhe;
    }
};

#endif