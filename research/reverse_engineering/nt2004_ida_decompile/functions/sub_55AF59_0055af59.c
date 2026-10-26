int __cdecl sub_55AF59(_DWORD *a1, char a2)
{
  bool v3; // zf
  int v4; // edi
  int result; // eax
  int v6; // ebx
  unsigned int v7; // ebx
  int i; // esi
  int v9; // [esp+10h] [ebp+8h]

  v3 = a1[19] == 0;
  v4 = a1[105];
  result = *(_DWORD *)(v4 + 24);
  v9 = result;
  if ( !v3 )
    a1[19] = 2;
  if ( a2 )
  {
    *(_DWORD *)(v4 + 4) = sub_55A16A;
    *(_DWORD *)(v4 + 8) = sub_55AF37;
    *(_BYTE *)(v4 + 28) = 1;
  }
  else
  {
    if ( a1[19] == 2 )
      *(_DWORD *)(v4 + 4) = sub_55AC39;
    else
      *(_DWORD *)(v4 + 4) = sub_55AB90;
    *(_DWORD *)(v4 + 8) = nullsub_8;
    v6 = a1[28];
    if ( v6 < 1 )
    {
      *(_DWORD *)(*a1 + 20) = 55;
      *(_DWORD *)(*a1 + 24) = 1;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
    result = 256;
    if ( v6 > 256 )
    {
      *(_DWORD *)(*a1 + 20) = 56;
      *(_DWORD *)(*a1 + 24) = 256;
      result = (*(int (__cdecl **)(_DWORD *))*a1)(a1);
    }
    if ( a1[19] == 2 )
    {
      v7 = 6 * (a1[23] + 2);
      if ( !*(_DWORD *)(v4 + 32) )
        *(_DWORD *)(v4 + 32) = (*(int (__cdecl **)(_DWORD *, int, unsigned int))(a1[1] + 4))(a1, 1, v7);
      result = sub_55293B(*(void **)(v4 + 32), v7);
      if ( !*(_DWORD *)(v4 + 40) )
        result = sub_55AEA7((int)a1);
      *(_BYTE *)(v4 + 36) = 0;
    }
  }
  if ( *(_BYTE *)(v4 + 28) )
  {
    for ( i = 0; i < 32; ++i )
      result = sub_55293B(*(void **)(v9 + 4 * i), 0x1000u);
    *(_BYTE *)(v4 + 28) = 0;
  }
  return result;
}
