int __thiscall sub_6A043C(_DWORD *this)
{
  int v1; // edi
  int v2; // eax
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // esi
  int v7; // edx
  int v8; // eax
  int v9; // edx
  unsigned int v10; // edi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  unsigned int v15; // [esp+4h] [ebp-14h]
  unsigned int v16; // [esp+8h] [ebp-10h]
  int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]

  v18 = -1;
  v17 = -1;
  v1 = 0;
  v16 = 0;
  if ( this[2] )
  {
    while ( 1 )
    {
      v2 = 4 * v1;
      v3 = *(_DWORD *)(4 * v1 + this[5]);
      if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v3 + 4)) + 4) & 0x10) == 0 )
        goto LABEL_23;
      v4 = *(_DWORD *)(v3 + 108);
      if ( v4 != 17 && v4 != 18 )
        goto LABEL_23;
      **(_DWORD **)(v2 + this[5]) &= 0x40000000u;
      if ( **(_DWORD **)(v2 + this[5]) )
        goto LABEL_23;
      v5 = *(_DWORD *)(v2 + this[5]);
      v6 = *(_DWORD *)(v5 + 108);
      if ( v6 != 17 )
        goto LABEL_9;
      if ( v18 == -1 )
        break;
LABEL_23:
      v1 = ++v16;
      if ( v16 >= this[2] )
        return 0;
    }
    v18 = v1;
LABEL_9:
    if ( v6 == 18 )
    {
      if ( v17 != -1 )
      {
        v7 = this[5];
        v8 = *(_DWORD *)(v7 + 4 * v1);
        v9 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * v17) + 12);
LABEL_22:
        *(_DWORD *)(v8 + 12) = v9;
        goto LABEL_23;
      }
      v17 = v1;
    }
    v19 = -1;
    v10 = 0;
    v15 = *(_DWORD *)(v5 + 12);
    if ( !this[2] )
      goto LABEL_23;
    do
    {
      v11 = *(_DWORD *)(this[5] + 4 * v10);
      if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v11 + 4)) + 4) & 0x10) != 0 )
      {
        v12 = *(_DWORD *)(v11 + 12);
        if ( v12 > v15 )
        {
          if ( v19 <= v12 )
            v19 = v12;
          v13 = *(_DWORD *)(this[5] + 4 * v10);
          --*(_DWORD *)(v13 + 12);
        }
      }
      ++v10;
    }
    while ( v10 < this[2] );
    v9 = v19;
    if ( v19 == -1 )
      goto LABEL_23;
    v8 = *(_DWORD *)(v2 + this[5]);
    goto LABEL_22;
  }
  return 0;
}
