function fact
  params
    _result
    n
  endparams

  vars
    f 1
  endvars

     %1 = 1
     f = %1
     %4 = 1
     %5 = n <= %4
     %5 = not %5
     ifFalse %5 goto endwhile1
  label loop14 :
     %8 = f * n
     f = %8
     %11 = 1
     %12 = n - %11
     n = %12
     %4 = 1
     %5 = n <= %4
     %5 = not %5
     ifFalse %5 goto endwhile1
     goto loop14
  label endwhile1 :
     %16 = f
     _result = %16
     return
endfunction

function main
  vars
    max 1
    i 1
    f 1
    end 1
  endvars

     %1 = 1
     end = %1
     readi max
     %5 = i <= max
     ifFalse %5 goto else10
     %6 = 0
     end = %6
     goto endif1
  label else10 :
     %8 = 0
     i = %8
  label endif1 :
     %12 = not end
     ifFalse %12 goto endwhile1
  label loop29 :
     writei i
     %14 = '!'
     writec %14
     %14 = '='
     writec %14
     pushparam 
     pushparam i
     call fact
     popparam 
     popparam %16
     writei %16
     writeln
     %21 = i == max
     ifFalse %21 goto else28
     %22 = 1
     end = %22
     goto endif2
  label else28 :
     %25 = 1
     %26 = i + %25
     i = %26
  label endif2 :
     %12 = not end
     ifFalse %12 goto endwhile1
     goto loop29
  label endwhile1 :
     return
endfunction


