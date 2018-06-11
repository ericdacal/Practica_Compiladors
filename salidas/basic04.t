function f
  vars
    a 1
    b 1
  endvars

     readi a
     %2 = 10
     %3 = a == %2
     ifFalse %3 goto endif1
     %4 = 4
     %5 = 0
     %6 = %4 * %5
     %7 = 3
     %8 = %6 + %7
     a = %8
     call f
  label endif1 :
     %12 = 9
     %13 = a + %12
     b = %13
     %17 = 2
     %18 = a * %17
     %19 = b + %18
     writei %19
     writeln
     return
endfunction

function main
  vars
    a 1
  endvars

     readi a
     %2 = 3
     %3 = a == %2
     ifFalse %3 goto endif1
     call f
  label endif1 :
     %5 = '.'
     writec %5
     writeln
     return
endfunction


