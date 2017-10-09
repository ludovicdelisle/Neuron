//
// Created by Ludovic Delisle on 10/2/17.
//

#include "Neuron.h"



bool Neuron::update(int input, double h) {
    if (refractory){
        refractory=false;
        potential_V=new_potential_calcul(input, h);
        return false;
    }else if(potential_V>=20){
        potential_V=0;
        refractory=true;
        return true;
    }else{
        potential_V=new_potential_calcul(input, h);
        return false;
    }
}
double Neuron::get_potential()const{
    return potential_V;
}
bool Neuron::get_refractory()const{
    return refractory;
}
double Neuron::new_potential_calcul(int input, double h) {
    double V;
    if(buffer<=0) {
        V = pow(M_E, -h / tao) * potential_V + input * R * (1 - pow(M_E, -h / tao)) + J;
        J = 0;
    }else {
        V = pow(M_E, -h / tao) * potential_V + input * R * (1 - pow(M_E, -h / tao));
        buffer--;
    }
    return V;
}
vector <Neuron*> Neuron::get_leaving_links(){
    return leaving_links;
}
void Neuron::charge_J(double input){
    J+=input;
}
void Neuron::set_buffer(int b){
    buffer=b;
}
