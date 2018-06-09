function main
  vars
    a 1
    b 1
    end 1
    pi 1
    pi2 1
    pi3 1
    pi4 1
    pi5 1
    pi6 1
  endvars

   %1 = 12
   a = %1
   %3 = 5
   %4 = a * %3
   %7 = 1
   %8 = a + %7
   %9 = a * %8
   %10 = %4 + %9
   b = %10
   %13 = b == a
   %13 = not %13
   %15 = 0
   %16 = a == %15
   %17 = not %16
   %18 = %13 and %17
   end = %18
   %19 = 3.3
   pi = %19
   %20 = 1
   %22 = %20 / a
   pi2 = %22
   %23 = 2.0
   a = float a
   %25 = %23 /. a
   %26 = - %25
   %27 = - %26
   pi3 = %27
   %30 = pi +. pi2
   pi4 = %30
   %33 = pi4 +. pi3
   pi5 = %33
   %34 = 3.3
   %35 = 1
   %37 = %35 / a
   %37 = float %37
   %38 = %34 +. %37
   %39 = 2.0
   a = float a
   %41 = %39 /. a
   %42 = - %41
   %43 = %38 - %42
   pi6 = %43
   writeln
   writef pi
   writeln
   writef pi2
   writeln
   writef pi3
   writeln
   writef pi4
   writeln
   writef pi5
   writeln
   writef pi6
   writeln
   writeln
   %65 = a * b
   writei %65
   writeln
   %67 = 2
   %67 = float %67
   %69 = %67 *. pi
   writei %69
   writeln
   return
endfunction


