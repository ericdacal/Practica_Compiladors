Typecheck float integer /
Typecheck float integer -
float integer float
float integer float
function main
  vars
    a 1
    b 1
    end 1
    pi 1
  endvars

   %1 = 12
   a = %1
   %2 = 3.3
   %3 = 2.0
   %4 = 12
   %6 = float %4
   %5 = %3 /. %6
   %7 = -. %5
   %9 = float %7
   %8 = %2 -. %9
   writef %8
   writeln
   writeln
   writeln
   return
endfunction


