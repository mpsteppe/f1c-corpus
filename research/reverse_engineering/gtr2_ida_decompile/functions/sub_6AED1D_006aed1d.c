int __thiscall sub_6AED1D(_DWORD *this, _DWORD *Block, unsigned int *a3)
{
  _DWORD *v3; // ebx
  _DWORD *v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // edx
  bool v8; // zf
  unsigned int v9; // edi
  const char **v10; // eax
  int result; // eax
  int v12; // eax
  int v13; // edi
  _DWORD *v14; // eax
  int v15; // edi
  unsigned int v16; // eax
  int v17; // edi
  int v18; // ecx
  _DWORD *v19; // eax
  int v20; // edx
  unsigned int i; // ecx
  int v22; // eax
  int v23; // [esp-8h] [ebp-44h]
  int v24; // [esp-4h] [ebp-40h]
  char v25[16]; // [esp+Ch] [ebp-30h] BYREF
  _DWORD v26[3]; // [esp+1Ch] [ebp-20h] BYREF
  int v27; // [esp+28h] [ebp-14h]
  unsigned int v28; // [esp+2Ch] [ebp-10h]
  int v29; // [esp+30h] [ebp-Ch]
  int v30; // [esp+34h] [ebp-8h]
  int v31; // [esp+38h] [ebp-4h]

  v3 = Block;
  v5 = (_DWORD *)(*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, Block[27]);
  v24 = v3[27];
  Block = v5;
  v6 = (*(int (__thiscall **)(_DWORD *, int))(*this + 88))(this, v24);
  v7 = 0;
  v8 = this[86] == 0;
  v9 = v6;
  v28 = v6;
  if ( !v8 )
  {
    if ( v3[27] != -1 )
    {
      if ( Block != (_DWORD *)0xFFFF )
      {
        v10 = (const char **)sub_6CA49D(Block);
        sub_632041((int)v25, 32, "v_%s%d", *v10, v9);
        v23 = v3[3];
        HIBYTE(v27) = 0;
        result = sub_66078B(this + 117, v25, v23, 1);
        if ( result < 0 )
          return result;
        ++this[124];
        if ( (this[51] & 1) != 0 )
        {
          v12 = v3[24];
          if ( v12 )
          {
            if ( *(_DWORD *)(v12 + 4) == 6 )
            {
              v13 = *(_DWORD *)(v12 + 20);
              if ( *(_DWORD *)(v13 + 4) == 3 )
              {
                v14 = operator new(strlen(*(const char **)(v13 + 24)) + 3);
                Block = v14;
                if ( !v14 )
                  return -2147024882;
                sprintf((char *const)v14, "n_%s", *(const char **)(v13 + 24));
                v15 = sub_66078B(this + 117, (char *)Block, v3[3], 1);
                j__free(Block);
                if ( v15 < 0 )
                  return v15;
                ++this[124];
              }
            }
          }
        }
      }
      if ( a3 )
        *a3 = v3[27];
    }
    return 0;
  }
  if ( Block == (_DWORD *)11 )
  {
    if ( v6 < this[10] )
    {
      *a3 = v6;
      v16 = this[v6 + 134];
      v31 = 1;
      goto LABEL_22;
    }
    return -2147467259;
  }
  if ( Block != (_DWORD *)6 || v6 >= 8 )
    return -2147467259;
  *a3 = v6 + 2;
  v16 = this[v6 + 126];
  v31 = 3;
LABEL_22:
  a3 = 0;
  if ( v16 )
  {
    do
    {
      if ( v7 )
      {
        switch ( v7 )
        {
          case 1u:
            BYTE2(a3) |= 2u;
            break;
          case 2u:
            BYTE2(a3) |= 4u;
            break;
          case 3u:
            BYTE2(a3) |= 8u;
            break;
        }
      }
      else
      {
        BYTE2(a3) |= 1u;
      }
      ++v7;
    }
    while ( v7 < v16 );
  }
  if ( v31 != 1 && ((this[51] & 0x20) != 0 || Block == (_DWORD *)6 && (*((_BYTE *)v3 + 3) & 2) != 0) )
    BYTE2(a3) |= 0x20u;
  v30 = 0;
  if ( (*((_BYTE *)v3 + 3) & 1) != 0 )
    v30 = 0x400000;
  result = sub_6CB0CE(&byte_200001F);
  if ( result >= 0 )
  {
    result = sub_6C9357(0x80000000);
    if ( result >= 0 )
    {
      if ( (this[51] & 1) != 0 )
      {
        v29 = 0;
        Block = 0;
        v8 = this[2] == 0;
        memset(v26, 255, sizeof(v26));
        v27 = -1;
        if ( !v8 )
        {
          v17 = v3[1];
          v18 = this[5];
          do
          {
            v19 = *(_DWORD **)v18;
            if ( v17 == *(_DWORD *)(*(_DWORD *)v18 + 4) && v3[2] == v19[2] && v3[3] == v19[3] )
              v26[v19[4]] = Block;
            Block = (_DWORD *)((char *)Block + 1);
            v18 += 4;
          }
          while ( (unsigned int)Block < this[2] );
        }
        v20 = v29;
        for ( i = 0; i < 4; ++i )
        {
          v22 = v26[i];
          if ( v22 != -1 )
            v26[v20++] = v22;
        }
        result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, _DWORD **, int))(*this + 112))(
                   this,
                   v26,
                   v20,
                   &Block,
                   1);
        if ( result < 0 )
          return result;
        LOWORD(v9) = v28;
      }
      result = (*(int (__thiscall **)(_DWORD *, unsigned int, unsigned int *, _DWORD))(*this + 100))(
                 this,
                 v30 | v9 & 0x7FF | ((v31 & 0x18 | ((v31 | 0xFFFFFFF8) << 20)) << 8),
                 a3,
                 0);
      if ( result >= 0 )
      {
        result = sub_6C64E6(this);
        if ( result >= 0 )
          return 0;
      }
    }
  }
  return result;
}
