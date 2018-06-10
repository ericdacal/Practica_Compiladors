function main
  vars
    n 1
    f 1
    aux 1
    end 1
  endvars

     %1 = 1
     f = %1
     %2 = false
     end = %2
     %4 = false
     %5 = end == %4
     ifFalse %5 goto endif1
     %6 = '!'
     writec %6
     %6 = '='
     writec %6
     writei f
     writeln
  label endif1 :
     return
endfunction


