int __thiscall sub_6940BF(int this)
{
  bool v2; // zf
  int result; // eax
  void *v4; // eax
  int v5; // eax
  _DWORD *v6; // ecx
  unsigned int v7; // eax
  char *v8; // esi
  char *v9; // edi
  unsigned int v10; // eax
  char *v11; // edi
  char *v12; // esi
  char v13; // cl
  unsigned int v14; // eax
  bool v15; // cf
  unsigned int v16; // edx
  unsigned int v17; // eax
  int v18; // ecx
  unsigned int v19; // esi
  int v20; // eax
  int v21; // edx
  int v22; // eax
  unsigned int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // edx
  int *v27; // edx
  int v28; // edi
  void *v29[25]; // [esp+8h] [ebp-78h] BYREF
  unsigned int v30; // [esp+6Ch] [ebp-14h]
  int i; // [esp+70h] [ebp-10h]
  unsigned int v32; // [esp+74h] [ebp-Ch]
  int v33; // [esp+78h] [ebp-8h]
  void *Block; // [esp+7Ch] [ebp-4h]

  v2 = (*(_BYTE *)(this + 111) & 0xC) == 0;
  Block = 0;
  if ( v2 )
    return 1;
  result = sub_6825A9((_DWORD *)this);
  if ( result >= 0 )
  {
    if ( sub_68E047((char *)this, v29, *(_DWORD *)(this + 136), *(_DWORD *)(this + 44) - 1) >= 0
      && sub_68E712(this, (int)v29, 0) >= 0
      || (sub_685D67(v29), sub_68E047((char *)this, v29, *(_DWORD *)(this + 136), *(_DWORD *)(this + 44)) >= 0)
      && sub_68E712(this, (int)v29, 0) >= 0 )
    {
      v4 = operator new(4 * *(_DWORD *)(this + 12));
      Block = v4;
      if ( v4 )
      {
        qmemcpy(v4, *(const void **)(this + 24), 4 * *(_DWORD *)(this + 12));
        v32 = sub_684A43((_DWORD *)this);
        v5 = 0;
        v2 = *(_DWORD *)(this + 12) == 0;
        i = 0;
        if ( !v2 )
        {
          do
          {
            if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v5) + 44) & 1) != 0 )
            {
              v33 = v5;
              if ( v5 )
              {
                do
                {
                  if ( !sub_684AF5((_DWORD *)this, v33) )
                    break;
                  v7 = sub_684A43(v6);
                  v30 = v7;
                  if ( v7 <= v32
                    && (v7 != v32
                     || (*(_BYTE *)(this + 111) & 8) == 0
                     && *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v33) + 44) == *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v33 - 4) + 44))
                    && sub_68E712(this, (int)v29, 0) >= 0 )
                  {
                    v8 = *(char **)(this + 24);
                    v9 = (char *)Block;
                    v10 = 4 * i + 4;
                    qmemcpy(Block, v8, 4 * (v10 >> 2));
                    v12 = &v8[4 * (v10 >> 2)];
                    v11 = &v9[4 * (v10 >> 2)];
                    v13 = v10;
                    v14 = v30;
                    qmemcpy(v11, v12, v13 & 3);
                    v32 = v14;
                  }
                  --v33;
                }
                while ( v33 );
                v5 = i;
              }
              qmemcpy(*(void **)(this + 24), Block, 4 * v5 + 4);
            }
            v15 = (unsigned int)++v5 < *(_DWORD *)(this + 12);
            i = v5;
          }
          while ( v15 );
        }
        v16 = *(_DWORD *)(this + 12);
        v17 = 0;
        for ( i = 0; v17 < v16; i = v17 )
        {
          v18 = 4 * v17;
          if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v17) + 44) & 1) != 0 )
          {
            v19 = v17 + 1;
            if ( v17 + 1 < v16 )
            {
              v20 = *(_DWORD *)(this + 24);
              v21 = *(_DWORD *)(*(_DWORD *)(v20 + v18) + 44);
              v22 = v20 + 4 * v19;
              do
              {
                if ( v21 != *(_DWORD *)(*(_DWORD *)v22 + 44) )
                  break;
                ++v19;
                v22 += 4;
              }
              while ( v19 < *(_DWORD *)(this + 12) );
              v17 = i;
            }
            v23 = (v19 - v17) >> 1;
            if ( v23 )
            {
              i = v18;
              v24 = 4 * v19;
              v32 = v23;
              do
              {
                v25 = *(_DWORD *)(this + 24);
                v26 = i;
                i += 4;
                v27 = (int *)(v25 + v26);
                v28 = *v27;
                *v27 = *(_DWORD *)(v24 + v25 - 4);
                *(_DWORD *)(v24 + *(_DWORD *)(this + 24) - 4) = v28;
                v24 -= 4;
                --v32;
              }
              while ( v32 );
            }
            v17 = v19 - 1;
          }
          v16 = *(_DWORD *)(this + 12);
          ++v17;
        }
      }
    }
    sub_685D67(v29);
    j__free(Block);
    return 0;
  }
  return result;
}
