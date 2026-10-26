int __stdcall sub_5946B0(int a1, int a2)
{
  int v2; // ecx
  int v3; // edx
  int v4; // edi
  int v5; // esi
  int v6; // eax
  int result; // eax

  v2 = a1;
  if ( !a1 )
    return a2;
  v3 = a2;
  if ( !a2 )
    return a1;
  if ( **(float **)a1 >= (double)**(float **)a2 )
  {
    v4 = a2;
    v5 = a2;
    v3 = *(_DWORD *)(a2 + 4);
  }
  else
  {
    v4 = a1;
    v5 = a1;
    v2 = *(_DWORD *)(a1 + 4);
  }
  if ( v2 )
  {
    while ( v3 )
    {
      if ( **(float **)v2 >= (double)**(float **)v3 )
      {
        v6 = v3;
        v3 = *(_DWORD *)(v3 + 4);
      }
      else
      {
        v6 = v2;
        v2 = *(_DWORD *)(v2 + 4);
      }
      *(_DWORD *)(v5 + 4) = v6;
      v5 = v6;
      if ( !v2 )
        goto LABEL_12;
    }
    result = v4;
    *(_DWORD *)(v5 + 4) = v2;
  }
  else
  {
LABEL_12:
    result = v4;
    if ( v3 )
      *(_DWORD *)(v5 + 4) = v3;
    else
      *(_DWORD *)(v5 + 4) = 0;
  }
  return result;
}
