int __thiscall sub_6C3EEA(int this)
{
  int result; // eax
  int v3; // esi
  bool v4; // zf
  int v5; // edi
  size_t v6; // esi
  void *v7; // edi
  unsigned int v8; // edx
  unsigned int i; // ecx
  int v10; // eax
  int v11; // edi
  _DWORD *v12; // ecx
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  unsigned int v15; // edx
  int v16; // esi
  _DWORD *v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // edx
  int v21; // eax
  const void *v22; // esi
  void *v23[25]; // [esp+4h] [ebp-E8h] BYREF
  void *v24[25]; // [esp+68h] [ebp-84h] BYREF
  int v25; // [esp+CCh] [ebp-20h]
  BOOL v26; // [esp+D0h] [ebp-1Ch]
  BOOL v27; // [esp+D4h] [ebp-18h]
  int v28; // [esp+D8h] [ebp-14h]
  size_t v29; // [esp+DCh] [ebp-10h]
  void *Block; // [esp+E0h] [ebp-Ch]
  void *v31; // [esp+E4h] [ebp-8h]
  int j; // [esp+E8h] [ebp-4h]

  if ( (*(_BYTE *)(this + 204) & 4) != 0 )
    return 1;
  result = sub_6825A9((_DWORD *)this);
  if ( result >= 0 )
  {
    result = sub_6863CE((_DWORD *)this);
    if ( result >= 0 )
    {
      v3 = *(_DWORD *)(this + 12);
      v31 = 0;
      Block = 0;
      v26 = 0;
      v4 = (*(_BYTE *)(this + 111) & 0x10) == 0;
      memset(v24, 0, sizeof(v24));
      v28 = v3;
      memset(v23, 0, sizeof(v23));
      if ( v4 )
      {
        if ( *(_DWORD *)(this + 48) )
        {
          v5 = sub_68E047((char *)this, v23, *(_DWORD *)(this + 140), *(_DWORD *)(this + 48));
          if ( v5 < 0 )
            goto LABEL_47;
          v26 = sub_68E712(this, (int)v23, 0) >= 0;
        }
        if ( sub_68E047((char *)this, v24, *(_DWORD *)(this + 136), *(_DWORD *)(this + 44) - 1) < 0
          || sub_68E712(this, (int)v24, 0) < 0 )
        {
          sub_685D67(v24);
          v5 = sub_68E047((char *)this, v24, *(_DWORD *)(this + 136), *(_DWORD *)(this + 44));
          if ( v5 < 0 || (v5 = sub_68E712(this, (int)v24, 0), v5 < 0) )
          {
            if ( v5 != -2147024882 )
              v5 = 1;
            goto LABEL_47;
          }
        }
      }
      v6 = 4 * v3;
      v29 = v6;
      v31 = operator new(v6);
      if ( v31 && (v7 = operator new(v6), (Block = v7) != 0) )
      {
        qmemcpy(v7, *(const void **)(this + 24), v6);
        v8 = v28;
        qmemcpy(v31, *(const void **)(this + 24), v29);
        for ( i = 0; i < v8; ++i )
        {
          v10 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * i);
          *(_DWORD *)(this + 256) = v10;
          *(_DWORD *)(v10 + 36) = -1;
        }
        v11 = v8 - 1;
        for ( j = v8 - 1; j >= 0; v11 = --j )
        {
          v12 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v11);
          *(_DWORD *)(this + 256) = v12;
          if ( (*v12 & 0xFFF00000) != 0 && (*v12 & 0xF0000000) != 0x60000000 && !sub_680F76(v12) )
          {
            v13 = *(_DWORD **)(this + 256);
            if ( (*v13 & 0xFFF00000) != 0x11000000 )
            {
              sub_6BB9A9((int)Block, v13, v11);
              if ( (*(_BYTE *)(this + 112) & 8) == 0 )
              {
                v21 = sub_6C3DAD(this, (int)v24, (int)v23, (int)v31, (int)Block, v11, v26);
                goto LABEL_42;
              }
              v14 = *(_DWORD **)(this + 256);
              v15 = *v14 & 0xFFF00000;
              v28 = 0;
              v27 = v15 == 1342177280;
              if ( v14[3] )
              {
                v16 = *(_DWORD *)(this + 20);
                v17 = (_DWORD *)v14[4];
                v18 = (8 * *(_DWORD *)(this + 108)) >> 31;
                v25 = *(_DWORD *)(*(_DWORD *)(this + 256) + 12);
                do
                {
                  v19 = *(_DWORD *)(v16 + 4 * *v17);
                  if ( v18 || v24[0] != *(void **)(v19 + 4) )
                    v20 = *(_DWORD *)(v19 + 16);
                  else
                    v20 = *((_DWORD *)v24[5] + 4 * *(_DWORD *)(v19 + 12) + *(_DWORD *)(v19 + 16));
                  if ( v20 == 3 )
                    v28 = 1;
                  else
                    v27 = 1;
                  ++v17;
                  --v25;
                }
                while ( v25 );
              }
              if ( !v27 )
              {
                v21 = sub_6C3BB1(this, (int)v24, v31, (int)Block, j, 0, 1);
LABEL_42:
                v5 = v21;
                if ( v21 < 0 )
                  goto LABEL_47;
                if ( !v21 )
                {
                  v22 = *(const void **)(this + 24);
                  --j;
                  qmemcpy(v31, v22, v29);
                }
                continue;
              }
              if ( !v28 )
              {
                v21 = sub_6C3BB1(this, (int)v24, v31, (int)Block, j, 1, 0);
                goto LABEL_42;
              }
            }
          }
        }
        v5 = 0;
      }
      else
      {
        v5 = -2147024882;
      }
LABEL_47:
      if ( (*(_BYTE *)(this + 111) & 0x10) == 0 )
      {
        sub_685D67(v24);
        if ( *(_DWORD *)(this + 48) )
          sub_685D67(v23);
      }
      j__free(Block);
      j__free(v31);
      return v5;
    }
  }
  return result;
}
