#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include "tema.hpp"

/* Classe base abstrata que representa qualquer conta cadastrada no console.
 * Interações no Diagrama:
 * - Classe pai (Herança) de Jogador e Desenvolvedor.
 * - Possui 1 objeto Tema via composição.
 */
class Usuario {
protected:

    int idUsuario;
    std::string nome;
    Tema tema;

public:
    Usuario(int id, std::string nome);
    virtual ~Usuario() = default;

    // Inicializa as estruturas do perfil no sistema
    void criarPerfil();

    // Atualiza os dados cadastrais (ex: alterar nome de exibição)
    void editarPerfil(const std::string& novoNome);

    // Remove as credenciais e dados do usuário
    void excluirPerfil();

    // Autentica o usuário na plataforma
    bool login();

    // Encerra a sessão ativa do usuário
    void logout();

    // Método virtual de execução padrão para o perfil
    virtual void jogar();

    int getIdUsuario() const {
        return idUsuario;
    }
    std::string getNome() const {
        return nome;
    }
    Tema getTema() const {
        return tema;
    }
};

#endif
