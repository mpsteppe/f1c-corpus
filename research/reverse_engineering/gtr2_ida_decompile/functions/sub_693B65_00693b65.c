int __thiscall sub_693B65(_DWORD *this)
{
  unsigned int v1; // esi
  bool v3; // zf
  int v4; // ecx
  int v5; // edi
  int v6; // edx
  size_t v7; // edi
  unsigned int v9; // esi
  int v10; // eax
  unsigned int v11; // edi
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  unsigned int j; // edx
  _DWORD *v16; // eax
  unsigned int *v17; // ecx
  unsigned int i; // ecx
  _DWORD *v19; // eax
  bool v20; // cf
  unsigned int k; // edx
  int v22; // eax
  int v23; // ecx
  unsigned int v24; // eax
  int *v25; // esi
  int v26; // edi
  int v27; // ecx
  unsigned int v28; // edx
  int v29; // edx
  unsigned int v30; // ecx
  int v31; // eax
  int v32; // esi
  unsigned int n; // eax
  int v34; // ecx
  int m; // eax
  int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // edx
  int v39; // esi
  unsigned int v40; // ecx
  unsigned int v41; // edx
  _DWORD *v42; // eax
  int v43; // ecx
  int v44; // esi
  int v45; // ecx
  int v46; // eax
  int v47; // eax
  unsigned int ii; // edx
  _DWORD *v49; // eax
  int v50; // ecx
  int v51; // ecx
  unsigned int v52; // eax
  void *v53; // [esp-4h] [ebp-74h]
  _BYTE v54[16]; // [esp+Ch] [ebp-64h] BYREF
  _DWORD v55[4]; // [esp+1Ch] [ebp-54h] BYREF
  _DWORD v56[4]; // [esp+2Ch] [ebp-44h] BYREF
  int v57; // [esp+3Ch] [ebp-34h] BYREF
  int v58; // [esp+40h] [ebp-30h]
  _DWORD *v59; // [esp+44h] [ebp-2Ch] BYREF
  int v60; // [esp+48h] [ebp-28h]
  unsigned int v61; // [esp+4Ch] [ebp-24h]
  int v62; // [esp+50h] [ebp-20h]
  unsigned int v63; // [esp+54h] [ebp-1Ch]
  _DWORD *v64; // [esp+58h] [ebp-18h] BYREF
  int *v65; // [esp+5Ch] [ebp-14h]
  unsigned int v66; // [esp+60h] [ebp-10h]
  _DWORD *v67; // [esp+64h] [ebp-Ch]
  unsigned int v68; // [esp+68h] [ebp-8h]
  void *Block; // [esp+6Ch] [ebp-4h]

  v1 = 0;
  v3 = this[1] == 0;
  v63 = 0;
  if ( !v3 )
  {
    v4 = this[4];
    v5 = this[1];
    do
    {
      v6 = *(_DWORD *)(*(_DWORD *)v4 + 4);
      if ( (v6 & 0x100) != 0 && (v6 & 0xC00) != 0 )
        v1 += *(_DWORD *)(*(_DWORD *)v4 + 8);
      v4 += 4;
      --v5;
    }
    while ( v5 );
    v63 = v1;
  }
  v7 = 16 * (v1 + 2 * this[3]);
  Block = operator new(v7);
  if ( !Block )
    return -2147024882;
  memset(Block, 0xFFu, v7);
  v9 = 0;
  v58 = 0;
  sub_686606(this);
  v3 = this[1] == 0;
  v66 = 0;
  if ( !v3 )
  {
    do
    {
      v64 = *(_DWORD **)(*(_DWORD *)(this[4] + 4 * v9) + 4);
      if ( (BYTE1(v64) & 1) != 0 && (BYTE1(v64) & 0xC) != 0 )
      {
        v68 = 0;
        if ( v63 )
        {
          v10 = this[2];
          do
          {
            v11 = 0;
            if ( v10 )
            {
              v12 = this[5];
              do
              {
                v13 = *(_DWORD *)(v12 + 4 * v11);
                if ( *(_DWORD *)(v13 + 4) == v9 && *(_DWORD *)(v13 + 8) == -1 )
                {
                  v14 = *((_DWORD *)Block + 4 * v68 + 4 * *(_DWORD *)(v13 + 12) + *(_DWORD *)(v13 + 16));
                  if ( v14 != -1
                    && ((BYTE1(v64) & 8) != 0 || *(double *)(v13 + 32) != *(double *)(*(_DWORD *)(v12 + 4 * v14) + 32)) )
                  {
                    v9 = v66;
                    break;
                  }
                  v9 = v66;
                }
                ++v11;
              }
              while ( v11 < this[2] );
            }
            v10 = this[2];
            if ( v11 == v10 )
              break;
            ++v68;
          }
          while ( v68 < v63 );
        }
        if ( (BYTE1(v64) & 8) != 0 )
        {
          for ( i = 0; i < this[2]; ++i )
          {
            v19 = *(_DWORD **)(this[5] + 4 * i);
            if ( v19[1] == v9 )
              *((_DWORD *)Block + 4 * v68 + 4 * v19[3] + v19[4]) = i;
          }
        }
        else
        {
          for ( j = 0; j < this[2]; ++j )
          {
            v16 = *(_DWORD **)(this[5] + 4 * j);
            if ( v16[1] == v9 )
            {
              v16[3] += v68;
              if ( v16[2] == -1 )
              {
                v17 = (unsigned int *)((char *)Block + 16 * v16[3] + 4 * v16[4]);
                if ( *v17 == -1 )
                {
                  *v17 = j;
                }
                else
                {
                  v16[1] = this[29];
                  v16[12] = *v17;
                  v58 = 1;
                }
              }
            }
          }
        }
      }
      v20 = ++v9 < this[1];
      v66 = v9;
    }
    while ( v20 );
    if ( v58 )
      sub_68661F(this);
  }
  for ( k = 0; k < this[2]; ++k )
  {
    v22 = *(_DWORD *)(this[5] + 4 * k);
    v23 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v22 + 4)) + 4);
    if ( (v23 & 0x100) != 0 && (v23 & 0xC00) == 0 )
    {
      *(_DWORD *)(v22 + 12) = -1;
      *(_DWORD *)(v22 + 4) = this[30];
    }
  }
  v3 = this[3] == 0;
  v63 = 0;
  if ( !v3 )
  {
    do
    {
      v3 = (*(_WORD *)(*(_DWORD *)(this[6] + 4 * v63) + 2) & 0xFFF0) == 0;
      v67 = *(_DWORD **)(this[6] + 4 * v63);
      if ( !v3 )
      {
        memset(v56, 255, sizeof(v56));
        memset(v55, 0, sizeof(v55));
        v68 = 0;
        v60 = 0;
        v62 = 0;
        v24 = sub_680D41(v67, 0, &v64);
        v61 = v24;
        if ( v24 )
        {
          v25 = (int *)v54;
          v65 = (int *)v54;
          while ( 1 )
          {
            v26 = this[5];
            v27 = *(_DWORD *)(v26 + 4 * *v64);
            if ( this[30] == *(_DWORD *)(v27 + 4) && *(_DWORD *)(v27 + 8) == -1 )
            {
              *v25 = (unsigned __int8)(~(unsigned __int8)this[27] & 4) >> 2;
              v28 = 1;
              if ( v24 > 1 )
              {
                do
                {
                  if ( !*v25 )
                    break;
                  if ( *(double *)(v27 + 32) != *(double *)(*(_DWORD *)(v26 + 4 * v64[v28]) + 32) )
                    *v25 = 0;
                  v24 = v61;
                  ++v28;
                }
                while ( v28 < v61 );
              }
              v66 = 0;
              if ( v24 )
              {
                while ( 1 )
                {
                  v29 = v64[v66];
                  v30 = 0;
                  if ( v68 )
                  {
                    do
                    {
                      if ( *(double *)(*(_DWORD *)(v26 + 4 * v56[v30]) + 32) == *(double *)(*(_DWORD *)(v26 + 4 * v29)
                                                                                          + 32) )
                        break;
                      ++v30;
                    }
                    while ( v30 < v68 );
                    if ( v30 == 4 )
                      break;
                  }
                  if ( v30 == v68 )
                  {
                    v31 = v68++;
                    v56[v31] = v29;
                  }
                  if ( !*v65 )
                    v55[v30] |= 1 << v66;
                  if ( ++v66 >= v61 )
                    goto LABEL_72;
                }
                v60 = 1;
LABEL_72:
                v25 = v65;
              }
              if ( v60 )
                break;
            }
            ++v62;
            v65 = ++v25;
            v24 = sub_680D41(v67, v62, &v64);
            v61 = v24;
            if ( !v24 )
            {
              if ( v60 )
                break;
              goto LABEL_76;
            }
          }
LABEL_83:
          v60 = 0;
          for ( m = sub_680D41(v67, 0, &v59); ; m = sub_680D41(v67, v60, &v59) )
          {
            v66 = m;
            if ( !m )
              break;
            v36 = *(_DWORD *)(this[5] + 4 * *v59);
            if ( this[30] == *(_DWORD *)(v36 + 4) && *(_DWORD *)(v36 + 8) == -1 )
            {
              v37 = v66;
              v38 = 0;
              if ( v66 )
              {
                qmemcpy(v56, v59, 4 * v66);
                do
                {
                  v39 = 1 << v38++;
                  *(_DWORD *)&v54[4 * v38 + 12] = v39;
                }
                while ( v38 < v37 );
              }
              if ( v37 < 4 )
              {
                v40 = (4 * (4 - v37)) >> 2;
                memset(&v55[v37], 0, 4 * v40);
                memset(&v56[v37], 0xFFu, 4 * v40);
              }
              sub_6851A3(this, (int)Block, v56, (char *)v55);
              sub_6850B2(this, (int)v56, v59, v66);
            }
            ++v60;
          }
          goto LABEL_94;
        }
LABEL_76:
        if ( sub_6851A3(this, (int)Block, v56, (char *)v55) < 0 )
          goto LABEL_83;
        v32 = 0;
        for ( n = sub_680D41(v67, 0, &v57); n; n = sub_680D41(v67, v32, &v57) )
        {
          v34 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)v57);
          if ( this[30] == *(_DWORD *)(v34 + 4) && *(_DWORD *)(v34 + 8) == -1 )
            sub_6850B2(this, (int)v56, (_DWORD *)v57, n);
          ++v32;
        }
      }
