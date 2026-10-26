int __thiscall sub_6636D3(_DWORD *this, _DWORD *a2, int a3, unsigned int a4, unsigned int a5)
{
  _DWORD *v5; // esi
  int result; // eax
  int v7; // eax
  _DWORD *v8; // ebx
  _DWORD *v9; // edx
  int v10; // edi
  _DWORD *v11; // esi
  bool v12; // zf
  int v13; // eax
  int v14; // ecx
  _DWORD *v15; // edi
  _DWORD *v16; // eax
  int v17; // esi
  _DWORD *v18; // edx
  bool v19; // zf
  int v20; // [esp+4h] [ebp-14h]
  int v22; // [esp+Ch] [ebp-Ch]
  unsigned int v23; // [esp+10h] [ebp-8h]
  unsigned int v24; // [esp+10h] [ebp-8h]
  _DWORD *v25; // [esp+14h] [ebp-4h]
  unsigned int v26; // [esp+20h] [ebp+8h]
  unsigned int v27; // [esp+24h] [ebp+Ch]
  _DWORD *v28; // [esp+24h] [ebp+Ch]

  v5 = this;
  if ( a3 != 2 )
    return a4 > 1;
  result = a5 * a4;
  if ( a5 * a4 )
  {
    v23 = 0;
    if ( a4 )
    {
      v7 = this[2];
      v8 = a2;
      while ( 1 )
      {
        v9 = *(_DWORD **)(*(_DWORD *)(v7 + 20) + 4 * *v8);
        v27 = 0;
        v10 = v9[1];
        if ( a5 )
          break;
LABEL_16:
        ++v23;
        v8 += a5;
        if ( v23 >= a4 )
          goto LABEL_17;
      }
      v22 = *(_DWORD *)(v5[2] + 20);
      v25 = v8;
      while ( 1 )
      {
        v11 = *(_DWORD **)(v22 + 4 * *v25);
        if ( v10 != v11[1] )
          return 1;
        if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v7 + 16) + 4 * v10) + 4) & 0x40) != 0 )
        {
          if ( v9[3] + (v27 >> 2) != v11[3] )
            return 1;
          v12 = v9[4] + (v27 & 3) == v11[4];
        }
        else
        {
          v12 = v9[18] == v11[18];
        }
        if ( !v12 )
          return 1;
        ++v27;
        ++v25;
        if ( v27 >= a5 )
        {
          v5 = this;
          goto LABEL_16;
        }
      }
    }
LABEL_17:
    v24 = 0;
    if ( !a5 )
      return 1;
    v13 = v5[2];
    v14 = *(_DWORD *)(v13 + 20);
    v15 = a2;
    v20 = *(_DWORD *)(v13 + 16);
    while ( 1 )
    {
      v16 = *(_DWORD **)(v14 + 4 * *v15);
      v26 = 0;
      v17 = v16[1];
      if ( a4 )
        break;
LABEL_28:
      ++v24;
      ++v15;
      if ( v24 >= a5 )
        return 1;
    }
    v28 = v15;
    while ( 1 )
    {
      v18 = *(_DWORD **)(*(_DWORD *)(this[2] + 20) + 4 * *v28);
      if ( v17 != v18[1] )
        return 0;
      if ( (*(_BYTE *)(*(_DWORD *)(v20 + 4 * v17) + 4) & 0x40) != 0 )
      {
        if ( v16[3] + (v26 >> 2) != v18[3] )
          return 0;
        v19 = v16[4] + (v26 & 3) == v18[4];
      }
      else
      {
        v19 = v16[18] == v18[18];
      }
      if ( !v19 )
        return 0;
      ++v26;
      v28 += a5;
      if ( v26 >= a4 )
        goto LABEL_28;
    }
  }
  return result;
}
