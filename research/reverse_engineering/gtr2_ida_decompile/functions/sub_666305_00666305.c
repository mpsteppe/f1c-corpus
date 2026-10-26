int __thiscall sub_666305(_DWORD *this, unsigned int a2, void *a3, char *a4, char *a5, _DWORD *a6, unsigned int a7)
{
  int v8; // eax
  unsigned int i; // edx
  int v11; // ecx
  char *v12; // ecx
  unsigned int v13; // eax
  _DWORD *v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // esi
  int v18; // edi
  int v19; // eax
  char *v20; // ecx
  unsigned int j; // eax
  int v22; // edi
  char *v24; // edx
  unsigned int k; // eax
  unsigned int m; // eax
  int v27; // edi
  int v28; // edi
  _DWORD *v29; // [esp+Ch] [ebp-18h]
  _DWORD *v30; // [esp+10h] [ebp-14h]
  _DWORD *v31; // [esp+14h] [ebp-10h]
  _BYTE *v32; // [esp+18h] [ebp-Ch]
  _BYTE *v33; // [esp+1Ch] [ebp-8h]
  void *Block; // [esp+20h] [ebp-4h]
  unsigned int v35; // [esp+34h] [ebp+10h]
  int v36; // [esp+38h] [ebp+14h]
  int v37; // [esp+40h] [ebp+1Ch]
  int v38; // [esp+40h] [ebp+1Ch]

  v8 = this[2];
  Block = *(void **)(v8 + 108);
  if ( (char)Block < 0 )
  {
    for ( i = 0; i < a7; ++i )
    {
      v11 = a6[i];
      if ( (**(_BYTE **)(*(_DWORD *)(v8 + 20) + 4 * v11) & 1) == 0 || ((unsigned __int8)Block & 4) != 0 && v11 != *a6 )
        break;
    }
    if ( i == a7 )
    {
      v12 = (char *)operator new(12 * a7);
      Block = v12;
      if ( v12 )
      {
        v13 = 0;
        v37 = 4 * a7;
        do
        {
          (&v31)[v13++] = v12;
          v12 += 4 * a7;
        }
        while ( v13 < 3 );
        if ( a7 )
        {
          v14 = v32;
          v36 = a5 - v32;
          v15 = a4 - v32;
          v16 = v33 - v32;
          v35 = a7;
          do
          {
            *v14 = *(_DWORD *)((char *)v14 + v15);
            *(_DWORD *)((char *)v14 + v16) = *(_DWORD *)((char *)v14 + v36);
            ++v14;
            --v35;
          }
          while ( v35 );
        }
        v17 = sub_6624CC(v31, a7);
        if ( v17 >= 0 )
        {
          v17 = sub_6624CC(a3, a7);
          if ( v17 >= 0 )
          {
            v18 = a7 & 0xFFFFF;
            v17 = sub_6641F3(this, a2, v18 | 0x10100000, (int)v31, a6, 0x1A00000000LL);
            if ( v17 >= 0 )
            {
              v19 = sub_6641F3(this, a2, v18 | 0x30000000, (int)a3, v31, (unsigned int)Block + v37);
              goto LABEL_30;
            }
          }
        }
        goto LABEL_32;
      }
LABEL_34:
      v17 = -2147024882;
      goto LABEL_32;
    }
  }
  if ( (HIBYTE(Block) & 2) == 0 )
  {
    Block = operator new(12 * a7);
    if ( Block )
    {
      v20 = (char *)Block;
      for ( j = 0; j < 3; ++j )
      {
        (&v31)[j] = v20;
        v20 += 4 * a7;
      }
      v17 = sub_6624CC(v31, a7);
      if ( v17 < 0 )
        goto LABEL_32;
      v17 = sub_6624CC(v32, a7);
      if ( v17 < 0 )
        goto LABEL_32;
      v17 = sub_6624CC(v33, a7);
      if ( v17 < 0 )
        goto LABEL_32;
      v17 = sub_6624CC(a3, a7);
      if ( v17 < 0 )
        goto LABEL_32;
      v22 = a7 & 0xFFFFF;
      v17 = sub_6641F3(this, a2, a7 & 0xFFFFF | 0x10100000, (int)v31, a4, 0);
      if ( v17 < 0 )
        goto LABEL_32;
      v17 = sub_6641F3(this, a2, v22 | 0x20400000, (int)v32, a5, (unsigned int)v31);
      if ( v17 < 0 )
        goto LABEL_32;
      v17 = sub_6641F3(this, a2, v22 | 0x20500000, (int)v33, a6, (unsigned int)v32);
      if ( v17 < 0 )
        goto LABEL_32;
      v19 = sub_6641F3(this, a2, v22 | 0x20400000, (int)a3, a4, (unsigned int)v33);
      goto LABEL_30;
    }
    goto LABEL_34;
  }
  Block = operator new(20 * a7);
  if ( !Block )
    goto LABEL_34;
  v24 = (char *)Block;
  for ( k = 0; k < 5; ++k )
  {
    (&v29)[k] = v24;
    v24 += 4 * a7;
  }
  for ( m = 0; m < a7; ++m )
    *(_DWORD *)&v33[4 * m] = this[8];
  v17 = sub_6624CC(v29, a7);
  if ( v17 >= 0 )
  {
    v17 = sub_6624CC(v30, a7);
    if ( v17 >= 0 )
    {
      v17 = sub_6624CC(v31, a7);
      if ( v17 >= 0 )
      {
        v17 = sub_6624CC(v32, a7);
        if ( v17 >= 0 )
        {
          v17 = sub_6624CC(a3, a7);
          if ( v17 >= 0 )
          {
            v27 = a7 & 0xFFFFF;
            v17 = sub_6641F3(this, a2, a7 & 0xFFFFF | 0x10100000, (int)v29, a6, 0);
            if ( v17 >= 0 )
            {
              v38 = v27 | 0x20400000;
              v17 = sub_6641F3(this, a2, v27 | 0x20400000, (int)v30, v29, (unsigned int)v33);
              if ( v17 >= 0 )
              {
                v28 = v27 | 0x20500000;
                v17 = sub_6641F3(this, a2, v28, (int)v31, v30, (unsigned int)a4);
                if ( v17 >= 0 )
                {
                  v17 = sub_6641F3(this, a2, v28, (int)v32, a6, (unsigned int)a5);
                  if ( v17 >= 0 )
                  {
                    v19 = sub_6641F3(this, a2, v38, (int)a3, v31, (unsigned int)v32);
LABEL_30:
                    v17 = v19;
                    if ( v19 >= 0 )
                      v17 = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_32:
  j__free(Block);
  return v17;
}
