int __thiscall sub_6A2AAC(int this)
{
  _DWORD *v2; // edi
  int v4; // eax
  int v5; // ecx
  int v6; // esi
  int v7; // eax
  int v8; // edi
  _DWORD *v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // eax
  char *v13; // edx
  int i; // ecx
  void *v15; // ecx
  int v16; // [esp+18h] [ebp-Ch]
  _DWORD *v17; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+1Ch] [ebp-8h]
  BOOL v19; // [esp+20h] [ebp-4h]
  char *v20; // [esp+20h] [ebp-4h]

  v2 = *(_DWORD **)(this + 256);
  if ( (*v2 & 0xFFF00000) != 0x10100000 )
    return 0;
  v4 = *(_DWORD *)(this + 256);
  v5 = *(_DWORD *)(this + 20);
  v6 = *(_DWORD *)v4 & 0xFFFFF;
  v19 = (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16)
                               + 4 * *(_DWORD *)(*(_DWORD *)(v5 + 4 * **(_DWORD **)(v4 + 8)) + 4))
                   + 4)
       & 0x200) != 0;
  if ( (*(_BYTE *)(this + 110) & 2) != 0 && v6 )
  {
    v17 = (_DWORD *)v2[2];
    v16 = *(_DWORD *)v4 & 0xFFFFF;
    do
    {
      v7 = *(_DWORD *)(v5 + 4 * *v17);
      if ( (*(_DWORD *)(v7 + 60) & 0x200) != 0 )
        v19 = 1;
      v8 = *(_DWORD *)(v7 + 56);
      if ( v8 != -1 )
        v7 = *(_DWORD *)(v5 + 4 * v8);
      if ( (*(_DWORD *)(v7 + 60) & 0x200) != 0 )
        v19 = 1;
      ++v17;
      --v16;
    }
    while ( v16 );
  }
  if ( !v19 )
    return 0;
  v9 = (_DWORD *)sub_681186(116);
  if ( v9 )
    v20 = (char *)sub_680CEC(v9);
  else
    v20 = 0;
  if ( !v20 )
    return -2147024882;
  v10 = sub_6811D1(v20, v6 & 0xFFFFF | 0x20500000, 2 * v6, v6, 0);
  if ( v10 >= 0 )
  {
    v10 = sub_680D22(v20, *(_DWORD *)(this + 256));
    if ( v10 >= 0 )
    {
      v11 = sub_681A51((void *)this, (int)"c", 785, 1, 4);
      if ( v11 == -1 || (v18 = sub_681AAA((void *)this, v11, 0, 0, -1.0), v18 == -1) )
      {
        v10 = -2147024882;
      }
      else
      {
        v12 = 4 * v6;
        qmemcpy(*((void **)v20 + 2), *(const void **)(*(_DWORD *)(this + 256) + 8), 4 * v6);
        v13 = v20;
        qmemcpy(*((void **)v20 + 4), *(const void **)(*(_DWORD *)(this + 256) + 16), 4 * v6);
        for ( i = v6; i; --i )
        {
          *(_DWORD *)(v12 + *((_DWORD *)v20 + 2)) = v18;
          v12 += 4;
        }
        v15 = *(void **)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(this + 252));
        v10 = 0;
        if ( v15 )
        {
          sub_66238F(v15, 1);
          v13 = v20;
        }
        *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(this + 252)) = v13;
        v20 = 0;
      }
    }
  }
  if ( v20 )
    sub_66238F(v20, 1);
  return v10;
}
