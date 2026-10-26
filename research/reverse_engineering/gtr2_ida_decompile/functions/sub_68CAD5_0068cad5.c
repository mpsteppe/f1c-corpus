int __thiscall sub_68CAD5(_DWORD *this)
{
  int v2; // esi
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // ecx
  _DWORD *v6; // eax
  int v7; // ecx
  int v8; // edx
  unsigned int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  int *v17; // ecx
  int v18; // edx
  _BYTE v20[16]; // [esp+4h] [ebp-30h] BYREF
  int v21; // [esp+14h] [ebp-20h]
  int v22; // [esp+18h] [ebp-1Ch]
  unsigned int v23; // [esp+1Ch] [ebp-18h]
  unsigned int v24; // [esp+20h] [ebp-14h]
  _DWORD *v25; // [esp+24h] [ebp-10h]
  _DWORD *v26; // [esp+28h] [ebp-Ch]
  unsigned int i; // [esp+2Ch] [ebp-8h]
  unsigned int j; // [esp+30h] [ebp-4h]

  sub_686074((int)this);
  for ( i = 0; i < this[3]; ++i )
  {
    v2 = *(_DWORD *)(this[6] + 4 * i);
    v3 = *(_DWORD *)v2;
    j = *(_DWORD *)v2;
    j &= 0xFFF00000;
    if ( !j )
      continue;
    v4 = v3 & 0xFFFFF;
    v23 = *(_DWORD *)(v2 + 4) / (v3 & 0xFFFFF);
    if ( j == 1342177280 )
    {
      sub_685E08(this, (_DWORD *)(*(_DWORD *)(v2 + 8) + 4 * v4), (int)v20, v3 & 0xFFFFF, 1);
      sub_685E08(this, *(_DWORD **)(v2 + 8), (int)v20, v4, 0);
    }
    else
    {
      v5 = v3 & 0xF0000000;
      if ( v5 >= 0x10000000 && v5 <= 0x40000000 )
      {
        sub_685E08(this, *(_DWORD **)(v2 + 16), (int)v20, v4, 1);
        for ( j = 0; j < v23; ++j )
          sub_685E08(this, (_DWORD *)(*(_DWORD *)(v2 + 8) + 4 * j * *(_DWORD *)(v2 + 12)), (int)v20, v4, 0);
      }
    }
    if ( (*(_DWORD *)v2 & 0xF0000000) != 0x20000000 || !sub_680DDB((_DWORD *)v2) )
      continue;
    v6 = *(_DWORD **)(v2 + 8);
    v7 = this[5];
    v8 = *(_DWORD *)(v7 + 4 * *v6);
    v9 = *(_DWORD *)(v7 + 4 * v6[v4]);
    v24 = -1;
    j = -1;
    v21 = v8;
    v23 = v9;
    if ( v4 )
    {
      v26 = *(_DWORD **)(v2 + 8);
      v25 = &v26[v4];
      v22 = v4;
      do
      {
        if ( *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v26) + 72) < v24 )
          v24 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v26) + 72);
        if ( *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v25) + 72) < j )
          j = *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v25) + 72);
        ++v26;
        ++v25;
        --v22;
      }
      while ( v22 );
      if ( v24 < j )
        continue;
      if ( v24 != j )
        goto LABEL_25;
    }
    v10 = *(_DWORD *)(v23 + 4);
    v11 = this[4];
    v22 = 4 * *(_DWORD *)(v21 + 4);
    v12 = 4 * v10;
    if ( *(_DWORD *)(*(_DWORD *)(v22 + v11) + 4) >= *(_DWORD *)(*(_DWORD *)(v11 + v12) + 4) )
    {
      if ( *(_DWORD *)(*(_DWORD *)(this[4] + v22) + 4) != *(_DWORD *)(*(_DWORD *)(this[4] + v12) + 4)
        || (v13 = *(_DWORD *)(v23 + 4), v14 = *(_DWORD *)(v21 + 4), v14 >= v13)
        && (v14 != v13 || *(_DWORD *)(v21 + 12) >= *(_DWORD *)(v23 + 12)) )
      {
LABEL_25:
        j = 0;
        if ( v4 )
        {
          v21 = 4 * v4;
          do
          {
            v15 = *(_DWORD *)(v2 + 8);
            v16 = j++;
            v17 = (int *)(v15 + 4 * v16);
            v22 = *v17;
            v18 = v21;
            *v17 = *(_DWORD *)(v21 + v15);
            *(_DWORD *)(v18 + *(_DWORD *)(v2 + 8)) = v22;
            v21 = v18 + 4;
          }
          while ( j < v4 );
        }
      }
    }
  }
  return 0;
}
