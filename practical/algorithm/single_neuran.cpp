#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
float step_fxn(float);
float sigmoid_fxn(float);
vector<float>single_neuran_step_fxn(float lambda, float w0, float w1, float w2, float x0, vector<vector<float>>& data){
    // loop for epochs
    int w_not_changed = false;
    int count = 1;
    while(w_not_changed == false){
            w_not_changed = true;
            cout << count <<"  Epoch  :" << endl << endl;
            for(int i = 0 ; i < data.size() ; i++){
                float b = w0*x0;    // bias term
                float x1 = data[i][0];
                float x2 = data[i][1];
                float input = b + w1*x1 + w2*x2;
                // float y = step_fxn(input); // prediction
                float y = sigmoid_fxn(input);
                float d = data[i][2];   // target value
                if( y != data[i][2]){
                    // adaptive law
                    w0 = w0 + lambda*(d-y)*x0;
                    w1 = w1 + lambda*(d-y)*x1;
                    w2 = w2 + lambda*(d-y)*x2;
                    w_not_changed = false; // check this flag.
                }

            }
        count++;
        cout << w0 << "\t" << w1 << "\t" << w2 << endl;
    }
    cout << "Our Final weights " << endl << endl;
    cout << w0 << "\t" << w1 << "\t" << w2 << endl;
    cout << "("<< w0 << "," << w1 << "," << w2 << ")" << endl;
    return {w0,w1,w2};

}
// first Activation Function
float step_fxn(float input){
    if(input > 0.0){
        return 1;
    }
    else{
        return 0;
    }
}

// Second Activation Function
float sigmoid_fxn(float input){
    float threshold = 0.5;      // threshold probability
    float output = 1 / (1 + exp(-input));
    // cout << output << endl;
    if(output >= 0.5){ // then o/p is 1
        return 1;
    }
    else {  // then o/p is 0
        return 0;
    }
}
int main(){
    vector<vector<float>> data = {
        {0.2, 0.1, 1},
        {0.4, 0.6, 1},
        {0.5, 0.2, 1},
        {0.7, 0.9, 0}
    };
    // for(int i = 0 ; i<4 ; i++){
    //     cout << "w =  "<< i << endl << endl;
        single_neuran_step_fxn(1,3,3,3,0,data);
        // cout << endl << endl << endl << endl;
    // }
    // cout << sigmoid_fxn(-0.1) << endl;

}
