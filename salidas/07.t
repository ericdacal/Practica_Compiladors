function f
  params
    a
  endparams

   %1 = 5
   %3 = 1
   %2 = %3 * %1
   %5 = 5
   %7 = 1
   %6 = %7 * %5
   %9 = a
   %8 = %9[%6]
   %10 = 10
   %12 = float %10
   %11 = %8 *. %12
   a[%2] = %11
   %14 = 'h'
   writec %14
   %14 = 'o'
   writec %14
   %14 = 'l'
   writec %14
   %14 = 'a'
   writec %14
   %15 = 5
   %17 = 1
   %16 = %17 * %15
   %19 = a
   %18 = %19[%16]
   writef %18
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


