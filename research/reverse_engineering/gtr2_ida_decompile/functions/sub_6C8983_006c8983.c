int __thiscall sub_6C8983(int this)
{
  int *v1; // edx
  int v2; // eax
  unsigned int v3; // esi
  int v4; // esi
  char *v5; // eax
  char *v6; // edx
  int v7; // esi
  int v8; // edx
  char *v9; // edx
  unsigned int v10; // ebx
  char *v12; // edx
  bool v13; // zf
  int v14; // eax
  char *v15; // eax
  _DWORD *i; // esi
  unsigned int v17; // [esp+Ch] [ebp-10h]
  char *v18; // [esp+10h] [ebp-Ch]
  unsigned int v19; // [esp+14h] [ebp-8h]
  int v20; // [esp+14h] [ebp-8h]
  char *v21; // [esp+18h] [ebp-4h]
  int v22; // [esp+18h] [ebp-4h]

  *(_DWORD *)(this + 348) = 0;
  v1 = *(int **)(this + 256);
  v2 = *v1;
  v3 = *v1 & 0xFFF00000;
  if ( v3 == 542113792 )
  {
    v4 = v2 & 0xFFFFF;
    v5 = (char *)v1[2];
    v6 = &v5[4 * v4];
    v19 = v4;
    v7 = *(_DWORD *)(this + 20);
    v21 = v6;
    v8 = *(_DWORD *)(this + 16);
    if ( (*(_DWORD *)(*(_DWORD *)(v8 + 4 * *(_DWORD *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)v5) + 4)) + 4) & 0x100) != 0 )
    {
      v9 = v5;
      v5 = v21;
LABEL_6:
      v18 = v9;
      if ( !v19 )
        return sub_6C73E9(this, 0x40000, 0x20000, v18, 0x40000, 0, 0);
      v10 = 0;
      v22 = v5 - v9;
      while ( *(double *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)&v9[v22]) + 32) == 2.0
           && ((*(_DWORD *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)v9) + 60) & 0x1F0000) == 0x20000
            || (*(_BYTE *)(this + 110) & 8) == 0) )
      {
        ++v10;
        v9 += 4;
        if ( v10 >= v19 )
          return sub_6C73E9(this, 0x40000, 0x20000, v18, 0x40000, 0, 0);
      }
      return 1;
    }
    if ( (*(_DWORD *)(*(_DWORD *)(v8 + 4 * *(_DWORD *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)v21) + 4)) + 4) & 0x100) != 0 )
    {
      v9 = v21;
      goto LABEL_6;
    }
    return 1;
  }
  if ( v3 != 541065216 )
    return 1;
  v12 = (char *)v1[2];
  v14 = v2 & 0xFFFFF;
  v13 = v14 == 0;
  v17 = v14;
  v15 = &v12[4 * v14];
  v20 = 0;
  if ( !v13 )
  {
    for ( i = v12;
          *i == *(_DWORD *)((char *)i + v15 - v12)
       && ((*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *i) + 60) & 0x1F0000) == 0x20000
        || (*(_BYTE *)(this + 110) & 8) == 0);
          ++i )
    {
      if ( ++v20 >= v17 )
        return sub_6C73E9(this, 0x40000, 0x20000, v12, 0x40000, 0, 0);
    }
    return 1;
  }
  return sub_6C73E9(this, 0x40000, 0x20000, v12, 0x40000, 0, 0);
}
