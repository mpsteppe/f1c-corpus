int __stdcall sub_676C7F(_DWORD *a1, int a2, int a3, int a4, unsigned int a5)
{
  int v5; // edi
  int result; // eax
  unsigned int v7; // esi

  if ( a3 >= 0 )
  {
    result = sub_6768C8(a1, a3, &a3);
    if ( result < 0 )
      return result;
    v5 = a3;
  }
  else
  {
    v5 = -a3;
  }
  v7 = a5 >> 2;
  while ( 1 )
  {
    result = sub_673DB1(v5, a2, a4, v7, 0);
    if ( result < 0 )
      break;
    v5 = *(_DWORD *)(v5 + 36);
    if ( !v5 )
      return 0;
  }
  return result;
}
