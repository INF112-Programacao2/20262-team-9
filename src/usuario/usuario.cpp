#include <string>
#include "../../include/usuario/usuario.hpp"

Usuario::Usuario(int idUsuario, std::string nome, std::string username, std::string senha):
_idUsuario(idUsuario), _nome(nome), _username(username), _senha(senha){}
Usuario::~Usuario(){}

    // Inicializa as estruturas do perfil no sistema
void Usuario::criarPerfil(){}

    // Atualiza o nome de exibição do usuário
void Usuario::alterarNome(const std::string& novoNome){
    _nome = novoNome;
}

    // Atualiza o identificador único de login (@username)
void Usuario::alterarUsername(const std::string& novoUsername){
    _username = novoUsername;
}

    // Atualiza a senha mediante validação da senha atual
bool Usuario::alterarSenha(const std::string& senhaAtual, const std::string& novaSenha){
    if(_senha == senhaAtual){
        _senha = novaSenha;
        return true;
    }
    else
        return false;
    
}

    // Remove as credenciais e dados do usuário
void Usuario::excluirPerfil(){}

    // Autentica o usuário validando a senha fornecida
bool Usuario::login(const std::string& senhaDigitada){
    if(_senha == senhaDigitada){
        _logado = true;
        return true;
    }
    else
        return false;
}

    // Encerra a sessão ativa do usuário
void Usuario::logout(){
    _logado = false;
}

    // Método virtual de execução padrão para o perfil
void Usuario::jogar(){}

int Usuario::getIdUsuario() const{
    return _idUsuario;
}
std::string Usuario::getNome() const{
    return _nome;
}
std::string Usuario::getUsername() const{
    return _username;
}
bool Usuario::isLogado() const{
    return _logado;
}

    // Retorna referência ao Tema para permitir customização direta
Tema& Usuario::getTema(){
    return _tema;
}
const Tema& Usuario::getTema() const{
    return _tema;
}