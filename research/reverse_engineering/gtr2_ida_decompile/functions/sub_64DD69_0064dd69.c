int __thiscall sub_64DD69(_DWORD *this)
{
  int v2; // edx
  BOOL v3; // edi
  unsigned int v4; // edi
  int v5; // esi
  int *v6; // eax
  int v7; // esi
  float *v8; // eax
  _DWORD *v9; // ecx
  _DWORD *v10; // edx
  _DWORD *i; // ecx
  char *v12; // eax
  char *v13; // ecx
  void **v14; // edi
  int v15; // esi
  void *v16; // eax
  void *v17; // eax
  float *v18; // eax
  float *v19; // edx
  float *v20; // edi
  float *v21; // ecx
  float *k; // eax
  double v23; // st7
  float *v24; // esi
  char *v25; // edi
  void **v26; // esi
  bool v27; // zf
  int v28; // edx
  unsigned int ii; // edi
  float *v30; // ecx
  double v31; // st5
  float *v32; // ecx
  double v33; // st5
  float *v34; // ecx
  double v35; // st5
  float *v36; // ecx
  double v37; // st5
  int v38; // edx
  unsigned int n; // edi
  float *v40; // ecx
  double v41; // st5
  float *v42; // ecx
  double v43; // st5
  float *v44; // ecx
  double v45; // st5
  float *v46; // ecx
  double v47; // st5
  int v48; // edx
  unsigned int m; // edi
  float *v50; // ecx
  double v51; // st6
  float *v52; // ecx
  double v53; // st6
  float *v54; // ecx
  double v55; // st6
  float *v56; // ecx
  double v57; // st6
  int v58; // esi
  unsigned int v60; // [esp+Ch] [ebp-30h]
  void **v61; // [esp+10h] [ebp-2Ch]
  char *v62; // [esp+10h] [ebp-2Ch]
  unsigned int v63; // [esp+14h] [ebp-28h]
  void *v64; // [esp+18h] [ebp-24h]
  float *v65; // [esp+18h] [ebp-24h]
  float *v66; // [esp+1Ch] [ebp-20h]
  float *v67; // [esp+20h] [ebp-1Ch]
  int v68; // [esp+20h] [ebp-1Ch]
  _DWORD *Block; // [esp+24h] [ebp-18h]
  void **v70; // [esp+28h] [ebp-14h]
  char *v71; // [esp+2Ch] [ebp-10h]
  float *v72; // [esp+30h] [ebp-Ch]
  void **v73; // [esp+34h] [ebp-8h]
  char *j; // [esp+38h] [ebp-4h]
  float *v75; // [esp+38h] [ebp-4h]
  char *v76; // [esp+38h] [ebp-4h]

  v2 = this[1];
  Block = 0;
  v73 = 0;
  v70 = 0;
  v72 = 0;
  if ( *(_DWORD *)(v2 + 112) != 1 || *(_DWORD *)(*this + 112) != 1 )
    return -2147467259;
  v3 = ((this[2] >> 17) & 1) == 0;
  v66 = (float *)sub_64AB33(*(_DWORD *)(*this + 104), *(_DWORD *)(v2 + 104), (this[2] & 0x10000) == 0);
  if ( v66 && (Block = sub_64AB33(*(_DWORD *)(*this + 108), *(_DWORD *)(this[1] + 108), v3)) != 0 )
  {
    v63 = (unsigned int)v66 + *(_DWORD *)v66;
    v4 = (unsigned int)Block + *Block;
    v5 = *(_DWORD *)(this[1] + 108);
    v60 = v4;
    v6 = (int *)operator new(12 * v5 + 4);
    if ( v6 )
    {
      *v6 = v5;
      v61 = (void **)(v6 + 1);
      sub_41D1B0((int)(v6 + 1), 12, v5, (int)unknown_libname_26);
      v73 = v61;
    }
    else
    {
      v73 = 0;
    }
    if ( v73
      && ((v7 = *(_DWORD *)(*this + 104), v8 = (float *)operator new(16 * v7), (v67 = v8) == 0)
        ? (v72 = 0)
        : (sub_41D1B0((int)v8, 16, v7, (int)sub_681563), v72 = v67),
          v72) )
    {
      v9 = Block + 1;
      if ( (unsigned int)(Block + 1) < v4 )
      {
        do
        {
          v10 = (_DWORD *)((char *)v9 + *v9);
          for ( i = v9 + 1; i < v10; i += 2 )
            v73[3 * *i + 2] = (char *)v73[3 * *i + 2] + 1;
          v9 = v10;
        }
        while ( (unsigned int)v10 < v4 );
      }
      v12 = (char *)(Block + 1);
      v68 = 0;
      if ( (unsigned int)(Block + 1) < v4 )
      {
        do
        {
          v13 = &v12[*(_DWORD *)v12];
          v71 = v13;
          v62 = v12 + 4;
          for ( j = v12 + 4; j < v13; j += 8 )
          {
            v14 = &v73[3 * *(_DWORD *)j];
            if ( !*v14 )
            {
              if ( v70 )
              {
                *v14 = *v70;
                *v70 = 0;
                v70 = (void **)v70[1];
              }
              else
              {
                v15 = *(_DWORD *)(this[1] + 104);
                v16 = operator new(16 * v15);
                v64 = v16;
                if ( v16 )
                {
                  sub_41D1B0((int)v16, 16, v15, (int)sub_681563);
                  v17 = v64;
                }
                else
                {
                  v17 = 0;
                }
                *v14 = v17;
                if ( !v17 )
                  goto LABEL_116;
              }
              memset(*v14, 0, 16 * *(_DWORD *)(this[1] + 104));
              v13 = v71;
            }
          }
          (*(void (__thiscall **)(_DWORD, int, _DWORD, float *))(*(_DWORD *)*this + 4))(*this, v68, 0, v72);
          v18 = v66 + 1;
          if ( (unsigned int)(v66 + 1) < v63 )
          {
            v19 = v72 + 2;
            do
            {
              v20 = (float *)((char *)v18 + *(_DWORD *)v18);
              v75 = (float *)v62;
              if ( v62 < v71 )
              {
                v65 = v18 + 1;
                do
                {
                  v21 = (float *)v73[3 * *(_DWORD *)v75];
                  for ( k = v65; k < v20; k += 2 )
                  {
                    v23 = k[1] * v75[1];
                    v21[4 * *(_DWORD *)k] = v23 * *(v19 - 2) + v21[4 * *(_DWORD *)k];
                    v21[4 * *(_DWORD *)k + 1] = v23 * *(v19 - 1) + v21[4 * *(_DWORD *)k + 1];
                    v21[4 * *(_DWORD *)k + 2] = v23 * *v19 + v21[4 * *(_DWORD *)k + 2];
                    v24 = &v21[4 * *(_DWORD *)k + 3];
                    *v24 = v23 * v19[1] + *v24;
                  }
                  v75 += 2;
                }
                while ( v75 < (float *)v71 );
              }
              v19 += 4;
              v18 = v20;
            }
            while ( (unsigned int)v20 < v63 );
          }
          v25 = v62;
          v12 = v71;
          while ( 1 )
          {
            v76 = v25;
            if ( v25 >= v12 )
              break;
            v26 = &v73[3 * *(_DWORD *)v25];
            v27 = v26[2] == (void *)1;
            v26[2] = (char *)v26[2] - 1;
            if ( v27 )
            {
              switch ( *(_DWORD *)(*this + 8) )
              {
                case 1:
                  v48 = 0;
                  for ( m = 0; m < *(_DWORD *)(this[1] + 104); v48 += 16 )
                  {
                    v50 = (float *)((char *)*v26 + v48);
                    if ( *v50 >= 0.0 )
                    {
                      if ( *v50 >= 1.0 )
                        v51 = 1.0;
                      else
                        v51 = *v50;
                    }
                    else
                    {
                      v51 = 0.0;
                    }
                    *v50 = v51;
                    v52 = (float *)((char *)*v26 + v48 + 4);
                    if ( *v52 >= 0.0 )
                    {
                      if ( *v52 >= 1.0 )
                        v53 = 1.0;
                      else
                        v53 = *v52;
                    }
                    else
                    {
                      v53 = 0.0;
                    }
                    *v52 = v53;
                    v54 = (float *)((char *)*v26 + v48 + 8);
                    if ( *v54 >= 0.0 )
                    {
                      if ( *v54 >= 1.0 )
                        v55 = 1.0;
                      else
                        v55 = *v54;
                    }
                    else
                    {
                      v55 = 0.0;
                    }
                    *v54 = v55;
                    v56 = (float *)((char *)*v26 + v48 + 12);
                    if ( *v56 >= 0.0 )
                    {
                      if ( *v56 >= 1.0 )
                        v57 = 1.0;
                      else
                        v57 = *v56;
                    }
                    else
                    {
                      v57 = 0.0;
                    }
                    *v56 = v57;
                    ++m;
                  }
                  break;
                case 2:
                  v38 = 0;
                  for ( n = 0; n < *(_DWORD *)(this[1] + 104); v38 += 16 )
                  {
                    v40 = (float *)((char *)*v26 + v38);
                    if ( *v40 >= -1.0 )
                    {
                      if ( *v40 >= 1.0 )
                        v41 = 1.0;
                      else
                        v41 = *v40;
                    }
                    else
                    {
                      v41 = -1.0;
                    }
                    *v40 = v41;
                    v42 = (float *)((char *)*v26 + v38 + 4);
                    if ( *v42 >= -1.0 )
                    {
                      if ( *v42 >= 1.0 )
                        v43 = 1.0;
                      else
                        v43 = *v42;
                    }
                    else
                    {
                      v43 = -1.0;
                    }
                    *v42 = v43;
                    v44 = (float *)((char *)*v26 + v38 + 8);
                    if ( *v44 >= -1.0 )
                    {
                      if ( *v44 >= 1.0 )
                        v45 = 1.0;
                      else
                        v45 = *v44;
                    }
                    else
                    {
                      v45 = -1.0;
                    }
                    *v44 = v45;
                    v46 = (float *)((char *)*v26 + v38 + 12);
                    if ( *v46 >= 0.0 )
                    {
                      if ( *v46 >= 1.0 )
                        v47 = 1.0;
                      else
                        v47 = *v46;
                    }
                    else
                    {
                      v47 = 0.0;
                    }
                    *v46 = v47;
                    ++n;
                  }
                  break;
                case 3:
                  v28 = 0;
                  for ( ii = 0; ii < *(_DWORD *)(this[1] + 104); v28 += 16 )
                  {
                    v30 = (float *)((char *)*v26 + v28);
                    if ( *v30 >= -1.0 )
                    {
                      if ( *v30 >= 1.0 )
                        v31 = 1.0;
                      else
                        v31 = *v30;
                    }
                    else
                    {
                      v31 = -1.0;
                    }
                    *v30 = v31;
                    v32 = (float *)((char *)*v26 + v28 + 4);
                    if ( *v32 >= -1.0 )
                    {
                      if ( *v32 >= 1.0 )
                        v33 = 1.0;
                      else
                        v33 = *v32;
                    }
                    else
                    {
                      v33 = -1.0;
                    }
                    *v32 = v33;
                    v34 = (float *)((char *)*v26 + v28 + 8);
                    if ( *v34 >= -1.0 )
                    {
                      if ( *v34 >= 1.0 )
                        v35 = 1.0;
                      else
                        v35 = *v34;
                    }
                    else
                    {
                      v35 = -1.0;
                    }
                    *v34 = v35;
                    v36 = (float *)((char *)*v26 + v28 + 12);
                    if ( *v36 >= -1.0 )
                    {
                      if ( *v36 >= 1.0 )
                        v37 = 1.0;
                      else
                        v37 = *v36;
                    }
                    else
                    {
                      v37 = -1.0;
                    }
                    *v36 = v37;
                    ++ii;
                  }
                  break;
              }
              v25 = v76;
              (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, void *))(*(_DWORD *)this[1] + 8))(
                this[1],
                *(_DWORD *)v76,
                0,
                *v26);
              v26[1] = v70;
              v12 = v71;
              v70 = v26;
            }
            v25 += 8;
          }
          ++v68;
        }
        while ( (unsigned int)v12 < v60 );
      }
      v58 = 0;
    }
    else
    {
LABEL_116:
      v58 = -2147024882;
    }
  }
  else
  {
    v58 = -2147467259;
  }
  if ( v73 )
    sub_64D694(v73, 3);
  j__free(Block);
  j__free(v66);
  j__free(v72);
  j__free(0);
  return v58;
}
