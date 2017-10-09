#include <iostream>
#include "Neuron.h"
#include "Network.h"

using namespace std;
int main() {
    Network network;
    Neuron n1;
    Neuron n2;
    network.add_a_neuron(&n1);
    network.add_a_neuron(&n2);

    int t_stop=1;
    double h=(0.001);
    double sim_time=0;
    do{
        double current_input=1;
        network.update(current_input, h, sim_time);
        sim_time+=h;
    }while(sim_time<t_stop);
    return 0;
}