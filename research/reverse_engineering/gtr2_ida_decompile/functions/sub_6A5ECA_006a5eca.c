int __thiscall sub_6A5ECA(_DWORD *this)
{
  bool v2; // zf
  int *v3; // eax
  int v4; // ecx
  unsigned int v5; // edx
  int v6; // edi
  int v7; // ecx
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  _DWORD *v12; // eax
  int v13; // ecx
  bool v14; // cf
  _DWORD *v15; // ebx
  int *v16; // edx
  unsigned int v17; // eax
  int v18; // ecx
  unsigned int i; // eax
  int v20; // ecx
  unsigned int v21; // ebx
  void *v22; // edi
  int result; // eax
  int v24; // eax
  int v25; // eax
  _DWORD *v26; // eax
  void *v27; // eax
  void *v28; // eax
  void *v29; // eax
  void *v30; // edi
  _DWORD *v31; // eax
  unsigned int v32; // edx
  int v33; // ecx
  _DWORD *v34; // edx
  int v35; // ecx
  int v36; // edi
  int v37; // edi
  unsigned int v38; // edx
  _DWORD *v39; // eax
  int v40; // ecx
  unsigned int k; // eax
  unsigned int j; // ecx
  int v43; // eax
  _DWORD v44[6]; // [esp+Ch] [ebp-70h] BYREF
  _DWORD v45[6]; // [esp+24h] [ebp-58h] BYREF
  int v46[6]; // [esp+3Ch] [ebp-40h] BYREF
  int v47; // [esp+54h] [ebp-28h]
  int v48; // [esp+58h] [ebp-24h]
  int v49; // [esp+5Ch] [ebp-20h]
  unsigned int v50; // [esp+60h] [ebp-1Ch]
  _DWORD *v51; // [esp+64h] [ebp-18h]
  int v52; // [esp+68h] [ebp-14h]
  void *Block; // [esp+6Ch] [ebp-10h]
  int v54; // [esp+70h] [ebp-Ch] BYREF
  void *v55; // [esp+74h] [ebp-8h]
  unsigned int v56; // [esp+78h] [ebp-4h]

  Block = 0;
  v55 = 0;
  memset(v45, 0, sizeof(v45));
  memset(v44, 0, sizeof(v44));
  memset(v46, 0, sizeof(v46));
  memset(this + 259, 0xFFu, 0x18u);
  memset(this + 265, 0xFFu, 0x18u);
  v2 = this[3] == 0;
  v52 = 1;
  v50 = 0;
  v56 = 0;
  if ( v2 )
    goto LABEL_30;
  do
  {
    v3 = *(int **)(this[6] + 4 * v56);
    v4 = *v3;
    v5 = *v3 & 0xFFF00000;
    v3[9] = 0;
    if ( v5 != 1610612736 && v5 != 1615855616 && v5 != 1621098496 && v5 != 1626341376 )
    {
      if ( v5 == 285212672 )
      {
        v24 = *(_DWORD *)v3[2];
        goto LABEL_38;
      }
      if ( v5 != 1925185536 && v5 != 1926234112 )
      {
        v6 = v4 & 0xFFFFF;
        v48 = v4 & 0xFFFFF;
        if ( (v4 & 0xFFFFF) != 0 && v4 )
        {
          v54 = 0;
          if ( v3[1] )
          {
            v7 = v3[1];
            v8 = (_DWORD *)v3[2];
            v47 = v7;
            v51 = v8;
            do
            {
              v9 = *(_DWORD *)(this[5] + 4 * *v51);
              if ( *(_DWORD *)(v9 + 4) == this[32] )
              {
                v10 = *(unsigned __int8 *)(v9 + 109);
                if ( *(_BYTE *)(v9 + 108) == 3 )
                {
                  v11 = v10;
                  v12 = &v45[v10];
                  if ( *v12 && (unsigned __int16)this[50] != 260 && !v46[v11] )
                    v52 = 0;
                  *v12 = 1;
                  v13 = v54 + v6;
                  v14 = v54 < (unsigned int)(v54 + v6);
                  v44[v11] = 1;
                  if ( v14 )
                  {
                    v15 = v51;
                    v16 = &v46[v11];
                    v17 = *v16;
                    v49 = v13 - v54;
                    do
                    {
                      v18 = this[5];
                      if ( *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v15) + 16) + 1 > v17 )
                        v17 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v15) + 16) + 1;
                      ++v15;
                      --v49;
                    }
                    while ( v49 );
                    v6 = v48;
                    *v16 = v17;
                  }
                }
              }
              v54 += v6;
              v51 += v6;
            }
            while ( v54 < (unsigned int)v47 );
          }
          ++v50;
        }
        goto LABEL_27;
      }
    }
    v24 = *(_DWORD *)(v3[2] + 4 * (v4 & 0xFFFFF));
