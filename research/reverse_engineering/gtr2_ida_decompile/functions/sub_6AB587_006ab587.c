int __stdcall sub_6AB587(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v4; // eax
  int v5; // ecx

  v4 = *(_DWORD *)(a1 + 108);
  v5 = *(unsigned __int8 *)(a1 + 109);
  *a2 = v5;
  if ( (unsigned __int8)v4 == 1 )
  {
    if ( !v5 )
    {
      *a3 = 0;
      if ( a4 )
        *a4 = 0;
      return 0;
    }
  }
  else if ( (unsigned __int8)v4 == 2 && !v5 )
  {
    *a3 = 9;
    if ( a4 )
      *a4 = 1;
    return 0;
  }
  return -2147467259;
}
