int __thiscall sub_6C0E5D(int this)
{
  int v2; // eax
  _DWORD *v4; // eax
  char *v5; // ebx
  int v6; // edi
  unsigned int v7; // ecx
  unsigned int v8; // eax
  bool v9; // zf
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // edi
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int i; // edx
  int *v19; // eax
  int v20; // edi
  _DWORD *v21; // ebx
  int v22; // eax
  int v23; // eax
  int v24; // edx
  unsigned int v25; // ecx
  int v26; // ebx
  bool v27; // cc
  _DWORD *v28; // eax
  int v29; // ecx
  int v30; // edi
  int v31; // edx
  int v32; // ecx
  int *v33; // ecx
  int v34; // eax
  _DWORD *v35; // ebx
  int v36; // eax
  int v37; // edi
  _DWORD *v38; // eax
  char *v39; // edi
  int v40; // ebx
  char *v41; // ecx
  char *v42; // eax
  int v43; // ebx
  char v44[64]; // [esp+14h] [ebp-218h] BYREF
  char v45[64]; // [esp+54h] [ebp-1D8h] BYREF
  _DWORD v46[40]; // [esp+94h] [ebp-198h] BYREF
  _DWORD v47[40]; // [esp+134h] [ebp-F8h] BYREF
  int v48[4]; // [esp+1D4h] [ebp-58h] BYREF
  int v49[4]; // [esp+1E4h] [ebp-48h] BYREF
  unsigned int v50; // [esp+1F4h] [ebp-38h]
  unsigned int v51; // [esp+1F8h] [ebp-34h]
  unsigned int v52; // [esp+1FCh] [ebp-30h]
  int v53; // [esp+200h] [ebp-2Ch]
  int v54; // [esp+204h] [ebp-28h]
  _DWORD *v55; // [esp+208h] [ebp-24h]
  char *v56; // [esp+20Ch] [ebp-20h]
  int v57; // [esp+210h] [ebp-1Ch]
  int v58; // [esp+214h] [ebp-18h]
  char *v59; // [esp+218h] [ebp-14h]
  int v60; // [esp+21Ch] [ebp-10h]
  unsigned int v61; // [esp+220h] [ebp-Ch] BYREF
  unsigned int v62; // [esp+224h] [ebp-8h]
  unsigned int v63; // [esp+228h] [ebp-4h]

  memset(&v48[1], 255, 12);
  memset(&v49[1], 255, 12);
  v2 = **(_DWORD **)(this + 256);
  v48[0] = 0;
  v49[0] = 0;
  v50 = v2 & 0xFFFFF;
  if ( (v2 & 0xFFF00000) != 0x20900000 )
    return 1;
  v4 = (_DWORD *)sub_681186(116);
  if ( v4 )
    v56 = (char *)sub_680CEC(v4);
  else
    v56 = 0;
  v5 = v56;
  if ( !v56 )
    return -2147024882;
  v6 = sub_681430(v56, *(_DWORD **)(this + 256));
  if ( v6 < 0 )
  {
    sub_66238F(v56, 1);
    return v6;
  }
  v7 = v50;
  v8 = 0;
  v9 = v50 == 0;
  *((_DWORD *)v56 + 3) = 1;
  *((_DWORD *)v5 + 1) = 2;
  *(_DWORD *)v5 = 546308097;
  v51 = 0;
  if ( v9 )
    return 0;
  v54 = 4 * v7;
  while ( 1 )
  {
    v10 = 4 * v8;
    **((_DWORD **)v5 + 4) = *(_DWORD *)(v10 + *(_DWORD *)(*(_DWORD *)(this + 256) + 16));
    **((_DWORD **)v5 + 2) = *(_DWORD *)(v10 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8));
    v11 = *(_DWORD *)(v54 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8));
    v12 = *((_DWORD *)v5 + 2);
    v61 = 0;
    *(_DWORD *)(v12 + 4) = v11;
    memset(v47, 0xFFu, sizeof(v47));
    if ( !sub_6BB35B((_DWORD *)this, (int *)v5, &unk_746F70, v45, &v61, (int)v47, v48, 1u, 1) )
    {
      v13 = v47[4];
      if ( v47[4] == v47[8] )
      {
        v61 = 0;
        sub_6BB35B((_DWORD *)this, (int *)v5, dword_747030, v44, &v61, (int)v46, v49, 1u, 1);
        v60 = v46[0] == v47[0] ? v46[4] : v47[0];
        if ( v60 != -1 )
        {
          v14 = 4 * **((_DWORD **)v5 + 4);
          if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + v14) + 20) != -1 )
          {
            v15 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20)
                                        + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + v14) + 20))
                            + 72);
            if ( v15 != -1 )
            {
              v9 = **(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v15) == 286261249;
              v59 = *(char **)(*(_DWORD *)(this + 24) + 4 * v15);
              if ( v9 )
              {
                v16 = *(_DWORD *)(this + 20);
                v58 = *(_DWORD *)(v16 + 4 * v47[0]);
                v17 = *(_DWORD *)(v16 + 4 * v13);
                for ( i = v13; ; v17 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * i) )
                {
                  v22 = *(_DWORD *)(v17 + 72);
                  if ( v22 == -1 )
                    break;
                  if ( *(_DWORD *)(v17 + 8) != -1 )
                    break;
                  v19 = *(int **)(*(_DWORD *)(this + 24) + 4 * v22);
                  v20 = *v19;
                  if ( (*v19 & 0xFFF00000) != 0x10000000 )
                    break;
                  v63 = 0;
                  v62 = v20 & 0xFFFFF;
                  if ( (v20 & 0xFFFFF) == 0 )
                    break;
                  v21 = (_DWORD *)v19[4];
                  while ( *v21 != i )
                  {
                    ++v63;
                    ++v21;
                    if ( v63 >= v62 )
                      goto LABEL_32;
                  }
                  i = *(_DWORD *)(v19[2] + 4 * v63);
                }
LABEL_32:
                v23 = *(_DWORD *)(this + 16);
                if ( (*(_DWORD *)(*(_DWORD *)(v23 + 4 * *(_DWORD *)(v58 + 4)) + 4) & 0x100) != 0
                  && (*(_DWORD *)(*(_DWORD *)(v23 + 4 * *(_DWORD *)(v17 + 4)) + 4) & 0x100) != 0
                  && *(double *)(v58 + 32) == 1.0
                  && *(double *)(v17 + 32) == 0.0 )
                {
                  v24 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v60);
                  v25 = *(_DWORD *)(v24 + 84);
                  v26 = -1;
                  v27 = v25 <= *(_DWORD *)(v24 + 88);
                  v53 = -1;
                  v58 = v24;
                  v61 = v25;
                  if ( v27 )
                  {
                    do
                    {
                      v28 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v25);
                      v9 = v28[3] == 0;
                      v55 = v28;
                      if ( !v9 )
                      {
                        v62 = 0;
                        if ( v28[1] )
                        {
                          while ( 1 )
                          {
                            v29 = *(_DWORD *)(this + 20);
                            v30 = *(_DWORD *)(v29 + 4 * *(_DWORD *)(v28[2] + 4 * v62));
                            v31 = *(_DWORD *)(v30 + 8);
                            v57 = -1;
                            if ( v31 == -1 )
                              goto LABEL_49;
                            v32 = *(_DWORD *)(*(_DWORD *)(v29 + 4 * v31) + 72);
                            if ( v32 != -1 )
                              break;
LABEL_55:
                            if ( ++v62 >= v28[1] )
                            {
                              v24 = v58;
                              v25 = v61;
                              goto LABEL_57;
                            }
                          }
                          v33 = *(int **)(*(_DWORD *)(this + 24) + 4 * v32);
                          v34 = *v33;
                          if ( (*v33 & 0xFFF00000) == 0x10000000 )
                          {
                            v63 = 0;
                            v52 = v34 & 0xFFFFF;
                            if ( (v34 & 0xFFFFF) != 0 )
                            {
                              v35 = (_DWORD *)v33[4];
                              while ( *v35 != v31 )
                              {
                                ++v63;
                                ++v35;
                                if ( v63 >= v52 )
                                  goto LABEL_49;
                              }
                              v57 = *(_DWORD *)(v33[2] + 4 * v63);
                            }
                          }
                          else
                          {
                            v57 = v31;
                          }
LABEL_49:
                          v26 = v53;
                          if ( v57 == v60 )
                          {
                            if ( v53 == -1 )
                            {
                              v36 = sub_681A51((void *)this, (int)&unk_7474F8, 21, -1, 4);
                              v26 = sub_681AAA((void *)this, v36, 0, 0, 0.0);
                              v53 = v26;
                              *(_DWORD *)(v30 + 8) = v26;
                            }
                            *(_DWORD *)(v30 + 8) = v26;
                            v37 = *(_DWORD *)(v30 + 56);
                            if ( v37 != -1 )
                              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v37) + 8) = v26;
                          }
                          v28 = v55;
                          goto LABEL_55;
                        }
                      }
