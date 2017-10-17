//
// Created by Ludovic Delisle on 10/2/17.
//

#include "Neuron.h"



bool Neuron::update(double input, double h) {
    if (refractory){
        refractory=false;
        potential_V=new_potential_calcul(input, h);
        set_buffer();
        return false;
    }else if(potential_V>=20){
        potential_V=0;
        refractory=true;
        set_buffer();
        return true;
    }else{
        potential_V=new_potential_calcul(input, h);
        set_buffer();
        return false;
    }
}
double Neuron::get_potential()const{
    return potential_V;
}
bool Neuron::get_refractory()const{
    return refractory;
}
double Neuron::new_potential_calcul(double input, double h) {
    double V;
        V = pow(M_E, -h / tao) * potential_V + input * R * (1 - pow(M_E, -h / tao)) + buffer.back();

    return V;
}
vector <Neuron*> Neuron::get_leaving_links(){
    return leaving_links;
}
void Neuron::charge_J(double input){
    buffer[0] += input;
}
void Neuron::set_buffer(){
    for(size_t i = buffer.size()-1; i>0; --i){
       buffer[i]= buffer[i-1];
    }
    buffer[0]=0;
}
