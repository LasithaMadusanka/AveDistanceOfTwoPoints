# include <stdio.h>
# include <math.h>


double f(double x1, double y1, double x2, double y2){
    double sum = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1); 
    double distance = sqrt(sum); //used the pythogoren thereom to calculate the distance
    return distance;
}

double g(int N){
    double sum=0, h;
     
    h = 1.0/N; //since we are dealing with unit square the differenace between upper and lower limit is 1.0
    
    for ( int i = 0; i < N; i++){ //since I want to deal with 4D space I used 4 for loop to evaluate the Trapezodail sum
       for ( int j = 0; j < N; j++){
          double x1 = i*h;//we can have x1 vales like 1h,2h,...,(N-1)h
          double y1 = j*h;
          for (int p = 0; p < N; p++){
            for (int q = 0; q < N; q++){
                double x2 = p*h;
                double y2 = q*h;
                if (x1 != x2 || y1 != y2){//here I don't need the overlapping values,so I ignore them
                    double distance = f(x1,y1,x2,y2);
                    sum += distance;
                }
                
            }
            
          }
          
       }

        
    }
    double ave_distance = sum/(N*N*N*N);//4D space average distance
    return ave_distance;
    

}
int main(){
    int N;
    double error_1 =0;//initialising this means I don't expect and value to the first convergence order
    for (N= 5; N<=80; N*=2){ //used a for loop to find the output together to all N values I want
    double ave_distance = g(N);
    double Convergence_Order;
    double error = fabs(0.53-ave_distance);//assuming the exact value is 0.53
    Convergence_Order = log10(error_1/error)/log(2);
    error_1= error;
    printf(" \nWhen N = %d the Average distance  of two random points within a square is: %lf and the error is %lf with Convergence_Order %lf",N, ave_distance,error,Convergence_Order);
    
    }
}