int __thiscall sub_64D6E3(_DWORD *this)
{
  int v2; // edi
  BOOL v3; // edi
  unsigned int v4; // ebx
  int v5; // edi
  int *v6; // eax
  int v7; // edi
  float *v8; // eax
  _DWORD *v9; // ecx
  _DWORD *v10; // edx
  _DWORD *i; // ecx
  float *v12; // eax
  double v13; // st7
  void **v14; // ebx
  int v15; // edi
  void *v16; // eax
  void *v17; // eax
  float *v18; // edx
  float *v19; // eax
  float *k; // ebx
  int v21; // eax
  float *m; // ecx
  double v23; // st7
  float *v24; // edi
  float *v25; // ebx
  void **v26; // edi
  bool v27; // zf
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  unsigned int v31; // edx
  float *v32; // ecx
  double v33; // st6
  double v34; // st6
  double v35; // st6
  double v36; // st6
  unsigned int v37; // edx
  float *v38; // ecx
  double v39; // st6
  double v40; // st6
  double v41; // st6
  double v42; // st6
  unsigned int v43; // edx
  float *v44; // ecx
  double v45; // st6
  double v46; // st6
  double v47; // st6
  double v48; // st6
  int v49; // esi
  BOOL v51; // [esp-4h] [ebp-58h]
  unsigned int v52; // [esp+Ch] [ebp-48h]
  BOOL v53; // [esp+10h] [ebp-44h]
  void **v54; // [esp+10h] [ebp-44h]
  float *v55; // [esp+10h] [ebp-44h]
  float *v56; // [esp+10h] [ebp-44h]
  unsigned int v57; // [esp+14h] [ebp-40h]
  unsigned int v58; // [esp+18h] [ebp-3Ch]
  float *v59; // [esp+1Ch] [ebp-38h]
  int v60; // [esp+20h] [ebp-34h]
  void *v61; // [esp+24h] [ebp-30h]
  float *v62; // [esp+24h] [ebp-30h]
  float *v63; // [esp+28h] [ebp-2Ch]
  int v64; // [esp+2Ch] [ebp-28h]
  float *v65; // [esp+30h] [ebp-24h]
  float *v66; // [esp+34h] [ebp-20h]
  float *v67; // [esp+38h] [ebp-1Ch]
  _DWORD *Block; // [esp+3Ch] [ebp-18h]
  void **v69; // [esp+40h] [ebp-14h]
  float *v70; // [esp+44h] [ebp-10h]
  float *v71; // [esp+48h] [ebp-Ch]
  void **v72; // [esp+4Ch] [ebp-8h]
  float *j; // [esp+50h] [ebp-4h]
  float *v74; // [esp+50h] [ebp-4h]
  unsigned int n; // [esp+50h] [ebp-4h]

  v2 = this[2];
  v53 = (v2 & 0x40000) == 0;
  v51 = (v2 & 0x10000) == 0;
  v67 = 0;
  Block = 0;
  v72 = 0;
  v69 = 0;
  v71 = 0;
  v3 = (v2 & 0x20000) == 0;
  v59 = (float *)sub_64AB33(*(_DWORD *)(*this + 104), *(_DWORD *)(this[1] + 104), v51);
  if ( v59
    && (v67 = (float *)sub_64AB33(*(_DWORD *)(*this + 108), *(_DWORD *)(this[1] + 108), v3)) != 0
    && (Block = sub_64AB33(*(_DWORD *)(*this + 112), *(_DWORD *)(this[1] + 112), v53)) != 0 )
  {
    v58 = (unsigned int)v59 + *(_DWORD *)v59;
    v57 = (unsigned int)v67 + *(_DWORD *)v67;
    v4 = (unsigned int)Block + *Block;
    v5 = *(_DWORD *)(this[1] + 112);
    v52 = v4;
    v6 = (int *)operator new(12 * v5 + 4);
    if ( v6 )
    {
      *v6 = v5;
      v54 = (void **)(v6 + 1);
      sub_41D1B0((int)(v6 + 1), 12, v5, (int)unknown_libname_26);
      v72 = v54;
    }
    else
    {
      v72 = 0;
    }
    if ( v72
      && ((v7 = *(_DWORD *)(*this + 104), v8 = (float *)operator new(16 * v7), (v55 = v8) == 0)
        ? (v71 = 0)
        : (sub_41D1B0((int)v8, 16, v7, (int)sub_681563), v71 = v55),
          v71) )
    {
      v9 = Block + 1;
      if ( (unsigned int)(Block + 1) < v4 )
      {
        do
        {
          v10 = (_DWORD *)((char *)v9 + *v9);
          for ( i = v9 + 1; i < v10; i += 2 )
            v72[3 * *i + 2] = (char *)v72[3 * *i + 2] + 1;
          v9 = v10;
        }
        while ( (unsigned int)v10 < v4 );
      }
      v12 = (float *)(Block + 1);
      v60 = 0;
      if ( (unsigned int)(Block + 1) < v4 )
      {
        v13 = -1.0;
        do
        {
          v70 = (float *)((char *)v12 + *(_DWORD *)v12);
          v56 = v12 + 1;
          for ( j = v12 + 1; j < v70; j += 2 )
          {
            v14 = &v72[3 * *(_DWORD *)j];
            if ( !*v14 )
            {
              if ( v69 )
              {
                *v14 = *v69;
                *v69 = 0;
                v69 = (void **)v69[1];
              }
              else
              {
                v15 = *(_DWORD *)(this[1] + 104) * *(_DWORD *)(this[1] + 108);
                v16 = operator new(16 * v15);
                v61 = v16;
                if ( v16 )
                {
                  sub_41D1B0((int)v16, 16, v15, (int)sub_681563);
                  v17 = v61;
                }
                else
                {
                  v17 = 0;
                }
                *v14 = v17;
                if ( !v17 )
                  goto LABEL_128;
                v13 = -1.0;
              }
              memset(*v14, 0, 16 * *(_DWORD *)(this[1] + 104) * *(_DWORD *)(this[1] + 108));
            }
          }
          v64 = 0;
          v62 = v67 + 1;
          if ( (unsigned int)(v67 + 1) < v57 )
          {
            do
            {
              v63 = (float *)((char *)v62 + *(_DWORD *)v62);
              (*(void (__thiscall **)(_DWORD, int, int, float *))(*(_DWORD *)*this + 4))(*this, v64, v60, v71);
              v65 = v59 + 1;
              if ( (unsigned int)(v59 + 1) < v58 )
              {
                v18 = v71 + 2;
                do
                {
                  v66 = (float *)((char *)v65 + *(_DWORD *)v65);
                  v19 = v56;
                  v74 = v56;
                  while ( v19 < v70 )
                  {
                    for ( k = v62 + 1; k < v63; k += 2 )
                    {
                      v21 = (int)v72[3 * *(_DWORD *)v74] + 16 * *(_DWORD *)k * *(_DWORD *)(this[1] + 104);
                      for ( m = v65 + 1; m < v66; m += 2 )
                      {
                        v23 = m[1] * v74[1] * k[1];
                        *(float *)(v21 + 16 * *(_DWORD *)m) = v23 * *(v18 - 2) + *(float *)(v21 + 16 * *(_DWORD *)m);
                        *(float *)(16 * *(_DWORD *)m + v21 + 4) = v23 * *(v18 - 1)
                                                                + *(float *)(16 * *(_DWORD *)m + v21 + 4);
                        *(float *)(16 * *(_DWORD *)m + v21 + 8) = v23 * *v18 + *(float *)(16 * *(_DWORD *)m + v21 + 8);
                        v24 = (float *)(16 * *(_DWORD *)m + v21 + 12);
                        *v24 = v23 * v18[1] + *v24;
                      }
                    }
                    v74 += 2;
                    v19 = v74;
                  }
                  v18 += 4;
                  v65 = v66;
                }
                while ( (unsigned int)v66 < v58 );
              }
              ++v64;
              v62 = v63;
            }
            while ( (unsigned int)v63 < v57 );
            v13 = -1.0;
          }
          v25 = v56;
          v12 = v70;
          while ( v25 < v12 )
          {
            v26 = &v72[3 * *(_DWORD *)v25];
            v27 = v26[2] == (void *)1;
            v26[2] = (char *)v26[2] - 1;
            if ( v27 )
            {
              v28 = this[1];
              for ( n = 0; n < *(_DWORD *)(v28 + 108); v28 = this[1] )
              {
                v29 = *(_DWORD *)(v28 + 104);
                v30 = (int)*v26 + 16 * n * v29;
                switch ( *(_DWORD *)(*this + 8) )
                {
                  case 1:
                    v43 = 0;
                    if ( v29 )
                    {
                      v44 = (float *)(v30 + 8);
                      do
                      {
                        if ( *(v44 - 2) >= 0.0 )
                        {
                          if ( *(v44 - 2) >= 1.0 )
                            v45 = 1.0;
                          else
                            v45 = *(v44 - 2);
                        }
                        else
                        {
                          v45 = 0.0;
                        }
                        *(v44 - 2) = v45;
                        if ( *(v44 - 1) >= 0.0 )
                        {
                          if ( *(v44 - 1) >= 1.0 )
                            v46 = 1.0;
                          else
                            v46 = *(v44 - 1);
                        }
                        else
                        {
                          v46 = 0.0;
                        }
                        *(v44 - 1) = v46;
                        if ( *v44 >= 0.0 )
                        {
                          if ( *v44 >= 1.0 )
                            v47 = 1.0;
                          else
                            v47 = *v44;
                        }
                        else
                        {
                          v47 = 0.0;
                        }
                        *v44 = v47;
                        if ( v44[1] >= 0.0 )
                        {
                          if ( v44[1] >= 1.0 )
                            v48 = 1.0;
                          else
                            v48 = v44[1];
                        }
                        else
                        {
                          v48 = 0.0;
                        }
                        v44[1] = v48;
                        ++v43;
                        v44 += 4;
                      }
                      while ( v43 < *(_DWORD *)(this[1] + 104) );
                    }
                    break;
                  case 2:
                    v37 = 0;
                    if ( v29 )
                    {
                      v38 = (float *)(v30 + 8);
                      do
                      {
                        if ( v13 <= *(v38 - 2) )
                        {
                          if ( *(v38 - 2) >= 1.0 )
                            v39 = 1.0;
                          else
                            v39 = *(v38 - 2);
                        }
                        else
                        {
                          v39 = v13;
                        }
                        *(v38 - 2) = v39;
                        if ( v13 <= *(v38 - 1) )
                        {
                          if ( *(v38 - 1) >= 1.0 )
                            v40 = 1.0;
                          else
                            v40 = *(v38 - 1);
                        }
                        else
                        {
                          v40 = v13;
                        }
                        *(v38 - 1) = v40;
                        if ( v13 <= *v38 )
                        {
                          if ( *v38 >= 1.0 )
                            v41 = 1.0;
                          else
                            v41 = *v38;
                        }
                        else
                        {
                          v41 = v13;
                        }
                        *v38 = v41;
                        if ( v38[1] >= 0.0 )
                        {
                          if ( v38[1] >= 1.0 )
                            v42 = 1.0;
                          else
                            v42 = v38[1];
                        }
                        else
                        {
                          v42 = 0.0;
                        }
                        v38[1] = v42;
                        ++v37;
                        v38 += 4;
                      }
                      while ( v37 < *(_DWORD *)(this[1] + 104) );
                    }
                    break;
                  case 3:
                    v31 = 0;
                    if ( v29 )
                    {
                      v32 = (float *)(v30 + 8);
                      do
                      {
                        if ( v13 <= *(v32 - 2) )
                        {
                          if ( *(v32 - 2) >= 1.0 )
                            v33 = 1.0;
                          else
                            v33 = *(v32 - 2);
                        }
                        else
                        {
                          v33 = v13;
                        }
                        *(v32 - 2) = v33;
                        if ( v13 <= *(v32 - 1) )
                        {
                          if ( *(v32 - 1) >= 1.0 )
                            v34 = 1.0;
                          else
                            v34 = *(v32 - 1);
                        }
                        else
                        {
                          v34 = v13;
                        }
                        *(v32 - 1) = v34;
                        if ( v13 <= *v32 )
                        {
                          if ( *v32 >= 1.0 )
                            v35 = 1.0;
                          else
                            v35 = *v32;
                        }
                        else
                        {
                          v35 = v13;
                        }
                        *v32 = v35;
                        if ( v13 <= v32[1] )
                        {
                          if ( v32[1] >= 1.0 )
                            v36 = 1.0;
                          else
                            v36 = v32[1];
                        }
                        else
                        {
                          v36 = v13;
                        }
                        v32[1] = v36;
                        ++v31;
                        v32 += 4;
                      }
                      while ( v31 < *(_DWORD *)(this[1] + 104) );
                    }
                    break;
                }
                (*(void (__stdcall **)(unsigned int, _DWORD, unsigned int))(*(_DWORD *)this[1] + 8))(
                  n,
                  *(_DWORD *)v25,
                  (unsigned int)*v26 + 16 * n * *(_DWORD *)(this[1] + 104));
                v13 = -1.0;
                ++n;
              }
              v26[1] = v69;
              v12 = v70;
              v69 = v26;
            }
            v25 += 2;
          }
          ++v60;
        }
        while ( (unsigned int)v12 < v52 );
      }
      v49 = 0;
    }
    else
    {
LABEL_128:
      v49 = -2147024882;
    }
  }
  else
  {
    v49 = -2147467259;
  }
  if ( v72 )
    sub_64D694(v72, 3);
  j__free(Block);
  j__free(v67);
  j__free(v59);
  j__free(v71);
  j__free(0);
  return v49;
}
