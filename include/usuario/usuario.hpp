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
    std::string username;
    bool logado;
    Tema tema;

public:
    Usuario(int idUsuario, std::string nome, std::string username, std::string senha);
    virtual ~Usuario() = default;

    // Inicializa as estruturas do perfil no sistema
    void criarPerfil();

    // Atualiza o nome de exibição do usuário
    void editarPerfil(const std::string& novoNome);

    // Atualiza o identificador único de login (@username)
    void alterarUsername(const std::string& novoUsername);

    // Atualiza a senha mediante validação da senha atual
    bool alterarSenha(const std::string& senhaAtual, const std::string& novaSenha);

    // Remove as credenciais e dados do usuário
    void excluirPerfil();

    // Autentica o usuário validando a senha fornecida
    bool login(const std::string& senhaDigitada);

    // Encerra a sessão ativa do usuário
    void logout();

    // Método virtual de execução padrão para o perfil
    virtual void jogar();

    int getIdUsuario() const { return idUsuario; }
    std::string getNome() const { return nome; }
    std::string getUsername() const { return username; }
    bool isLogado() const { return logado; }

    // Retorna referência ao Tema para permitir customização direta
    Tema& getTema() { return tema; }
    const Tema& getTema() const { return tema; }
};

#endif