/*
* PROBLEMA DO CORTE MÁXIMO
* Implementação de solução por Lucas Cafieiro Bittencourt Lima para a
* disciplina de Análise e Projeto de Algoritmos da Universidade Federal da
* Paraíba.
*
* Instâncias utilizadas disponíveis em: http://www.optsicom.es/maxcut/
*/

#include <fstream>
#include "../Graph/Graph.hpp"
#include "../Heuristic/MaxCut.hpp"

int main() {
    int vertices;
    int edges;
    int e_start;
    int e_end;
    int v_weight;
    std::ifstream file;

    Graph* graph;

    // Leitura das instâncias.
    file.open("Instances/g1.rud");
    if (file.is_open()) {
        file >> vertices >> edges;
        graph = new Graph(vertices, edges);
        // Criação de vértices e arestas.
        for (int i = 0; i < edges; i++) {
            file >> e_start >> e_end >> v_weight;
            graph->addEdge(e_start, e_end, v_weight);
        }
        file.close();
    }
    else
        std::cout << "ERROR: Unable to open file" << std::endl;

    // Criação do grafo.
    graph->buildGraph();

    MaxCut solver;
    int cut = solver.MultiStart(graph->getList(), graph->getEdges(), 100);
    std::cout << "Melhor corte encontrado: " << cut << std::endl;

    return 0;
}
