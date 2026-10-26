int __thiscall sub_66353F(_DWORD *this, _DWORD *a2, int a3, unsigned int a4, unsigned int a5)
{
  int result; // eax
  int v6; // eax
  _DWORD *v7; // edi
  _DWORD *v8; // eax
  int v9; // esi
  _DWORD *v10; // edx
  bool v11; // zf
  int v12; // eax
  _DWORD *v13; // ebx
  _DWORD *v14; // edx
  int v15; // edi
  _DWORD *v16; // esi
  bool v17; // zf
  int v18; // [esp+4h] [ebp-14h]
  int v19; // [esp+8h] [ebp-10h]
  unsigned int v20; // [esp+10h] [ebp-8h]
  unsigned int v21; // [esp+10h] [ebp-8h]
  _DWORD *v22; // [esp+14h] [ebp-4h]
  unsigned int v23; // [esp+20h] [ebp+8h]
  unsigned int v24; // [esp+24h] [ebp+Ch]
  _DWORD *v25; // [esp+24h] [ebp+Ch]

  if ( a3 != 2 )
    return a4 == 1;
  result = a5 * a4;
  if ( a5 * a4 )
  {
    v20 = 0;
    if ( a5 )
    {
      v6 = this[2];
      v7 = a2;
      v19 = *(_DWORD *)(v6 + 20);
      v18 = *(_DWORD *)(v6 + 16);
      while ( 1 )
      {
        v8 = *(_DWORD **)(v19 + 4 * *v7);
        v9 = v8[1];
        v24 = 0;
        if ( a4 )
          break;
LABEL_15:
        ++v20;
        ++v7;
        if ( v20 >= a5 )
          goto LABEL_16;
      }
      v22 = v7;
      while ( 1 )
      {
        v10 = *(_DWORD **)(*(_DWORD *)(this[2] + 20) + 4 * *v22);
        if ( v9 != v10[1] )
          return 1;
        if ( (*(_BYTE *)(*(_DWORD *)(v18 + 4 * v9) + 4) & 0x40) != 0 )
        {
          if ( v8[3] + (v24 >> 2) != v10[3] )
            return 1;
          v11 = v8[4] + (v24 & 3) == v10[4];
        }
        else
        {
          v11 = v8[18] == v10[18];
        }
        if ( !v11 )
          return 1;
        ++v24;
        v22 += a5;
        if ( v24 >= a4 )
          goto LABEL_15;
      }
    }
LABEL_16:
    v21 = 0;
    if ( !a4 )
      return 1;
    v12 = this[2];
    v13 = a2;
    while ( 1 )
    {
      v14 = *(_DWORD **)(*(_DWORD *)(v12 + 20) + 4 * *v13);
      v23 = 0;
      v15 = v14[1];
      if ( a5 )
        break;
LABEL_27:
      ++v21;
      v13 += a5;
      if ( v21 >= a4 )
        return 1;
    }
    v25 = v13;
    while ( 1 )
    {
      v16 = *(_DWORD **)(*(_DWORD *)(this[2] + 20) + 4 * *v25);
      if ( v15 != v16[1] )
        return 0;
      if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v12 + 16) + 4 * v15) + 4) & 0x40) != 0 )
      {
        if ( v14[3] + (v23 >> 2) != v16[3] )
          return 0;
        v17 = v14[4] + (v23 & 3) == v16[4];
      }
      else
      {
        v17 = v14[18] == v16[18];
      }
      if ( !v17 )
        return 0;
      ++v23;
      ++v25;
      if ( v23 >= a5 )
        goto LABEL_27;
    }
  }
  return result;
}
