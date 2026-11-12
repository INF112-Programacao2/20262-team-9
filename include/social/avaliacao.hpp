#ifndef AVALIACAO_HPP
#define AVALIACAO_HPP

#include <string>

// Declaração antecipada para evitar inclusão circular
class Jogador;

/* Registra a nota e o comentário atribuídos por um Jogador a um Item.
 * 
 * Interações no Diagrama:
 * - Associação com Jogador (autor da avaliação).
 * - Composição/Agregação 0..* pertencente a um Item.
 */
class Avaliacao {
private:
    int _nota;
    std::string _comentario;
    Jogador* _autor;

public:
    Avaliacao(int nota, std::string comentario, Jogador* autor);
    ~Avaliacao();

    int getNota() const;

    std::string getComentario() const;
    
    Jogador* getAutor() const;
};

#endif