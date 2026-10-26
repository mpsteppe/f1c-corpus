int __thiscall sub_666C0F(_DWORD *this, unsigned int a2, void *a3, void *a4, unsigned int a5, unsigned int a6)
{
  bool v6; // zf
  void *v8; // ebx
  int v9; // edi
  unsigned int v10; // eax
  _DWORD *v11; // ecx
  unsigned int v13; // ecx
  int v14; // esi
  int v15; // eax
  void *v16; // edi
  _DWORD *v17; // esi
  _DWORD *v19; // ecx
  unsigned int v20; // eax
  int v21; // edx
  _DWORD *v22; // esi
  unsigned int i; // eax
  unsigned int j; // ecx
  _DWORD *v25; // eax
  int v27; // [esp+Ch] [ebp-18h]
  _DWORD *v28; // [esp+10h] [ebp-14h]
  _DWORD *v29; // [esp+14h] [ebp-10h]
  void *Block; // [esp+18h] [ebp-Ch]
  int v31; // [esp+1Ch] [ebp-8h]
  _DWORD *v32; // [esp+20h] [ebp-4h]
  int v33; // [esp+38h] [ebp+14h]
  unsigned int v34; // [esp+3Ch] [ebp+18h]

  v6 = (*(_BYTE *)(this[2] + 113) & 0x10) == 0;
  v32 = this;
  if ( v6 )
  {
    v8 = operator new(8 * a6);
    Block = v8;
    if ( v8 )
    {
      v9 = sub_6624CC(v8, 2 * a6);
      if ( v9 >= 0 )
      {
        v10 = 0;
        v34 = 4 * a6;
        v11 = v8;
        do
        {
          *(&v27 + v10++) = (int)v11;
          v11 += a6;
        }
        while ( v10 < 2 );
        v13 = 0;
        v31 = 4;
        if ( !a6 )
          goto LABEL_10;
        v33 = *(_DWORD *)(v32[2] + 20);
        do
          v31 = **(_BYTE **)(v33 + 4 * *(_DWORD *)(a5 + 4 * v13++)) & 4 & (unsigned __int8)v31;
        while ( v13 < a6 );
        if ( !v31 )
        {
          v14 = a6 & 0xFFFFF;
          v15 = sub_6641F3(v32, a2, v14 | 0x20500000, v27, (_DWORD *)a5, a5 | 0x400000000LL);
        }
        else
        {
LABEL_10:
          v14 = a6 & 0xFFFFF;
          v15 = sub_6641F3(v32, a2, v14 | 0x10000000, v27, (_DWORD *)a5, 0x400000000LL);
        }
        v9 = v15;
        if ( v15 >= 0 )
        {
          v9 = sub_6641F3(v32, a2, v14 | 0x10100000, (int)v28, (_DWORD *)v27, 0x800000000LL);
          if ( v9 >= 0 )
          {
            if ( a3 )
              qmemcpy(a3, (const void *)v27, v34);
            v16 = a4;
            if ( !a4 )
              goto LABEL_37;
            v17 = v28;
LABEL_36:
            qmemcpy(v16, v17, v34);
LABEL_37:
            v9 = 0;
            goto LABEL_38;
          }
        }
      }
      goto LABEL_38;
    }
LABEL_19:
    v9 = -2147024882;
    goto LABEL_38;
  }
  Block = operator new(12 * a6);
  if ( !Block )
    goto LABEL_19;
  v9 = sub_6624CC(Block, 3 * a6);
  if ( v9 >= 0 )
  {
    v19 = Block;
    v20 = 0;
    v21 = 4 * a6;
    v34 = 4 * a6;
    do
    {
      *(&v27 + v20++) = (int)v19;
      v19 = (_DWORD *)((char *)v19 + v21);
    }
    while ( v20 < 3 );
    v31 = a6 & 0xFFFFF | 0x10100000;
    v9 = sub_6641F3(v32, a2, v31, v27, (_DWORD *)a5, 0);
    if ( v9 >= 0 )
    {
      v22 = v32;
      v9 = sub_6641F3(v32, a2, a6 & 0xFFFFF | 0x20100000, (int)v28, (_DWORD *)a5, (unsigned int)v27 | 0x400000000LL);
      if ( v9 >= 0 )
      {
        v9 = sub_6641F3(v22, a2, v31, (int)v29, v28, 0x800000000LL);
        if ( v9 >= 0 )
        {
          for ( i = 0; i < a6; ++i )
          {
            if ( (**(_BYTE **)(*(_DWORD *)(v22[2] + 20) + 4 * *(_DWORD *)(a5 + 4 * i)) & 0x17) == 0 )
              break;
          }
          if ( i == a6 )
          {
            for ( j = 0; j < a6; ++j )
            {
              v25 = *(_DWORD **)(*(_DWORD *)(v22[2] + 20) + 4 * v28[j]);
              *v25 |= 0x17u;
            }
          }
          if ( a3 )
            qmemcpy(a3, v28, v34);
          v16 = a4;
          if ( !a4 )
            goto LABEL_37;
          v17 = v29;
          goto LABEL_36;
        }
      }
    }
  }
LABEL_38:
  j__free(Block);
  return v9;
}
