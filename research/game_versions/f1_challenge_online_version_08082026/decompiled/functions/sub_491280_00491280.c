char __stdcall sub_491280(int a1, int a2)
{
  __int16 **v2; // eax
  bool v3; // zf
  __int16 *v4; // eax
  int v5; // eax
  __int16 **v6; // eax

  v2 = *(__int16 ***)a1;
  v3 = *(_DWORD *)a1 == 0;
  *(_DWORD *)(a1 + 8) = *(_DWORD *)a1;
  if ( v3 )
    return 0;
  v4 = *v2;
  if ( !v4 )
    return 0;
  while ( !(unsigned __int8)sub_491680(*v4, v4[1], v4[2], v4[3]) )
  {
    v5 = *(_DWORD *)(a1 + 8);
    if ( v5 )
    {
      v6 = *(__int16 ***)(v5 + 4);
      *(_DWORD *)(a1 + 8) = v6;
      if ( v6 )
      {
        v4 = *v6;
        if ( v4 )
          continue;
      }
    }
    return 0;
  }
  return 1;
}
