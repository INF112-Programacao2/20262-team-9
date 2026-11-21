cmake_minimum_required(VERSION 3.16)
project(simuladorConsole)

# Obrigatorio para a SFML 3.1.0 funcionar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Garante que o .exe e as .dll fiquem juntos na raiz de build/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Integra o IntelliSense do VS Code com as pastas de include
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Aponta para a pasta local da SFML no Windows
if(WIN32)
    # No Windows, aponta para a pasta local libs/SFML/lib/cmake/SFML
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/SFML/lib/cmake/SFML")
    find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)
else()
    # No Linux/WSL, baixa e compila a SFML 3.1.0 automaticamente
    include(FetchContent)
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0
        GIT_SHALLOW ON
    )
    FetchContent_MakeAvailable(SFML)
endif()

add_executable (executavel main.cpp 
#[[
#arquivos /item
src/item/item.cpp
src/item/jogojogavel.cpp
src/item/jogomidia.cpp
#arquivos /loja
src/loja/biblioteca.cpp
src/loja/cartao.cpp
src/loja/loja.cpp
#arquivos /social
src/social/avaliacao.cpp
src/social/emprestimo.cpp
src/social/notificacao.cpp
src/social/pedidoAmizade.cpp
src/social/trofeu.cpp
#arquivos /usuario
src/usuario/configuracoes.cpp
src/usuario/desenvolvedor.cpp
src/usuario/jogador.cpp
src/usuario/tema.cpp
src/usuario/usuario.cpp
]]
)

#da pra suar #include sem precisar do caminho completo
target_include_directories(executavel PUBLIC include/item
include/loja
include/social
include/usuario
)

# Vincula a SFML ao executavel
target_link_libraries(executavel PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

# Configuracoes especificas para Windows (DLLs da SFML e runtime do MinGW)
if(WIN32)
    file(GLOB SFML_DLLS "${CMAKE_SOURCE_DIR}/libs/SFML/bin/*.dll")
    file(COPY ${SFML_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    target_link_options(executavel PRIVATE -static-libgcc -static-libstdc++)
endif()

#avisa sobre variaveis n utilizadas, comparacoes ambiguas e bugs
if(MSVC)
    target_compile_options(executavel PRIVATE /W4)
else()
    target_compile_options(executavel PRIVATE -Wall -Wextra)
endif()