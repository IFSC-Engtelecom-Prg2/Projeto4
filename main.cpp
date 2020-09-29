#include <iostream>
#include <fstream>
#include <string>
#include <prglib.h>
#include <Diretorio.h>

using namespace std;
using namespace prglib;

int main(int argc, char * argv[]) {
    fila<string> q(1024);

    // usa um algoritmo do tipo busca em largura
    // para listar recursivamente um diretório
    // Tal algoritmo usa uma fila ...

    q.enfileira(argv[1]);
    while (! q.vazia()) {
        // desenfileira próximo subdiretório a ser listado
        auto path = q.desenfileira();

        Diretorio dir(path);

        // lista um subdiretório
        dir.inicia_listagem();
        while (! dir.fim_listagem()) {
            Entrada item = dir.proximo();
            // se item dentro do subdiretório for . ou .. ignora
            if (item.nome == "." || item.nome == "..") continue;

            string subpath = path + '/' + item.nome;
            // se item for um subdiretório, deve ser enfileirado
            if (item.tipo == Tipo::Diretorio) {
                q.enfileira(subpath);
            }

            cout << subpath << endl;
        }
    }
}