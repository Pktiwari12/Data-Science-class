#ifndef Single_Neuran_H
#define Single_Neuran_H

#include<vector>
using namespace std;
float step_fxn(float input);
float sigmoid_fxn(float input);
vector<float>single_neuran_step_fxn(float lambda, float w0, float w1, float w2, float x0, vector<vector<float>>& data);

#endif