int __thiscall sub_542E09(_DWORD *this)
{
  int v2; // edx
  BOOL v3; // edi
  _DWORD *v4; // esi
  unsigned int v5; // edi
  int v6; // esi
  int *v7; // eax
  char *v8; // eax
  int v9; // esi
  char *v10; // eax
  void *v11; // eax
  _DWORD *v12; // ecx
  _DWORD *v13; // edx
  _DWORD *i; // ecx
  float *v15; // eax
  float *v16; // esi
  float *v17; // eax
  void **v18; // edi
  int v19; // esi
  void *v20; // eax
  void *v21; // eax
  float *v22; // eax
  float *v23; // edx
  float *v24; // ecx
  float *v25; // edi
  int v26; // ecx
  float *v27; // eax
  double v28; // st7
  float *v29; // esi
  float *v30; // edi
  void **v31; // esi
  bool v32; // zf
  int v33; // esi
  unsigned int v35; // [esp+Ch] [ebp-44h]
  void *v36; // [esp+10h] [ebp-40h]
  float *v37; // [esp+10h] [ebp-40h]
  char *v38; // [esp+14h] [ebp-3Ch]
  _DWORD *v39; // [esp+18h] [ebp-38h]
  char *v40; // [esp+1Ch] [ebp-34h]
  char *v41; // [esp+1Ch] [ebp-34h]
  float *v42; // [esp+20h] [ebp-30h]
  unsigned int v43; // [esp+24h] [ebp-2Ch]
  int v44; // [esp+28h] [ebp-28h]
  char *v45; // [esp+2Ch] [ebp-24h]
  _DWORD *v46; // [esp+30h] [ebp-20h]
  unsigned int v47; // [esp+34h] [ebp-1Ch]
  void **v48; // [esp+38h] [ebp-18h]
  char *v49; // [esp+3Ch] [ebp-14h]
  float *v50; // [esp+40h] [ebp-10h]
  float *v51; // [esp+40h] [ebp-10h]

  v2 = this[1];
  v40 = 0;
  v48 = 0;
  if ( *(_DWORD *)(v2 + 4192) != 1 || *(_DWORD *)(*this + 4192) != 1 )
    return -2147467259;
  v3 = ((this[2] >> 17) & 1) == 0;
  v4 = sub_53FA2E(*(_DWORD *)(*this + 4184), *(_DWORD *)(v2 + 4184), (this[2] & 0x10000) == 0);
  v39 = v4;
  if ( v4 && (v46 = sub_53FA2E(*(_DWORD *)(*this + 4188), *(_DWORD *)(this[1] + 4188), v3)) != 0 )
  {
    v43 = (unsigned int)v4 + *v4;
    v5 = (unsigned int)v46 + *v46;
    v6 = *(_DWORD *)(this[1] + 4188);
    v35 = v5;
    v7 = (int *)operator new(12 * v6 + 4);
    if ( v7 )
    {
      *v7 = v6;
      v41 = (char *)(v7 + 1);
      `eh vector constructor iterator'(v7 + 1, 0xCu, v6, (void (__thiscall *)(void *))unknown_libname_107, sub_53FA25);
      v8 = v41;
      v49 = v41;
    }
    else
    {
      v49 = 0;
      v8 = 0;
    }
    v40 = v8;
    if ( v8
      && ((v9 = *(_DWORD *)(*this + 4184), v10 = (char *)operator new(16 * v9), (v38 = v10) == 0)
        ? (v45 = 0, v11 = 0)
        : (sub_53D688((int)v10, 16, v9, (int (__thiscall *)(int))sub_53D5B2), v11 = v38, v45 = v38),
          v11) )
    {
      v12 = v46 + 1;
      if ( (unsigned int)(v46 + 1) < v5 )
      {
        do
        {
          v13 = (_DWORD *)((char *)v12 + *v12);
          for ( i = v12 + 1; i < v13; i += 2 )
            ++*(_DWORD *)&v49[12 * *i + 8];
          v12 = v13;
        }
        while ( (unsigned int)v13 < v5 );
      }
      v15 = (float *)(v46 + 1);
      v44 = 0;
      if ( (unsigned int)(v46 + 1) < v5 )
      {
        do
        {
          v16 = (float *)((char *)v15 + *(_DWORD *)v15);
          v17 = v15 + 1;
          v47 = (unsigned int)v16;
          v42 = v17;
          while ( 1 )
          {
            v50 = v17;
            if ( v17 >= v16 )
              break;
            v18 = (void **)&v49[12 * *(_DWORD *)v17];
            if ( !*v18 )
            {
              if ( v48 )
              {
                *v18 = *v48;
                *v48 = 0;
                v48 = (void **)v48[1];
              }
              else
              {
                v19 = *(_DWORD *)(this[1] + 4184);
                v20 = operator new(16 * v19);
                v36 = v20;
                if ( v20 )
                {
                  sub_53D688((int)v20, 16, v19, (int (__thiscall *)(int))sub_53D5B2);
                  v21 = v36;
                }
                else
                {
                  v21 = 0;
                }
                *v18 = v21;
                if ( !v21 )
                  goto LABEL_47;
              }
              v16 = (float *)v47;
              memset(*v18, 0, 16 * *(_DWORD *)(this[1] + 4184));
            }
            v17 = v50 + 2;
          }
          (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)*this + 4))(*this, v44, 0, v45);
          v22 = (float *)(v39 + 1);
          if ( (unsigned int)(v39 + 1) < v43 )
          {
            v23 = (float *)(v45 + 8);
            do
            {
              v24 = v42;
              v25 = (float *)((char *)v22 + *(_DWORD *)v22);
              v51 = v42;
              if ( v42 < v16 )
              {
                v37 = v22 + 1;
                while ( 1 )
                {
                  v26 = *(_DWORD *)&v49[12 * *(_DWORD *)v24];
                  v27 = v37;
                  if ( v37 < v25 )
                  {
                    do
                    {
                      v28 = v27[1] * v51[1];
                      *(float *)(v26 + 16 * *(_DWORD *)v27) = v28 * *(v23 - 2) + *(float *)(v26 + 16 * *(_DWORD *)v27);
                      *(float *)(16 * *(_DWORD *)v27 + v26 + 4) = v28 * *(v23 - 1)
                                                                + *(float *)(16 * *(_DWORD *)v27 + v26 + 4);
                      *(float *)(16 * *(_DWORD *)v27 + v26 + 8) = v28 * *v23 + *(float *)(16 * *(_DWORD *)v27 + v26 + 8);
                      v29 = (float *)(16 * *(_DWORD *)v27 + v26 + 12);
                      v27 += 2;
                      *v29 = v28 * v23[1] + *v29;
                    }
                    while ( v27 < v25 );
                    v16 = (float *)v47;
                  }
                  v51 += 2;
                  if ( v51 >= v16 )
                    break;
                  v24 = v51;
                }
              }
              v23 += 4;
              v22 = v25;
            }
            while ( (unsigned int)v25 < v43 );
          }
          v30 = v42;
          if ( v42 < v16 )
          {
            do
            {
              v31 = (void **)&v49[12 * *(_DWORD *)v30];
              v32 = v31[2] == (void *)1;
              v31[2] = (char *)v31[2] - 1;
              if ( v32 )
              {
                (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, void *))(*(_DWORD *)this[1] + 8))(
                  this[1],
                  *(_DWORD *)v30,
                  0,
                  *v31);
                v31[1] = v48;
                v48 = v31;
              }
              v30 += 2;
            }
            while ( (unsigned int)v30 < v47 );
            v16 = (float *)v47;
          }
          ++v44;
          v15 = v16;
        }
        while ( (unsigned int)v16 < v35 );
      }
      v33 = 0;
    }
    else
    {
LABEL_47:
      v33 = -2147024882;
    }
  }
  else
  {
    v33 = -2147467259;
  }
  if ( v40 )
    sub_53FCEB(v40, 3);
  sub_5BE8AE();
  sub_5BE8AE();
  sub_5BE8AE();
  sub_5BE8AE();
  return v33;
}
