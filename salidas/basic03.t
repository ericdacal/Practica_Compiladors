function f
  vars
    a 1
    b 1
  endvars

     readi a
     %2 = 10
     %3 = a == %2
     ifFalse %3 goto endif1
     %4 = 3
     a = %4
  label endif1 :
     %7 = 67
     %8 = a + %7
     b = %8
     %12 = b + a
     %13 = 1
     %14 = %12 + %13
     writei %14
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


