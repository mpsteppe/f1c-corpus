int __usercall ExpHypSum@<eax>(char a1@<bh>, double a2@<st1>)
{
  double v2; // st7

  v2 = ExpHypCopyInv() + a2;
  if ( a1 )
    return ((int (*)(void))ExpHypSumReturn)();
  else
    return ExpHypSumReturn(v2 + 1.0 + 1.0);
}
