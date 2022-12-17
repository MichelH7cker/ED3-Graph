#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include "main.hpp"

typedef struct edge {
    int velocidade;
    int idPoPsConectado;
    int capacity;
} edge;

typedef struct vertex {
    int idConecta;
    string nomePoPs;
    string nomePais;
    string siglaPais;

    int parent;

    forward_list<edge> edges;
} vertex;

/**
 * @brief 'overload' do comparador "<" 
 * 
 * @param x struct edge a ser comparada com struct edge y
 * @param y struct edge a ser comparada com struct edge x
 * @return true se uma x é menor que y
 * @return false se y é menor que x
 */
bool my_compare (const edge x,const edge y);

/**
 * @brief 
 * 
 */
class Graph {
    private: 
        map<int, vertex> vertices;
        map<int, vertex>::iterator it;        
        forward_list<edge>::iterator itl;
        

        int numberOfVertices;
        int numberOfEdges;
        
    public:
        /**
         * @brief Create a Graph object
         * 
         * @param db_file arquivo database
         */
        void createGraph(char *db_file);

        /**
         * @brief função que percorre todo o map vertices, ordenando suas listas encadeadas
         * 
         */
        void sortList();

        /**
         * @brief função utilizada para debug. serve para mostrar no terminal todas as informações de um vértice inteiro
         * 
         * @param vertex struct vertex a ser mostrada no terminal
         */
        void printVertex(vertex vertex);
        
        /**
         * @brief Create a Vertex object
         * 
         * @param reg_db 
         * @return vertex 
         */
        vertex createVertex(const register_db &reg_db);
      
        /**
         * @brief Create a Edge object
         * 
         * @param reg_db 
         * @return edge 
         */
        edge createEdge(const register_db &reg_db);
        
        /**
         * @brief atualiza a aresta para ser inserida na posição idPoPsConectado, e não mais na posição idConecta
         * 
         * @param reg_db 
         * @return edge 
         */
        edge updateEdgeToIdPoPs(register_db reg_db);

        /**
         * @brief conta quantos ciclos há no grafo, prepara as variáveis para a função de contagem em si
         */
        void count_cycles();
        
        /**
         * @brief faz a contagem de todos os ciclos presentes no grafo
         * 
         * @param v_current id do vértice atual
         * @param v_parent id da aresta analisada
         * @param color vetor com a cor de cada vértice
         * @param par vetor com os pais
         * @param cycles quantidade de ciclos
        */
        void DFS_cycle(int v_current, int v_parent, int *color, int *par, int &cycles);

        /**
         * @brief
         * 
         * @param
         * @param
         * @param
         * 
         * @return
         * 
        */
        int bfs (vertex origin, int destiny);

        /**
         * @brief
         * 
         * @param
         * @param
        */
        void edmond_karp(int origin, int detiny);

        /**
         * 
        */
        void flow_max();

        /**
         * @brief mostra o grafo no terminal
         * 
         */
        void printGraph();

};

#endif