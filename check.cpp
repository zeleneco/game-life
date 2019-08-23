int check(int first, int second, int size)
{
    int sum = 0, tempf, temps;

    tempf = first+1;
    if(tempf >= size) tempf = 0;
    sum+=generation[tempf][second];
    
    tempf = first-1;
    if(tempf < 0) tempf = size-1;
    sum+=generation[tempf][second];
    
    temps = second+1;
    if(temps >= size) temps = 0;
    sum+=generation[first][temps];
    
    temps = second-1;
    if(temps < 0) temps = size-1;
    sum+=generation[first][temps];
    
    tempf = first+1;
    temps = second+1;
    if(tempf >= size) tempf = 0;
    if(temps >= size) temps = 0;
    sum+=generation[tempf][temps];
    
    tempf = first-1;
    temps = second-1;
    if(tempf < 0) tempf = size-1;
    if(temps < 0) temps = size-1;
    sum+=generation[tempf][temps];
    
    tempf = first+1;
    temps = second-1;
    if(tempf >= size) tempf = 0;
    if(temps < 0) temps = size-1;
    sum+=generation[tempf][temps];
    
    tempf = first-1;
    temps = second+1;
    if(tempf < 0) tempf = size-1;
    if(temps >= size) temps = 0;
    sum+=generation[tempf][temps];

    return sum;
}
