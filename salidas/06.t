function f
  params
    _result
    a
    f
  endparams

  vars
    x 1
    b 1
    z 10
  endvars

     %1 = 5
     %3 = 1
     %2 = %3 * %1
     readi %5
     z[%2] = %5
     %6 = 5
     %8 = 1
     %7 = %8 * %6
     %9 = z[%7]
     %10 = 88
     %11 = %9 + %10
     writei %11
     readi b
     readf f
     ifFalse b goto endif1
     %13 = 'h'
     writec %13
     writeln
     %13 = '\t'
     writec %13
     %13 = 'l'
     writec %13
     %13 = '\\'
     writec %13
     %13 = 'a'
     writec %13
     %15 = -. f
     %16 = -. %15
     %17 = -. %16
     writef %17
     writeln
  label endif1 :
     %19 = 1
     %20 = %19
     _result = %20
     return
endfunction

function fz
  params
    _result
    r
    u
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
     %10 = 0
     %11 = r == %10
     ifFalse %11 goto endif1
     pushparam 
     %12 = 55555
     pushparam %12
     %13 = 1
     %14 = 4
     %15 = %13 / %14
     %15 = float %15
     pushparam %15
     call f
     popparam 
     popparam 
     popparam %16
  label endif1 :
     %18 = 3
     %19 = r + %18
     %22 = float %19
     %21 = %22 *. u
     %23 = %21
     _result = %23
     return
endfunction

function main
  vars
    a 1
    q 1
  endvars

   %1 = 0
   q = %1
   pushparam 
   %3 = 3
   %4 = 4
   %5 = %3 + %4
   pushparam %5
   pushparam 
   %6 = 4444
   pushparam %6
   %8 = 2
   %10 = float %8
   %9 = q +. %10
   pushparam %9
   call fz
   popparam 
   popparam 
   popparam %11
   pushparam %11
   call fz
   popparam 
   popparam 
   popparam %12
   q = %12
   %15 = 3.7
   %16 = q +. %15
   %17 = 4
   %19 = float %17
   %18 = %16 +. %19
   writef %18
   writeln
   return
endfunction


