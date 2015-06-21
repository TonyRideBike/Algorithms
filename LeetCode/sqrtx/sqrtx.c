int mySqrt(int x) {
    if(x <= 0)
        return 0;
    double root = 1;
    while(root*root-x > 0.5 || root*root-x < -0.5){
        root = (root + x/root) / 2;
    }
    return (int)root;
}