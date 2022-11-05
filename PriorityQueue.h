#pragma once
#pragma once
class PriorityQueue
{
private:
	int* niz;
	int kapacitet;
	int broj_elemenata;
	int f, r;//front-rear
public:
	PriorityQueue(int kapacitet = 1);
	~PriorityQueue();
	int PunRed(PriorityQueue* queue);
	int PrazanRed(PriorityQueue* queue);
	void enqueue(PriorityQueue* queue, int value);
	bool Obrisi_Najveci(PriorityQueue* queue);
	bool Obrisi_Na_Poziciji(int index);
	void ispis(PriorityQueue* red);
	bool shouldShrink();
};