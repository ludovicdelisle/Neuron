//
// Created by Ludovic Delisle on 10/2/17.
//

#include "Neuron.h"



void Neuron::update(int input, double h, double simtime){
    if (refractory){
        potential_V=-70;
        refractory=false;
        add_spike();
        add_time_of_spike(simtime);
    }else if(potential_V>-55){
        refractory=true;
    }else{
        potential_V=new_potential_calcul(input, h);
    }
}
double Neuron::get_potential()const{
    return potential_V;
}
int Neuron::get_spikes()const{
    return spikes;
}
/*vector Neuron::get_time_of_spikes()const{
    return time_of_spikes;
}*/
void Neuron::add_spike(){
    spikes+=1;
}
void Neuron::add_time_of_spike(double t){
    time_of_spikes.push_back(t);
}
bool Neuron::get_refractory()const{
    return refractory;
}
double Neuron::new_potential_calcul(int input, double h) {
    double V;
    V = exp(-h/tao) * potential_V + input * R / tao * (1 - exp(-h/tao));
    return V;
}
