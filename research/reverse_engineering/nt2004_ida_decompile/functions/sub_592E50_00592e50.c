int __stdcall sub_592E50(int *a1)
{
  int result; // eax
  int v2; // eax
  int i; // ecx

  result = 0;
  if ( dword_7E8D34 )
  {
    v2 = dword_7E8D34;
    for ( i = *(_DWORD *)(dword_7E8D34 + 32); i; i = *(_DWORD *)(i + 32) )
      v2 = i;
    *(_DWORD *)(v2 + 32) = a1;
    a1[7] = v2;
    result = *a1 + 1;
    a1[8] = 0;
    *a1 = result;
  }
  else
  {
    dword_7E8D34 = (int)a1;
    a1[7] = 0;
    a1[8] = 0;
    ++*a1;
  }
  return result;
}
