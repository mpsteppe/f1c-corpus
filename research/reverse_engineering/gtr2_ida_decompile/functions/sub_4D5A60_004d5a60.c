int __stdcall sub_4D5A60(int a1, int a2, int a3)
{
  int v3; // eax
  int v4; // esi
  int v5; // ecx
  int *v6; // eax
  int v7; // edi

  v3 = *(_DWORD *)(a3 + 12);
  v4 = 0;
  if ( v3 <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = v4;
    if ( v4 < 0 || v4 >= v3 )
      goto LABEL_8;
    v6 = *(int **)a3;
    if ( v4 > 0 )
    {
      while ( v6 )
      {
        v6 = (int *)v6[1];
        if ( --v5 <= 0 )
          goto LABEL_7;
      }
LABEL_8:
      v7 = 0;
      goto LABEL_10;
    }
LABEL_7:
    if ( !v6 )
      goto LABEL_8;
    v7 = *v6;
LABEL_10:
    if ( sub_4D3810(v7, a1, a2) )
      return v7;
    v3 = *(_DWORD *)(a3 + 12);
    if ( ++v4 >= v3 )
      return 0;
  }
}
