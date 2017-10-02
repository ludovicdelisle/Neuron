#include <iostream>
#include "Neuron.h"
#include <chrono>

using namespace std;
int main() {
    Neuron neuron1;
    int t_stop=1;
    double h=(0.001);
    double sim_time=0;
    do{
        double current_input=0.000000000000000000000002;
        neuron1.update(current_input, h, sim_time);
        sim_time+=h;
        cout<< sim_time << "   ";
        cout<< neuron1.get_potential()<<endl;
    }while(sim_time<t_stop);
    return 0;
}