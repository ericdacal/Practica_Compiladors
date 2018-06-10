function main
  vars
    n 1
    f 1
    aux 1
    end 1
  endvars

     readi n
     aux = n
     %4 = 0
     %5 = n < %4
     ifFalse %5 goto endif1
     %6 = 'n'
     writec %6
     %6 = ' '
     writec %6
     %6 = '>'
     writec %6
     %6 = '='
     writec %6
     %6 = ' '
     writec %6
     %6 = '0'
     writec %6
     %6 = '!'
     writec %6
     writeln
     %7 = 1
     end = %7
  label endif1 :
     %9 = 1
     f = %9
     %12 = not end
     %14 = 1
     %15 = n <= %14
     %15 = not %15
     %16 = %12 and %15
     ifFalse %16 goto endwhile1
  label loop25 :
     %19 = f * n
     f = %19
     %22 = 1
     %23 = n - %22
     n = %23
     %12 = not end
     %14 = 1
     %15 = n <= %14
     %15 = not %15
     %16 = %12 and %15
     ifFalse %16 goto endwhile1
     goto loop25
  label endwhile1 :
     %27 = 0
     %28 = end == %27
     ifFalse %28 goto endif2
     writei aux
     %30 = '!'
     writec %30
     %30 = '='
     writec %30
     writei f
     writeln
  label endif2 :
     return
endfunction


