function main
  vars
    a 1
    b 1
    end 1
    pi 1
  endvars

   %1 = 12
   a = %1
   %4 = 5
   %5 = a * %4
   %8 = 1
   %9 = a + %8
   %10 = a * %9
   %11 = %5 + %10
   b = %11
   %15 = b < a
   %15 = not %15
   %17 = 0
   %18 = a == %17
   %19 = not %18
   %20 = %15 and %19
   end = %20
   %22 = 3.3
   %23 = 1
   %25 = %23 / a
   %27 = float %25
   %26 = %22 +. %27
   %28 = 2.0
   %31 = float a
   %30 = %28 /. %31
   %32 = -. %30
   %33 = %26 -. %32
   pi = %33
   %37 = a == b
   %39 = %37 or end
   writei %39
   writeln
   %43 = a * b
   writei %43
   writeln
   %45 = 2
   %48 = float %45
   %47 = %48 *. pi
   writef %47
   writeln
   return
endfunction


