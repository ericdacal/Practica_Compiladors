function x2
  params
    _result
    a
  endparams

  vars
    i 1
    n 1
  endvars

     %1 = 0
     n = %1
     %3 = 0
     i = %3
     %6 = 10
     %7 = i < %6
     ifFalse %7 goto endwhile1
  label loop41 :
     %10 = 1
     %9 = %10 * i
     %12 = a
     %11 = %12[%9]
     %13 = 0
     %14 = %11 == %13
     ifFalse %14 goto endif1
     %16 = 1
     %17 = n + %16
     n = %17
  label endif1 :
     %21 = 1
     %20 = %21 * i
     %22 = a
     %25 = 1
     %24 = %25 * i
     %27 = a
     %26 = %27[%24]
     %28 = 2
     %29 = %26 * %28
     %22[%20] = %29
     %33 = 1
     %32 = %33 * i
     %35 = a
     %34 = %35[%32]
     writei %34
     writeln
     %38 = 1
     %39 = i + %38
     i = %39
     %6 = 10
     %7 = i < %6
     ifFalse %7 goto endwhile1
     goto loop41
  label endwhile1 :
     %43 = n
     _result = %43
     return
endfunction

function main
  vars
    x 10
    i 1
    z 1
  endvars

     %1 = 0
     i = %1
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endwhile1
  label loop16 :
     %8 = 1
     %7 = %8 * i
     x[%7] = i
     %13 = 1
     %14 = i + %13
     i = %14
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endwhile1
     goto loop16
  label endwhile1 :
     %17 = 0
     i = %17
     %20 = 10
     %21 = i < %20
     ifFalse %21 goto endwhile2
  label loop31 :
     %24 = 1
     %23 = %24 * i
     %25 = x[%23]
     writei %25
     writeln
     %28 = 1
     %29 = i + %28
     i = %29
     %20 = 10
     %21 = i < %20
     ifFalse %21 goto endwhile2
     goto loop31
  label endwhile2 :
     pushparam 
     %34 = &x
     pushparam %34
     call x2
     popparam 
     popparam %33
     z = %33
     %36 = 'z'
     writec %36
     %36 = ':'
     writec %36
     writei z
     writeln
     %39 = 0
     i = %39
     %42 = 10
     %43 = i < %42
     ifFalse %43 goto endwhile3
  label loop56 :
     %44 = 'x'
     writec %44
     %44 = '['
     writec %44
     writei i
     %46 = ']'
     writec %46
     %46 = '='
     writec %46
     %49 = 1
     %48 = %49 * i
     %50 = x[%48]
     writei %50
     writeln
     %53 = 1
     %54 = i + %53
     i = %54
     %42 = 10
     %43 = i < %42
     ifFalse %43 goto endwhile3
     goto loop56
  label endwhile3 :
     return
endfunction


