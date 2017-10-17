//
// Created by Ludovic Delisle on 10/9/17.
//
#include <vector>
#include "Neuron.h"
#ifndef NEURONS_NETWORK_H
#define NEURONS_NETWORK_H


class Network {
public:
    Network();
    void add_a_neuron(Neuron* n);
    void kill_a_neuron(Neuron* n);
    void add_time_of_spike(double t);
    vector<double> get_time_of_spike()const;
    void update(double input, double h, double simtime);
    void afficher_spikes_per_cycle();
private:

    vector<Neuron*> list_neurons;
    vector<double> time_of_spikes;
    vector<int> number_of_spike_per_cycle;
};


#endif //NEURONS_NETWORK_H
