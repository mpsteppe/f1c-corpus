int __thiscall sub_66040C(_DWORD **this)
{
  int v2; // ebx
  _DWORD *i; // eax
  int v4; // ecx
  int j; // eax
  void *v6; // edi
  int v7; // edi
  char *v8; // ebx
  void *v9; // eax
  unsigned int v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned int v15; // ecx
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  _DWORD v19[10]; // [esp+Ch] [ebp-50h] BYREF
  _BYTE v20[16]; // [esp+34h] [ebp-28h] BYREF
  size_t Size; // [esp+44h] [ebp-18h]
  int v22; // [esp+48h] [ebp-14h] BYREF
  int k; // [esp+4Ch] [ebp-10h]
  void *Block; // [esp+50h] [ebp-Ch]
  void *v25; // [esp+54h] [ebp-8h]
  int v26; // [esp+58h] [ebp-4h]

  sub_6801F7(1196769860);
  memset(v19, 0, sizeof(v19));
  v2 = 0;
  v19[0] = 40;
  Block = 0;
  v25 = 0;
  v26 = sub_68024C(v19, 0x28u, 1, 0);
  if ( v26 >= 0 )
  {
    for ( i = this[13]; i; i = (_DWORD *)i[3] )
    {
      v4 = i[2];
      if ( v4 && *(_DWORD *)(v4 + 4) == 18 )
      {
        v2 = i[2];
        break;
      }
    }
    for ( j = v2; j; j = *(_DWORD *)(j + 12) )
      ++v19[5];
    if ( !v19[5] )
      goto LABEL_29;
    v6 = operator new(4 * v19[5]);
    Block = v6;
    if ( !v6 || (memset(v6, 0, 4 * v19[5]), (v25 = operator new(8 * v19[5])) == 0) )
    {
      v26 = -2147024882;
      goto LABEL_44;
    }
    Size = 8 * v19[5];
    memset(v25, 0, 8 * v19[5]);
    v7 = v2;
    if ( v2 )
    {
      v8 = (char *)v25 + 8 * v19[5] - 6;
      do
      {
        *(_WORD *)v8 = -1;
        *((_WORD *)v8 - 1) = *(_WORD *)(v7 + 36);
        *(_DWORD *)(v8 + 2) = *(_DWORD *)(v7 + 88);
        v9 = *(void **)(v7 + 32);
        if ( v9 )
        {
          if ( sub_68024C(v9, 0xFFFFFFFF, 7, (int)&v22) < 0 )
            goto LABEL_44;
          v10 = 0;
          for ( k = 0; v10 < v19[3]; k = ++v10 )
          {
            if ( *((_DWORD *)Block + v10) == v22 )
              break;
          }
          if ( v10 == v19[3] )
          {
            *((_DWORD *)Block + v19[3]++) = v22;
            LOWORD(v10) = k;
          }
          *(_WORD *)v8 = v10;
        }
        v7 = *(_DWORD *)(v7 + 12);
        v8 -= 8;
      }
      while ( v7 );
    }
    if ( !v19[3] || (v26 = sub_68024C(Block, 4 * v19[3], 1, (int)&v19[4]), v26 >= 0) )
    {
      v26 = sub_68024C(v25, Size, 1, (int)&v19[6]);
      if ( v26 >= 0 )
      {
LABEL_29:
        v11 = this[29];
        if ( !v11 || (v26 = sub_68024C(v11, 0xFFFFFFFF, 7, (int)&v19[9]), v26 >= 0) )
        {
          v12 = this[27];
          if ( (!v12
             || sub_68024C(v12, (size_t)this[28], 5, (int)&v19[2]) >= 0 && sub_68024C((void *)WindowName, 1u, 5, 0) >= 0)
            && sub_68024C("Microsoft (R) D3DX9 Shader Assembler 5.04.00.2904", 0xFFFFFFFF, 5, (int)&v19[1]) >= 0 )
          {
            v13 = sub_680385(v20);
            v14 = v13;
            if ( v13 > 0x8000 )
            {
              sub_65DDE6(
                *this,
                (int)(this + 4),
                (const char *)0x7EE,
                "debug info exceeds maximum comment size; no debug info emitted");
              goto LABEL_43;
            }
            v26 = sub_65F877((int)this, v13);
            if ( v26 >= 0 )
            {
              memcpy(&this[22][v14 + 1], this[22] + 1, 4 * (_DWORD)this[23] - 4);
              v15 = 0;
              if ( v19[5] )
              {
                v16 = (char *)v25 + 4;
                do
                {
                  *v16 += 4 * ((_DWORD)this[26] + v14);
                  ++v15;
                  v16 += 2;
                }
                while ( v15 < v19[5] );
              }
              v26 = sub_680391(this[22] + 1, v14);
              if ( v26 >= 0 )
              {
                this[23] = (_DWORD *)((char *)this[23] + v14);
                v17 = this[23];
                this[26] = (_DWORD *)((char *)this[26] + v14);
                this[25] = v17;
LABEL_43:
                v26 = 0;
              }
            }
          }
        }
      }
    }
  }
LABEL_44:
  j__free(Block);
  j__free(v25);
  sub_680214(v20);
  return v26;
}
