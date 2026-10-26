int __thiscall sub_6C6CB5(_DWORD *this)
{
  int result; // eax
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // eax
  int v9; // ebx
  int v10; // eax
  bool v11; // zf
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // edi
  int v18; // eax
  int v19; // edi
  int v20; // ecx
  unsigned int v21; // edx
  _DWORD *v22; // eax
  int v23; // ecx
  int v24; // edi
  unsigned int v25; // edx
  _DWORD *v26; // eax
  unsigned int v27; // edi
  bool v28; // cc
  int v29; // eax
  int v30; // edi
  int v31; // eax
  int v32; // ecx
  _DWORD *v33; // edi
  int v34; // eax
  int v35; // eax
  _DWORD *v36; // edi
  int v37; // eax
  int v38; // ecx
  unsigned int k; // eax
  int v40; // edi
  int v41; // ecx
  int v42; // eax
  int v43; // ecx
  int v44; // eax
  int v45; // ecx
  int v46; // ebx
  _DWORD *v47; // eax
  int v48; // eax
  _DWORD *v49; // ecx
  int v50; // eax
  _DWORD *v51; // ebx
  _DWORD *v52; // eax
  int v53; // [esp+Ch] [ebp-7Ch]
  _DWORD v54[8]; // [esp+24h] [ebp-64h] BYREF
  unsigned int v55; // [esp+44h] [ebp-44h]
  int v56; // [esp+48h] [ebp-40h]
  _DWORD *v57; // [esp+4Ch] [ebp-3Ch]
  int v58; // [esp+50h] [ebp-38h]
  int v59; // [esp+54h] [ebp-34h]
  int v60; // [esp+58h] [ebp-30h]
  int v61; // [esp+5Ch] [ebp-2Ch]
  unsigned int v62; // [esp+60h] [ebp-28h]
  int v63; // [esp+64h] [ebp-24h]
  int v64; // [esp+68h] [ebp-20h]
  unsigned int i; // [esp+6Ch] [ebp-1Ch]
  int v66; // [esp+70h] [ebp-18h] BYREF
  unsigned int v67; // [esp+74h] [ebp-14h]
  unsigned int v68; // [esp+78h] [ebp-10h]
  int v69; // [esp+7Ch] [ebp-Ch]
  int v70; // [esp+80h] [ebp-8h]
  int j; // [esp+84h] [ebp-4h]

  result = sub_6BC1A9(this);
  if ( result >= 0 )
  {
    v3 = this[2];
    v69 = 0;
    if ( v3 )
    {
      v4 = this[34];
      v5 = this[5];
      v6 = v3;
      do
      {
        if ( v4 == *(_DWORD *)(*(_DWORD *)v5 + 4) )
        {
          v7 = *(_DWORD *)(*(_DWORD *)v5 + 12);
          if ( v7 >= v69 )
            v69 = v7 + 1;
        }
        v5 += 4;
        --v6;
      }
      while ( v6 );
    }
    v8 = 0;
    v55 = this[3];
    for ( i = 0; i < v55; ++i )
    {
      v9 = *(_DWORD *)(this[6] + 4 * v8);
      v10 = *(_DWORD *)v9;
      v11 = (*(_DWORD *)v9 & 0xFFF00000) == 0;
      v56 = v9;
      if ( !v11 )
      {
        v70 = v10 & 0xFFFFF;
        v12 = this[5];
        v62 = *(_DWORD *)(v9 + 4) / (v10 & 0xFFFFFu);
        v13 = *(_DWORD *)(v12 + 4 * **(_DWORD **)(v9 + 16));
        v14 = *(_DWORD *)(v13 + 20);
        v15 = *(_DWORD *)(v13 + 24);
        v64 = v14;
        v63 = v15;
        while ( (*(int (__thiscall **)(_DWORD *, int, int *))(*this + 32))(this, v9, &v66)
             && (*(_DWORD *)v9 & 0xFFF00000) != 0x74100000 )
        {
          v16 = v66;
          v11 = (*(_BYTE *)(*(_DWORD *)(this[4]
                                      + 4
                                      * *(_DWORD *)(*(_DWORD *)(this[5]
                                                              + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4 * v70 * v66))
                                                  + 4))
                          + 4)
               & 2) == 0;
          v60 = *(_DWORD *)(this[4]
                          + 4
                          * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4 * v70 * v66)) + 4));
          if ( !v11 )
          {
            sub_686791((int)this, *(_DWORD *)(v9 + 60), 0, "internal error: result violated port constraints");
            return -2147467259;
          }
          v67 = 0;
          j = 0;
          if ( v62 )
          {
            v68 = 0;
            do
            {
              v17 = *(_DWORD *)(this[4]
                              + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v68 + *(_DWORD *)(v9 + 8))) + 4));
              if ( (*(int (__thiscall **)(_DWORD *, int, int))(*this + 156))(this, v9, j) != 1 )
              {
                v18 = *(_DWORD *)(v17 + 4);
                if ( (v18 & 0x40) != 0 && (((unsigned __int16)v18 ^ *(_WORD *)(v60 + 4)) & 0x12BF) == 0 )
                {
                  v19 = v70;
                  if ( v70 )
                  {
                    v20 = this[5];
                    v21 = v68;
                    do
                    {
                      if ( v67 < *(_DWORD *)(*(_DWORD *)(v20 + 4 * *(_DWORD *)(v21 + *(_DWORD *)(v9 + 8))) + 92) )
                      {
                        v67 = *(_DWORD *)(*(_DWORD *)(v20 + 4 * *(_DWORD *)(v21 + *(_DWORD *)(v9 + 8))) + 92);
                        v66 = j;
                      }
                      v21 += 4;
                      --v19;
                    }
                    while ( v19 );
                  }
                }
              }
              ++j;
              v68 += 4 * v70;
            }
            while ( j < v62 );
            v16 = v66;
          }
          v22 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4 * v70 * v16));
          v23 = v22[1];
          v24 = v22[3];
          v60 = v22[2];
          v11 = (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v23) + 4) & 0x40) == 0;
          v58 = v23;
          v61 = v24;
          if ( v11 )
          {
            sub_686791(
              (int)this,
              *(_DWORD *)(v9 + 60),
              0,
              "internal error: non-vectorized pool violated port constraints");
            return -2147467259;
          }
          memset(v54, 255, 16);
          v67 = 0;
          v25 = 0;
          if ( this[2] )
          {
            v68 = this[5];
            do
            {
              v26 = *(_DWORD **)v68;
              if ( *(_DWORD *)(*(_DWORD *)v68 + 4) == v23 && v26[3] == v61 && v26[2] == v60 && v26[14] == -1 )
              {
                v27 = v26[22];
                if ( v27 >= i )
                {
                  v28 = v67 <= v27;
                  v54[v26[4]] = v25;
                  if ( v28 )
                    v67 = v27 + 1;
                }
              }
              v68 += 4;
              ++v25;
            }
            while ( v25 < this[2] );
          }
          v29 = 0;
          v68 = 0;
          for ( j = 0; (unsigned int)j < 4; ++j )
          {
            v30 = j;
            v59 = v54[j];
            if ( v59 != -1 )
            {
              v31 = sub_681AAA(this, this[34], v69, j, 0.0);
              v54[v30 + 4] = v31;
              if ( v31 == -1 )
                return -2147024882;
              v32 = this[5];
              v33 = *(_DWORD **)(v32 + 4 * v31);
              result = sub_681692(v33, *(_DWORD **)(v32 + 4 * v59));
              if ( result < 0 )
                return result;
              v34 = v64;
              v33[26] = 0;
              v33[27] = -1;
              v33[28] = 0;
              ++v68;
              v33[5] = v34;
              v33[6] = v63;
              v29 = v68;
            }
          }
          v35 = sub_681B0A(this, v29 & 0xFFFFF | 0x10000000, v29, v29);
          if ( v35 == -1 )
            return -2147024882;
          v36 = *(_DWORD **)(this[6] + 4 * v35);
          result = sub_680D22(v36, v9);
          if ( result < 0 )
            return result;
          v37 = 0;
          for ( j = 0; (unsigned int)j < 0x10; j += 4 )
          {
            v38 = *(_DWORD *)((char *)v54 + j);
            if ( v38 != -1 )
            {
              *(_DWORD *)(v37 + v36[2]) = v38;
              *(_DWORD *)(v37 + v36[4]) = *(_DWORD *)((char *)&v54[4] + j);
              v37 += 4;
            }
          }
          ++v69;
          for ( k = i; ; k = j + 1 )
          {
            j = k;
            if ( k >= v67 )
              break;
            v40 = *(_DWORD *)(this[6] + 4 * k);
            if ( (*(_WORD *)(v40 + 2) & 0xFFF0) != 0 )
            {
              v41 = *(_DWORD *)(this[5] + 4 * **(_DWORD **)(v40 + 16));
              v42 = *(_DWORD *)(v41 + 20);
              v43 = *(_DWORD *)(v41 + 24);
              while ( v42 != -1 && (v42 != v64 || v43 != v63) )
              {
                v44 = *(_DWORD *)(this[5] + 4 * v42);
                v43 = *(_DWORD *)(v44 + 24);
                v42 = *(_DWORD *)(v44 + 20);
              }
              if ( v42 == v64 && v43 == v63 )
              {
                if ( (*(int (__thiscall **)(_DWORD *, int, _DWORD))(*this + 32))(this, v40, 0) )
                {
                  v68 = 0;
                  if ( *(_DWORD *)(v40 + 4) )
                  {
                    do
                    {
                      v45 = this[5];
                      v46 = 4 * v68;
                      v59 = 4 * v68 + *(_DWORD *)(v40 + 8);
                      v47 = *(_DWORD **)(v45 + 4 * *(_DWORD *)v59);
                      v11 = v47[1] == v58;
                      v57 = v47;
                      if ( v11 && v47[3] == v61 && v47[2] == v60 )
                      {
                        v11 = v47[14] == -1;
                        v48 = v54[v47[4] + 4];
                        if ( v11 )
                        {
                          *(_DWORD *)v59 = v48;
                        }
                        else
                        {
                          v49 = *(_DWORD **)(v45 + 4 * v48);
                          v53 = v49[4];
                          v59 = (int)v49;
                          *(_DWORD *)(v46 + *(_DWORD *)(v40 + 8)) = sub_681AAA(this, this[34], v49[3], v53, 0.0);
                          v50 = *(_DWORD *)(v40 + 8);
                          if ( *(_DWORD *)(v46 + v50) == -1 )
                            return -2147024882;
                          v51 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v46 + v50));
                          result = sub_681692(v51, (_DWORD *)v59);
                          if ( result < 0 )
                            return result;
                          v52 = v57;
                          v51[14] = v54[v57[4] + 4];
                          v51[15] = v52[15];
                        }
                      }
                      ++v68;
                    }
                    while ( v68 < *(_DWORD *)(v40 + 4) );
                    v9 = v56;
                  }
                }
              }
            }
          }
        }
        result = sub_681C03(this, (_DWORD *)v9);
        if ( result < 0 )
          return result;
        *(_DWORD *)v9 = 0;
      }
      v8 = i + 1;
    }
    return 0;
  }
  return result;
}
