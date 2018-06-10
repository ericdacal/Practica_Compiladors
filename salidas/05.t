function f
  params
    _result
    a
    b
  endparams

  vars
    x 1
    y 1
    z 10
  endvars

     %1 = 9
     %3 = 1
     %2 = %3 * %1
     %6 = 67
     %7 = a + %6
     z[%2] = %7
     %9 = 9
     %11 = 1
     %10 = %11 * %9
     %12 = %9[%10]
     writei %12
     writeln
     %14 = 34
     x = %14
     %16 = 3
     %18 = 1
     %17 = %18 * %16
     %20 = 56
     %21 = 9
     %23 = 1
     %22 = %23 * %21
     %24 = %21[%22]
     %25 = %20 + %24
     z[%17] = %25
     %27 = 3
     %29 = 1
     %28 = %29 * %27
     %30 = %27[%28]
     %32 = %30 <= x
     %32 = not %32
     ifFalse %32 goto endif1
     %33 = 78
     x = %33
     writef b
     writeln
  label endif1 :
     %39 = 3
     %41 = 1
     %40 = %41 * %39
     %42 = %39[%40]
     writei %42
     writeln
     return
endfunction

function fz
  params
    r
  endparams

     %2 = 0
     %3 = r <= %2
     %3 = not %3
     ifFalse %3 goto endwhile1
  label loop8 :
     %5 = 1
     %6 = r - %5
     r = %6
     %2 = 0
     %3 = r <= %2
     %3 = not %3
     ifFalse %3 goto endwhile1
     goto loop8
  label endwhile1 :
     return
endfunction

function main
  vars
    a 1
  endvars

     pushparam 
     %1 = 3
     pushparam %1
     %2 = 2
     pushparam %2
     call f
     popparam %1
     popparam %2
     popparam %3
     ifFalse %3 goto endif1
     %5 = 3.7
     %7 = float a
     %6 = %7 +. %5
     %8 = 4
     %10 = float %8
     %9 = %6 +. %10
     writef %9
     writeln
  label endif1 :
     return
endfunction


