int __thiscall sub_53FD37(_DWORD *this)
{
  unsigned int v2; // edi
  BOOL v3; // edi
  int v4; // edi
  int *v5; // eax
  char *v6; // eax
  int v7; // edi
  char *v8; // eax
  void *v9; // eax
  _DWORD *v10; // ecx
  _DWORD *v11; // edx
  _DWORD *i; // ecx
  float *v13; // eax
  float *v14; // edx
  void **v15; // ebx
  int v16; // edi
  void *v17; // eax
  void *v18; // eax
  unsigned int v19; // edi
  float *v20; // edx
  float *v21; // eax
  float *v22; // ecx
  float *v23; // ebx
  int v24; // eax
  float *k; // ecx
  double v26; // st7
  float *v27; // edi
  float *m; // ebx
  void **v29; // edi
  bool v30; // zf
  _DWORD *v31; // ecx
  int v32; // esi
  BOOL v34; // [esp-4h] [ebp-6Ch]
  char *v35; // [esp+Ch] [ebp-5Ch]
  char *v36; // [esp+10h] [ebp-58h]
  char *v37; // [esp+10h] [ebp-58h]
  BOOL v38; // [esp+14h] [ebp-54h]
  float *v39; // [esp+14h] [ebp-54h]
  unsigned int v40; // [esp+18h] [ebp-50h]
  unsigned int v41; // [esp+1Ch] [ebp-4Ch]
  void *v42; // [esp+20h] [ebp-48h]
  unsigned int v43; // [esp+20h] [ebp-48h]
  _DWORD *v44; // [esp+24h] [ebp-44h]
  int v45; // [esp+28h] [ebp-40h]
  _DWORD *v46; // [esp+2Ch] [ebp-3Ch]
  int v47; // [esp+30h] [ebp-38h]
  float *v48; // [esp+34h] [ebp-34h]
  float *v49; // [esp+38h] [ebp-30h]
  _DWORD *v50; // [esp+3Ch] [ebp-2Ch]
  _DWORD *v51; // [esp+40h] [ebp-28h]
  unsigned int v52; // [esp+44h] [ebp-24h]
  void **v53; // [esp+48h] [ebp-20h]
  char *v54; // [esp+4Ch] [ebp-1Ch]
  unsigned int v55; // [esp+50h] [ebp-18h]
  char *v56; // [esp+54h] [ebp-14h]
  float *j; // [esp+58h] [ebp-10h]
  float *v58; // [esp+58h] [ebp-10h]
  unsigned int v59; // [esp+58h] [ebp-10h]

  v36 = 0;
  v53 = 0;
  v2 = this[2];
  v38 = ((v2 >> 18) & 1) == 0;
  v34 = (v2 & 0x10000) == 0;
  v3 = ((v2 >> 17) & 1) == 0;
  v44 = sub_53FA2E(*(_DWORD *)(*this + 4184), *(_DWORD *)(this[1] + 4184), v34);
  if ( v44
    && (v50 = sub_53FA2E(*(_DWORD *)(*this + 4188), *(_DWORD *)(this[1] + 4188), v3)) != 0
    && (v51 = sub_53FA2E(*(_DWORD *)(*this + 4192), *(_DWORD *)(this[1] + 4192), v38)) != 0 )
  {
    v41 = (unsigned int)v44 + *v44;
    v40 = (unsigned int)v50 + *v50;
    v52 = (unsigned int)v51 + *v51;
    v4 = *(_DWORD *)(this[1] + 4192);
    v5 = (int *)operator new(12 * v4 + 4);
    if ( v5 )
    {
      *v5 = v4;
      v37 = (char *)(v5 + 1);
      `eh vector constructor iterator'(v5 + 1, 0xCu, v4, (void (__thiscall *)(void *))unknown_libname_107, sub_53FA25);
      v6 = v37;
      v56 = v37;
    }
    else
    {
      v56 = 0;
      v6 = 0;
    }
    v36 = v6;
    if ( v6
      && ((v7 = *(_DWORD *)(*this + 4184), v8 = (char *)operator new(16 * v7), (v35 = v8) == 0)
        ? (v54 = 0, v9 = 0)
        : (sub_53D688((int)v8, 16, v7, (int (__thiscall *)(int))sub_53D5B2), v9 = v35, v54 = v35),
          v9) )
    {
      v10 = v51 + 1;
      if ( (unsigned int)(v51 + 1) < v52 )
      {
        do
        {
          v11 = (_DWORD *)((char *)v10 + *v10);
          for ( i = v10 + 1; i < v11; i += 2 )
            ++*(_DWORD *)&v56[12 * *i + 8];
          v10 = v11;
        }
        while ( (unsigned int)v11 < v52 );
      }
      v45 = 0;
      v13 = (float *)(v51 + 1);
      if ( (unsigned int)(v51 + 1) < v52 )
      {
        do
        {
          v14 = (float *)((char *)v13 + *(_DWORD *)v13);
          v55 = (unsigned int)v14;
          v39 = v13 + 1;
          for ( j = v13 + 1; j < v14; j += 2 )
          {
            v15 = (void **)&v56[12 * *(_DWORD *)j];
            if ( !*v15 )
            {
              if ( v53 )
              {
                *v15 = *v53;
                *v53 = 0;
                v53 = (void **)v53[1];
              }
              else
              {
                v16 = *(_DWORD *)(this[1] + 4184) * *(_DWORD *)(this[1] + 4188);
                v17 = operator new(16 * v16);
                v42 = v17;
                if ( v17 )
                {
                  sub_53D688((int)v17, 16, v16, (int (__thiscall *)(int))sub_53D5B2);
                  v18 = v42;
                }
                else
                {
                  v18 = 0;
                }
                *v15 = v18;
                if ( !v18 )
                  goto LABEL_54;
                v14 = (float *)v55;
              }
              memset(*v15, 0, 16 * *(_DWORD *)(this[1] + 4184) * *(_DWORD *)(this[1] + 4188));
            }
          }
          v47 = 0;
          v46 = v50 + 1;
          if ( (unsigned int)(v50 + 1) < v40 )
          {
            do
            {
              v19 = (unsigned int)v46 + *v46;
              v43 = v19;
              (*(void (__stdcall **)(int, int, char *))(*(_DWORD *)*this + 4))(v47, v45, v54);
              v48 = (float *)(v44 + 1);
              if ( (unsigned int)(v44 + 1) < v41 )
              {
                v20 = (float *)(v54 + 8);
                do
                {
                  v21 = (float *)((char *)v48 + *(_DWORD *)v48);
                  v22 = v39;
                  v49 = v21;
                  while ( 1 )
                  {
                    v58 = v22;
                    if ( (unsigned int)v22 >= v55 )
                      break;
                    v23 = (float *)(v46 + 1);
                    if ( (unsigned int)(v46 + 1) < v19 )
                    {
                      do
                      {
                        v24 = *(_DWORD *)&v56[12 * *(_DWORD *)v22] + 16 * *(_DWORD *)v23 * *(_DWORD *)(this[1] + 4184);
                        for ( k = v48 + 1; k < v49; k += 2 )
                        {
                          v26 = k[1] * v23[1] * v58[1];
                          *(float *)(v24 + 16 * *(_DWORD *)k) = v26 * *(v20 - 2) + *(float *)(v24 + 16 * *(_DWORD *)k);
                          *(float *)(16 * *(_DWORD *)k + v24 + 4) = v26 * *(v20 - 1)
                                                                  + *(float *)(16 * *(_DWORD *)k + v24 + 4);
                          *(float *)(16 * *(_DWORD *)k + v24 + 8) = v26 * *v20 + *(float *)(16 * *(_DWORD *)k + v24 + 8);
                          v27 = (float *)(16 * *(_DWORD *)k + v24 + 12);
                          *v27 = v26 * v20[1] + *v27;
                        }
                        v22 = v58;
                        v23 += 2;
                      }
                      while ( (unsigned int)v23 < v43 );
                      v19 = v43;
                      v21 = v49;
                    }
                    v22 += 2;
                  }
                  v20 += 4;
                  v48 = v21;
                }
                while ( (unsigned int)v21 < v41 );
              }
              ++v47;
              v46 = (_DWORD *)v19;
            }
            while ( v19 < v40 );
            v14 = (float *)v55;
          }
          for ( m = v39; m < v14; m += 2 )
          {
            v29 = (void **)&v56[12 * *(_DWORD *)m];
            v30 = v29[2] == (void *)1;
            v29[2] = (char *)v29[2] - 1;
            if ( v30 )
            {
              v31 = (_DWORD *)this[1];
              v59 = 0;
              if ( v31[1047] )
              {
                do
                {
                  (*(void (__stdcall **)(unsigned int, _DWORD, unsigned int))(*v31 + 8))(
                    v59,
                    *(_DWORD *)m,
                    (unsigned int)*v29 + 16 * v59 * v31[1046]);
                  ++v59;
                  v31 = (_DWORD *)this[1];
                }
                while ( v59 < v31[1047] );
                v14 = (float *)v55;
              }
              v29[1] = v53;
              v53 = v29;
            }
          }
          ++v45;
          v13 = v14;
        }
        while ( (unsigned int)v14 < v52 );
      }
      v32 = 0;
    }
    else
    {
LABEL_54:
      v32 = -2147024882;
    }
  }
  else
  {
    v32 = -2147467259;
  }
  if ( v36 )
    sub_53FCEB(v36, 3);
  sub_5BE8AE();
  sub_5BE8AE();
  sub_5BE8AE();
  sub_5BE8AE();
  sub_5BE8AE();
  return v32;
}