LABEL_57:
                      v27 = ++v25 <= *(_DWORD *)(v24 + 88);
                      v61 = v25;
                    }
                    while ( v27 );
                    if ( v26 != -1 )
                      break;
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_66:
    v54 += 4;
    v8 = ++v51;
    if ( v51 >= v50 )
      return 0;
    v5 = v56;
  }
  v38 = (_DWORD *)sub_681186(116);
  if ( v38 )
    v39 = (char *)sub_680CEC(v38);
  else
    v39 = 0;
  if ( !v39 )
    return -2147024882;
  v40 = sub_6811D1(v39, 1947205633, 3, 1, 0);
  v41 = v39;
  if ( v40 < 0 )
    goto LABEL_69;
  v40 = sub_680D22(v39, (int)v59);
  if ( v40 >= 0 )
  {
    v42 = v59;
    **((_DWORD **)v39 + 4) = **((_DWORD **)v59 + 4);
    **((_DWORD **)v39 + 2) = **((_DWORD **)v42 + 2);
    v43 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * **((_DWORD **)v42 + 2));
    *(_DWORD *)(*((_DWORD *)v39 + 2) + 4) = sub_681AAA(
                                              (void *)this,
                                              *(_DWORD *)(v43 + 4),
                                              *(_DWORD *)(v43 + 12),
                                              2,
                                              0.0);
    *(_DWORD *)(*((_DWORD *)v39 + 2) + 8) = sub_681AAA(
                                              (void *)this,
                                              *(_DWORD *)(v43 + 4),
                                              *(_DWORD *)(v43 + 12),
                                              2,
                                              1.0);
    v40 = sub_681430(v59, v39);
    sub_66238F(v39, 1);
    if ( v40 < 0 )
      return v40;
    goto LABEL_66;
  }
  v41 = v39;
LABEL_69:
  sub_66238F(v41, 1);
  return v40;
}