LABEL_94:
      ++v63;
    }
    while ( v63 < this[3] );
  }
  v41 = 0;
  v3 = this[2] == 0;
  v57 = 0;
  if ( !v3 )
  {
    do
    {
      v42 = *(_DWORD **)(this[5] + 4 * v41);
      v43 = v42[1];
      v44 = this[30];
      if ( v44 == v43 && v42[3] == -1 )
      {
        v42[1] = this[29];
      }
      else
      {
        v45 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * v43) + 4);
        if ( (v45 & 0x100) != 0 && (v45 & 0x40) != 0 && (v45 & 0x800) == 0 )
        {
          v3 = v42[2] == -1;
          v42[1] = v44;
          if ( !v3 )
            v57 = 1;
        }
      }
      ++v41;
    }
    while ( v41 < this[2] );
  }
  v46 = *(_DWORD *)(this[4] + 4 * this[30]);
  *(_DWORD *)(v46 + 4) |= 0x40u;
  if ( v57 )
  {
    v47 = *(_DWORD *)(this[4] + 4 * this[30]);
    *(_BYTE *)(v47 + 5) |= 4u;
  }
  *(_DWORD *)(*(_DWORD *)(this[4] + 4 * this[30]) + 8) = 0;
  for ( ii = 0; ii < this[2]; ++ii )
  {
    v49 = *(_DWORD **)(this[5] + 4 * ii);
    v50 = this[30];
    if ( v50 == v49[1] && v49[2] == -1 )
    {
      v51 = *(_DWORD *)(this[4] + 4 * v50);
      v52 = v49[3];
      if ( *(_DWORD *)(v51 + 8) <= v52 )
        *(_DWORD *)(v51 + 8) = v52 + 1;
    }
  }
  if ( v58 )
    sub_68FECA(this);
  v53 = Block;
  this[55] = 1;
  j__free(v53);
  return 0;
}
