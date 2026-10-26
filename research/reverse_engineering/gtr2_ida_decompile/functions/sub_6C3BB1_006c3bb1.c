int __thiscall sub_6C3BB1(int this, int a2, const void *a3, int a4, int a5, int a6, int a7)
{
  int v7; // edi
  int result; // eax
  _DWORD *v10; // esi
  _DWORD *v11; // esi
  int v12; // edx
  _DWORD *v13; // edx
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // eax
  _DWORD *v18; // esi
  int v19; // [esp+8h] [ebp-14h]
  int v20; // [esp+8h] [ebp-14h]
  int v21; // [esp+Ch] [ebp-10h]
  unsigned int v22; // [esp+10h] [ebp-Ch]
  int v23; // [esp+14h] [ebp-8h]
  int v24; // [esp+18h] [ebp-4h]

  v7 = a5;
  result = 1;
  v21 = 1;
  if ( !a5 )
    return result;
  v10 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * a5 - 4);
  if ( sub_680F76(v10) || (*v10 & 0xF0000000) == 0x60000000 || (*v10 & 0xFFF00000) == 0x11000000 )
    return 1;
  v22 = a5 - 1;
  if ( a5 - 1 < 0 )
    return v21;
  while ( 1 )
  {
    v11 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v22);
    if ( v11[9] != v7 && (*v11 & 0xFFF00000) != 0 )
    {
      if ( (*v11 & 0xF0000000) == 0x60000000 || (*v11 & 0xFFF00000) == 0x11000000 )
        return v21;
      sub_6BB9A9(a4, v11, v7);
      v23 = 0;
      v24 = (v12 & *v11) == 1342177280;
      if ( v11[3] )
      {
        v13 = (_DWORD *)v11[4];
        v19 = v11[3];
        do
        {
          v14 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v13);
          if ( (*(_DWORD *)(this + 108) & 0x10000000) != 0 )
            v15 = *(_DWORD *)(v14 + 16);
          else
            v15 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * (*(_DWORD *)(v14 + 16) + 4 * *(_DWORD *)(v14 + 12)));
          if ( v15 == 3 )
            v23 = 1;
          else
            v24 = 1;
          ++v13;
          --v19;
        }
        while ( v19 );
        v7 = a5;
      }
      if ( v24 != a6 && v23 != a7 )
        break;
    }
LABEL_34:
    if ( (--v22 & 0x80000000) != 0 )
      return v21;
  }
  result = sub_6C3B64((_DWORD *)this, v7 - 1, v22);
  v21 = result;
  if ( result < 0 )
    return result;
  if ( (*(_BYTE *)(this + 111) & 0x10) == 0 )
  {
    if ( sub_68E712(v16, a2, 0) < 0 )
      goto LABEL_33;
    v17 = v11[3];
    if ( v17 )
    {
      v18 = (_DWORD *)v11[4];
      v20 = v17;
      do
      {
        if ( *(_DWORD *)(*(_DWORD *)(a2 + 20)
                       + 4
                       * (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v18) + 16)
                        + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v18) + 12))) == 3 )
          v23 = 1;
        else
          v24 = 1;
        ++v18;
        --v20;
      }
      while ( v20 );
    }
    if ( v24 == a6 || v23 == a7 )
    {
LABEL_33:
      qmemcpy(*(void **)(this + 24), a3, 4 * *(_DWORD *)(this + 12));
      v7 = a5;
      goto LABEL_34;
    }
  }
  return 0;
}
