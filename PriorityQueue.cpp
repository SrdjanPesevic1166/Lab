#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue(int kapacitet)
{
	this->niz = new int[kapacitet];
	this->kapacitet = kapacitet;
	this->broj_elemenata = 0;

	this->f = -1;
	this->r = 0;

}
PriorityQueue::~PriorityQueue()
{
	delete[] this->niz;
	this->niz = nullptr;
	this->broj_elemenata = 0;
	this->kapacitet = 0;
}

int PriorityQueue::PunRed(PriorityQueue* queue)
{
	return queue->r == queue->kapacitet;
}

int PriorityQueue::PrazanRed(PriorityQueue* queue)
{
	return queue->f == -1 || queue->f == queue->r;
}

void PriorityQueue::enqueue(PriorityQueue* queue, int value)
{
	//Provjera punog reda
	if (PunRed(queue))
	{
		int* Novi_Niz = new int[this->kapacitet * 2];
		this->kapacitet *= 2;
		for (int i = 0; i < this->broj_elemenata; i++)
		{
			Novi_Niz[i] = this->niz[i];
		}
		delete[] this->niz;
		this->niz = Novi_Niz;
	}
	if (queue->f == -1) 
	{
		queue->f = 0;
		queue->niz[queue->r++] = value;
		queue->broj_elemenata++;
	}
	else
	{
		int i= this->broj_elemenata - 1;
		while (value > this->niz[i] && i >= 0)
		{
			niz[i + 1] = niz[i];
			i--;
		}
		queue->niz[i + 1] = value;	
		queue->r++;
		queue->broj_elemenata++;
	}
}

bool PriorityQueue::Obrisi_Najveci(PriorityQueue* queue)
{

	if (PrazanRed(queue))
		return false;
	for (int i = this->f+1; i < this->r; i++)
	{
		this->niz[i - 1] = this->niz[i];
	}
	this->broj_elemenata--;
	this->r--;

	return true;
}

bool PriorityQueue::Obrisi_Na_Poziciji(int index)
{

	if (index<0 || index>=this->broj_elemenata)
		return false;
	for (int i = index; i < this->broj_elemenata-1; i++)
	{
		this->niz[i] = this->niz[i + 1];
	}
	this->broj_elemenata--;
	this->r--;
	if (this->shouldShrink())
	{

		int* Novi_Niz1 = new int[this->broj_elemenata]();
		this->kapacitet = this->broj_elemenata;
		this->broj_elemenata = this->kapacitet > this->broj_elemenata ? this->broj_elemenata : this->kapacitet;
		for (int i = 0; i < this->broj_elemenata; i++)
		{
			Novi_Niz1[i] = this->niz[i];
		}
		delete[]this->niz;
		this->niz = Novi_Niz1;

	}
	
}

bool PriorityQueue::shouldShrink()
{
	return this->broj_elemenata <= this->kapacitet / 2;
}
void PriorityQueue::ispis(PriorityQueue* red)
{
	for (int i = this->f; i <this->r; i++)
	{
		std::cout << this->niz[i] << " ";
	}


}
