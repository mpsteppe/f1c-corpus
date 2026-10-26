int __thiscall sub_6BC65D(int this)
{
  unsigned int v2; // edi
  int v4; // eax
  _DWORD *v5; // ecx
  _DWORD *v6; // eax
  int v7; // edx
  _DWORD *v8; // ecx
  _DWORD *v9; // edx
  unsigned int v10; // eax
  int v11; // ebx
  int v12; // edi
  int v13; // [esp+8h] [ebp-18h]
  unsigned int v14; // [esp+8h] [ebp-18h]
  unsigned int v15; // [esp+Ch] [ebp-14h]
  unsigned int v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  _DWORD *v18; // [esp+18h] [ebp-8h]
  unsigned int v19; // [esp+18h] [ebp-8h]
  unsigned int v20; // [esp+1Ch] [ebp-4h]
  int v21; // [esp+1Ch] [ebp-4h]

  v2 = **(_DWORD **)(this + 256) & 0xFFFFF;
  v15 = v2;
  if ( (**(_DWORD **)(this + 256) & 0xFFF00000) != 0x20800000 )
    return 1;
  v13 = 0;
  v16 = 0;
  v17 = 0;
  while ( 1 )
  {
    v20 = 0;
    if ( v2 )
    {
      v4 = *(_DWORD *)(this + 256);
      v5 = *(_DWORD **)(v4 + 16);
      v6 = (_DWORD *)(v17 + *(_DWORD *)(v4 + 8));
      v18 = v5;
      do
      {
        v7 = *(_DWORD *)(this + 20);
        v8 = *(_DWORD **)(v7 + 4 * *v18);
        v9 = *(_DWORD **)(v7 + 4 * *v6);
        if ( v9[1] != v8[1] )
          break;
        if ( v9[2] != v8[2] )
          break;
        if ( v9[3] != v8[3] )
          break;
        if ( v9[4] != v8[4] )
          break;
        ++v20;
        ++v18;
        ++v6;
      }
      while ( v20 < v2 );
    }
    if ( v20 == v2 )
      goto LABEL_23;
    v10 = sub_681B0A((void *)this, v2 & 0xFFFFF | 0x10000000, v2, v2);
    v14 = v10;
    if ( v10 == -1 )
      return -2147024882;
    v19 = 0;
    v11 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v10);
    if ( v2 )
      break;
LABEL_18:
    while ( v10 > *(_DWORD *)(this + 252)
         || v10 && (**(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v10 - 4) & 0xFFF00000) == 0x20800000 )
    {
      *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v10) = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v10 - 4);
      --v10;
    }
    *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v10) = v11;
    ++*(_DWORD *)(this + 252);
    v13 = 1;
LABEL_23:
    ++v16;
    v17 += 4 * v2;
    if ( v16 >= 2 )
      return v13 == 0;
  }
  v21 = v17;
  while ( 1 )
  {
    v12 = 4 * v19;
    *(_DWORD *)(4 * v19 + *(_DWORD *)(v11 + 8)) = *(_DWORD *)(v21 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8));
    *(_DWORD *)(v21 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8)) = sub_681BB1(
                                                                    (void *)this,
                                                                    *(_DWORD *)(*(_DWORD *)(this + 20)
                                                                              + 4
                                                                              * *(_DWORD *)(4 * v19
                                                                                          + *(_DWORD *)(*(_DWORD *)(this + 256) + 16))));
    *(_DWORD *)(4 * v19 + *(_DWORD *)(v11 + 16)) = *(_DWORD *)(v21 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8));
    if ( *(_DWORD *)(4 * v19 + *(_DWORD *)(v11 + 16)) == -1 )
      return -2147024882;
    ++v19;
    v21 += 4;
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(v12 + *(_DWORD *)(v11 + 16))) + 20) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(v12 + *(_DWORD *)(v11 + 8))) + 20);
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(v12 + *(_DWORD *)(v11 + 16))) + 24) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(v12 + *(_DWORD *)(v11 + 8))) + 24);
    if ( v19 >= v15 )
    {
      v10 = v14;
      v2 = v15;
      goto LABEL_18;
    }
  }
}
