int __stdcall sub_4958D0(int a1)
{
  int v1; // edi
  int i; // esi
  int v4; // eax
  int v5; // eax

  v1 = 0;
  if ( !a1 )
    return -1;
  for ( i = FieldGetter_8e30(a1); i; v1 += v4 )
  {
    v4 = ShortComputation_5920(i);
    i = *(_DWORD *)(i + 72);
  }
  v5 = ShortComputation_8f60(a1);
  return v1 + TreeWalkerVirtualCallRecurse(v5);
}

