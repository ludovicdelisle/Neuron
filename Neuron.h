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
    bool update(int input, double h);
    double get_potential()const;
    void add_time_of_spike(double t);
    bool get_refractory()const;
    double new_potential_calcul(int input, double h);
    vector <Neuron*> get_leaving_links();
    void charge_J(double input);
    void set_buffer(int b);
private:
    bool refractory=false;
    double potential_V=0;
    double tao = 0.02;
    double R=25.2;
    vector <Neuron*> leaving_links;
    vector <Neuron*> entering_links;
    double J=0;
    int buffer=0;
};


#endif //NEURONS_NEURON_H
