int __thiscall sub_6872BA(_DWORD *this)
{
  unsigned int v1; // ebx
  _DWORD *v3; // edi
  int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // edx
  int *v9; // edi
  int v10; // eax
  _DWORD *v11; // ecx
  unsigned int v12; // edx
  _DWORD *v13; // edx
  int v14; // eax
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  _DWORD *v18; // edi
  unsigned int v19; // ecx
  unsigned int v20; // eax
  _DWORD *v21; // edx
  unsigned int v22; // edx
  int *v23; // eax
  int *v24; // [esp+14h] [ebp-24h]
  unsigned int v25; // [esp+18h] [ebp-20h]
  int *v26; // [esp+1Ch] [ebp-1Ch]
  int v27; // [esp+20h] [ebp-18h]
  _DWORD *v28; // [esp+20h] [ebp-18h]
  unsigned int v29; // [esp+24h] [ebp-14h]
  unsigned int v30; // [esp+28h] [ebp-10h]
  _DWORD *v31; // [esp+28h] [ebp-10h]
  int *Block; // [esp+2Ch] [ebp-Ch]
  unsigned int v33; // [esp+30h] [ebp-8h]
  int v34; // [esp+34h] [ebp-4h]
  unsigned int i; // [esp+34h] [ebp-4h]

  v1 = 0;
  Block = 0;
  sub_686074((int)this);
  v34 = 0;
  if ( this[2] )
  {
    do
    {
      v3 = *(_DWORD **)(this[5] + 4 * v1);
      if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v3[1]) + 4) & 0x20) != 0 )
      {
        v4 = sub_681AAA(this, this[34], 0, 0, 0.0);
        v3[12] = v4;
        if ( v4 == -1 )
          goto LABEL_43;
        ++v34;
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v4) + 20) = v3[5];
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v3[12]) + 24) = v3[6];
      }
      else
      {
        v3[12] = v1;
      }
      ++v1;
    }
    while ( v1 < this[2] );
    if ( !v34 )
      goto LABEL_14;
    sub_68661F(this);
    Block = (int *)operator new(4 * v34);
    if ( Block )
    {
      v5 = 0;
      for ( i = 0; v5 < this[2]; ++v5 )
      {
        if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v5) + 4)) + 4) & 0x20) != 0 )
        {
          v6 = i++;
          Block[v6] = v5;
        }
      }
      sub_682274(sub_681EA6, Block, i, (int)this);
      v7 = 0;
      v29 = 0;
      if ( !i )
        goto LABEL_14;
      while ( 1 )
      {
        v9 = &Block[v7];
        v10 = this[5];
        v11 = *(_DWORD **)(v10 + 4 * *v9);
        v12 = v7 + 1;
        v24 = v9;
        v33 = 1;
        if ( v12 < i )
        {
          v30 = v12;
          v28 = v9 + 1;
          do
          {
            v13 = *(_DWORD **)(v10 + 4 * *v28);
            if ( v11[1] != v13[1] )
              break;
            if ( v11[2] != v13[2] )
              break;
            if ( v11[3] != v13[3] )
              break;
            ++v33;
            ++v30;
            ++v28;
          }
          while ( v30 < i );
        }
        v14 = sub_681B0A(this, v33 & 0xFFFFF | 0x10000000, -1, -1);
        if ( v14 == -1 )
          break;
        v25 = 0;
        v31 = *(_DWORD **)(this[6] + 4 * v14);
        if ( v33 )
        {
          v26 = v9;
          while ( 1 )
          {
            v15 = *(_DWORD *)(this[5] + 4 * *v26);
            v16 = *(_DWORD *)(v15 + 48);
            v17 = *(_DWORD *)(v15 + 72);
            if ( v17 != -1 )
              break;
LABEL_36:
            if ( !v31[15] )
            {
              ++v25;
              ++v26;
              if ( v25 < v33 )
                continue;
            }
            goto LABEL_38;
          }
          while ( 1 )
          {
            v18 = *(_DWORD **)(this[6] + 4 * v17);
            if ( v18[15] )
            {
              v27 = sub_680D22(v31, (int)v18);
              if ( v27 < 0 )
                goto LABEL_15;
            }
            if ( (*v18 & 0xFFF00000) == 0x10000000 )
            {
              v19 = v18[3];
              v20 = 0;
              if ( v19 )
              {
                v21 = (_DWORD *)v18[4];
                do
                {
                  if ( v16 == *v21 )
                    break;
                  ++v20;
                  ++v21;
                }
                while ( v20 < v19 );
              }
              v16 = *(_DWORD *)(v18[2] + 4 * v20);
              v17 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v16) + 72);
              if ( v17 != -1 )
                continue;
            }
            v9 = v24;
            goto LABEL_36;
          }
        }
LABEL_38:
        v22 = 0;
        if ( v33 )
        {
          v23 = v9;
          do
          {
            *(_DWORD *)(v31[2] + 4 * v22) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v23) + 48);
            *(_DWORD *)(v31[4] + 4 * v22++) = *v23++;
          }
          while ( v22 < v33 );
        }
        v29 += v33;
        if ( v29 >= i )
          goto LABEL_14;
        v7 = v29;
      }
    }
LABEL_43:
    v27 = -2147024882;
    goto LABEL_15;
  }
LABEL_14:
  v27 = 0;
LABEL_15:
  j__free(Block);
  return v27;
}
