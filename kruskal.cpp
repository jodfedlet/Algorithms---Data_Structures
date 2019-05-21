

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <string.h> // memset
using namespace std;

class Aresta
{
	int v1, v2, p;

public:

	Aresta(int v1, int v2, int p)
	{
		this->v1 = v1;
		this->v2 = v2;
		this->p = p;
	}

	int getV1()
	{
		return v1;
	}

	int getV2()
	{
		return v2;
	}

	int getP()
	{
		return p;
	}

	// sobrescrita do operador "<"
	bool operator < (const Aresta& aresta2) const
	{
		return (p < aresta2.p);
	}
};

class Grafo
{
	
	int V, soma; // número de vértices
	vector<Aresta> arestas; // vetor de arestas

public:

	Grafo(int V)
	{
		this->V = V;
	}

	// função que adiciona uma aresta
	void Add(int v1, int v2, int p)
	{
		Aresta aresta(v1, v2, p);
		arestas.push_back(aresta);
	}

	// função que busca o subconjunto de um elemento "i"
	int buscar(int subset[], int i)
	{
		if(subset[i] == -1)
			return i;
		return buscar(subset, subset[i]);
	}

	// função para unir dois subconjuntos em um único subconjunto
	void unir(int subset[], int v1, int v2)
	{
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}

	/// função que roda o algoritmo de Kruskal
	void kruskal()
	{
		vector<Aresta> arvore;
		int size_arestas = arestas.size();

		// ordena as arestas pelo menor p
		sort(arestas.begin(), arestas.end());

		// aloca memória para criar "V" subconjuntos
		int * subset = new int[V];

		// inicializa todos os subconjuntos como conjuntos de um único elemento
		memset(subset, -1, sizeof(int) * V);

		for(int i = 0; i < size_arestas; i++)
		{
			int v1 = buscar(subset, arestas[i].getV1());
			int v2 = buscar(subset, arestas[i].getV2());

			if(v1 != v2)
			{
				// se forem diferentes é porque NÃO forma ciclo, insere no vetor
				arvore.push_back(arestas[i]);
				unir(subset, v1, v2); // faz a união
			}
		}

		int size_arvore = arvore.size();

		// mostra as arestas selecionadas com seus respectivos ps
		for(int i = 0; i < size_arvore; i++)
		{
			char v1 = '0' + arvore[i].getV1();
			char v2 = '0' + arvore[i].getV2();
			cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].getP() << endl;
			soma+=arvore[i].getP();
		}
		cout<<"O custo e:" <<soma<<endl;
	}
};

int main(int argc, char *argv[])
{
	Grafo TpG(8); // grafo
	
	// adiciona as arestas
	TpG.Add(0, 1, 2);
	TpG.Add(0, 3, 6);
	TpG.Add(0, 4, 5);
	TpG.Add(1, 2, 7);
	TpG.Add(1, 3, 7);
	TpG.Add(2, 4, 6);
	TpG.Add(2, 5, 2);
	
	TpG.Add(4, 6, 4);
	TpG.Add(4, 7, 5);
	TpG.Add(5, 6, 4);
	TpG.Add(5, 7, 6);
	TpG.Add(6, 7, 1);
	
	TpG.kruskal(); // roda o algoritmo de Kruskal
	

	return 0;
}