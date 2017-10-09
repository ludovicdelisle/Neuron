//
// Created by Ludovic Delisle on 10/9/17.
//

#include "Network.h"
#include <iostream>
using namespace std;

Network::Network(){

}

void Network::add_a_neuron(Neuron* n){
    list_neurons.push_back(n);
}
void Network::kill_a_neuron(Neuron* n) {
    for (size_t i = 0; i<list_neurons.size(); ++i) {
        if(list_neurons[i]== n) {
         list_neurons.erase(list_neurons.begin()+i);
        }
    }
}
void Network::add_time_of_spike(double t){
    time_of_spikes.push_back(t);
}
void Network::update(int input, double h, double simtime){
    for(size_t i=0; i<list_neurons.size(); ++i){
        if(list_neurons[i]->update(input-i, h)){
            if(list_neurons[i]!=list_neurons.back()) {
                list_neurons[i + 1]->charge_J(18.0);
            }
            add_time_of_spike(simtime);
            ++number_of_spike_per_cycle.back();
        }

    }
    cout<< list_neurons[0]->get_potential()<<"    ";
    cout<< list_neurons[1]->get_potential()<< endl;
    number_of_spike_per_cycle.push_back(0);
}
vector<double> Network::get_time_of_spike()const{
    return time_of_spikes;
}
void Network::afficher_spikes_per_cycle(){
    for(size_t i=0; i<number_of_spike_per_cycle.size() ; ++i){
        for(int j=0; j<=number_of_spike_per_cycle[i]; ++j){
            cout<< "-";
        }
        cout<<endl;
    }
}
