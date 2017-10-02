//
// Created by Ludovic Delisle on 10/2/17.
//
#include <vector>
#include <cmath>
#ifndef NEURONS_NEURON_H
#define NEURONS_NEURON_H

using namespace std;

class Neuron {

public:
    void update(int input, double h, double simtime);
    double get_potential()const;
    int get_spikes()const;
    //vector get_time_of_spikes()const;
    void add_spike();
    void add_time_of_spike(double t);
    bool get_refractory()const;
    double new_potential_calcul(int input, double h);
private:
    bool refractory=false;
    double potential_V=-70;
    int spikes = 0;
    vector <int> time_of_spikes;
    double tao = 0.02;
    int R=1000000;
};


#endif //NEURONS_NEURON_H
