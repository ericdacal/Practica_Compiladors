function f1
  vars
    x1 1
    y1 1
  endvars

     %1 = 'e'
     writec %1
     %1 = 'r'
     writec %1
     %1 = 'r'
     writec %1
     %1 = '!'
     writec %1
     %1 = '!'
     writec %1
     writeln
     %4 = 2
     %5 = y1 * %4
     %6 = x1 == %5
     ifFalse %6 goto endif1
     %8 = 3
     %9 = y1 + %8
     x1 = %9
     %14 = y1 * x1
     %15 = x1 + %14
     y1 = %15
  label endif1 :
     return
endfunction

function main
  vars
    x1 1
  endvars

     %1 = 0
     x1 = %1
     %4 = 1
     %5 = x1 == %4
     ifFalse %5 goto endif1
     call f1
  label endif1 :
     %7 = 4
     %8 = 5
     %9 = %7 * %8
     %10 = 6
     %11 = %9 + %10
     x1 = %11
     writei x1
     writeln
     return
endfunction