LABEL_38:
    v25 = *(_DWORD *)(this[5] + 4 * v24);
    if ( *(_DWORD *)(v25 + 4) != this[32] || *(_DWORD *)(v25 + 60) )
    {
      v52 = 0;
    }
    else
    {
      if ( *(_BYTE *)(v25 + 108) != 3 )
      {
        sub_686791(
          (int)this,
          *(_DWORD *)(v25 + 96),
          4513,
          "texture loads or clips cannot be from inputs not marked TEXCOORD");
        return -2147467259;
      }
      v26 = &v45[*(unsigned __int8 *)(v25 + 109)];
      if ( *v26 && (unsigned __int16)this[50] != 260 )
        v52 = 0;
      *v26 = 1;
    }
LABEL_27:
    ++v56;
  }
  while ( v56 < this[3] );
  if ( v50 > 0x10 )
    v52 = 0;
LABEL_30:
  for ( i = 0; i < this[2]; *(_DWORD *)(v20 + 64) = 0 )
    v20 = *(_DWORD *)(this[5] + 4 * i++);
  v21 = this[3];
  v47 = v21;
  if ( v52 )
  {
    this[139] = 0;
    v22 = operator new(0x800u);
    this[140] = v22;
    if ( v22 )
    {
      memset(v22, 0, 0x800u);
      result = sub_6A572C(this, this[140], this + 137, this[6], v21, 0, 0);
      if ( result < 0 )
        return result;
LABEL_78:
      v37 = 0;
      for ( j = 0; j < this[2]; ++j )
      {
        v43 = *(_DWORD *)(this[5] + 4 * j);
        if ( *(_DWORD *)(v43 + 64) == 1 )
          *(_DWORD *)(v43 + 4) = this[29];
      }
      goto LABEL_82;
    }
    return -2147024882;
  }
  v27 = operator new(0x800u);
  this[139] = v27;
  if ( !v27 )
    return -2147024882;
  v28 = operator new(0x800u);
  this[140] = v28;
  if ( !v28 )
    return -2147024882;
  Block = operator new(0x800u);
  if ( !Block )
    return -2147024882;
  v29 = operator new(0x800u);
  v30 = (void *)this[139];
  v55 = v29;
  memset(v30, 0, 0x800u);
  memset((void *)this[140], 0, 0x800u);
  memset(Block, 0, 0x800u);
  memset(v55, 0, 0x800u);
  v2 = this[3] == 0;
  this[136] = 0;
  this[137] = 0;
  v54 = 0;
  v56 = 0;
  if ( v2 )
  {
LABEL_71:
    v38 = 0;
    if ( v54 )
    {
      v39 = Block;
      v40 = (_BYTE *)v55 - (_BYTE *)Block;
      do
      {
        *(_DWORD *)((char *)v39 + v40) = *v39;
        *v39 = 0;
        ++v38;
        ++v39;
      }
      while ( v38 < v54 );
    }
    v37 = sub_6A572C(this, this[140], this + 137, this[6], v47, 0, 0);
    if ( v37 < 0 )
      goto LABEL_82;
    for ( k = 0; k < v54; ++k )
      *(_DWORD *)(*((_DWORD *)v55 + k) + 36) = 0;
    v37 = sub_6A572C(this, this[139], this + 136, (int)v55, v54, this[140], this[19]);
    if ( v37 < 0 )
      goto LABEL_82;
    goto LABEL_78;
  }
  while ( 2 )
  {
    if ( v56 >= 0x200 )
    {
      sub_686791((int)this, 0, 4514, "program too big");
      return -2147467259;
    }
    v31 = *(_DWORD **)(this[6] + 4 * v56);
    v32 = *v31 & 0xFFF00000;
    if ( v32 != 1610612736
      && v32 != 1615855616
      && v32 != 1621098496
      && v32 != 1626341376
      && v32 != 285212672
      && v32 != 1926234112
      && v32 != 1925185536 )
    {
LABEL_70:
      if ( ++v56 >= this[3] )
        goto LABEL_71;
      continue;
    }
    break;
  }
  v33 = *v31 & 0xFFFFF;
  v49 = v33;
  if ( v32 == 285212672 )
  {
    v33 = 0;
    v49 = 0;
  }
  v34 = (_DWORD *)(v31[2] + 4 * v33);
  v35 = *(_DWORD *)(this[5] + 4 * *v34);
  v36 = *(_DWORD *)(v35 + 4);
  if ( v36 == this[34] || *(_DWORD *)(v35 + 60) )
  {
    v37 = sub_6A554C(this, (int)v34, v31[1] - v49, (int)Block, &v54);
    if ( v37 < 0 )
      goto LABEL_82;
    goto LABEL_70;
  }
  if ( v36 != this[32] )
    goto LABEL_70;
  if ( *(_BYTE *)(v35 + 108) == 3 )
  {
    if ( v44[*(unsigned __int8 *)(v35 + 109)] && (unsigned __int16)this[50] != 260 )
    {
      sub_686791((int)this, 0, 4520, "can read from texcoord and use it for texlookup only in ps_1_4 and higher");
      goto LABEL_90;
    }
    goto LABEL_70;
  }
  sub_686791((int)this, 0, 4513, "cannot perform dependent texture read which in any way is based on color inputs");
LABEL_90:
  v37 = -2147467259;
LABEL_82:
  if ( Block )
    j__free(Block);
  if ( v55 )
    j__free(v55);
  return v37;
}
