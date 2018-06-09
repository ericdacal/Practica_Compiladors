func main()
  var a, b: int
  var end : bool
  var pi,pi2,pi3,pi4,pi5,pi6 : float
  a = 12;
  b = a*5 + a*(a+1);
  end = b >= a and not (a == 0);
  pi = 3.3 ;
  pi2 = 1/a;
  pi3 = - -2.0/a;
  pi4 = pi + pi2;
  pi5 = pi4 + pi3;
  pi6 = 3.3 +  1/a - -2.0/a;
  write "\n";
  write pi;
  write "\n";
  write pi2;
  write "\n";
  write pi3;
  write "\n";
  write pi4;
  write "\n";
  write pi5;
  write "\n";
  write pi6;
  write "\n";
  write a==b or end;
  write "\n";
  write a*b;
  write "\n";
  write 2*pi;
  write "\n";
endfunc
