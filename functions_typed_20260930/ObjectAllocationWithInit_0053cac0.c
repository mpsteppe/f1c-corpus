int __stdcall sub_53CAC0(int *a1)
{
  int v1; // eax
  int v2; // eax

  v1 = OperatorNewNhMallocWrapper(48);
  if ( v1 )
    v2 = MultiFieldZeroInitConstructor(v1);
  else
    v2 = 0;
  *a1 = v2;
  return -(GuardedCallWithStatus(0) != 0);
}

