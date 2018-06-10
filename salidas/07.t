function f
  params
    a
  endparams

   %1 = 5
   %3 = 1
   %2 = %3 * %1
   %5 = 6.71
   a[%2] = %5
   %7 = 5
   %9 = 1
   %8 = %9 * %7
   %11 = 5
   %13 = 1
   %12 = %13 * %11
   %14 = a[%12]
   %15 = 10
   %17 = float %15
   %16 = %14 *. %17
   a[%8] = %16
   %19 = 5
   %21 = 1
   %20 = %21 * %19
   %22 = a[%20]
   writef %22
   writeln
   return
endfunction

function main
  vars
    b 10
    c 10
  endvars

   %1 = 5
   %3 = 1
   %2 = %3 * %1
   readf %5
   b[%2] = %5
   %6 = 7
   %8 = 1
   %7 = %8 * %6
   %10 = 5
   %12 = 1
   %11 = %12 * %10
   %13 = b[%11]
   c[%7] = %13
   %15 = 5
   %17 = 1
   %16 = %17 * %15
   %18 = b[%16]
   writef %18
   writeln
   %20 = 7
   %22 = 1
   %21 = %22 * %20
   %23 = c[%21]
   writef %23
   writeln
   %27 = &b
   pushparam %27
   call f
   popparam 
   %28 = 5
   %30 = 1
   %29 = %30 * %28
   %31 = b[%29]
   writef %31
   writeln
   %33 = 7
   %35 = 1
   %34 = %35 * %33
   %36 = c[%34]
   writef %36
   writeln
   return
endfunction


