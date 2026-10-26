int __usercall sub_502F31@<eax>(int a1@<ebp>)
{
  int **v1; // ecx
  int **v2; // esi
  unsigned int v3; // eax
  BOOL v4; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // ecx
  char *v9; // eax
  _DWORD *v10; // ecx
  int v11; // edi
  _DWORD *v12; // eax
  int v13; // eax
  int v14; // edi
  int v15; // eax
  int v16; // eax
  unsigned int v17; // edi
  _DWORD *v18; // ecx
  _DWORD *v19; // edx
  _DWORD *i; // ecx
  _DWORD *v21; // eax
  _DWORD *v22; // edx
  _DWORD *v23; // eax
  void **v24; // ebx
  void **v25; // eax
  int v26; // edi
  int v27; // eax
  void *v28; // eax
  unsigned int v29; // eax
  bool v30; // cf
  int *v31; // ecx
  unsigned int v32; // edi
  int v33; // eax
  unsigned int v34; // eax
  float *v35; // edx
  unsigned int v36; // eax
  _DWORD *v37; // ecx
  unsigned int v38; // ebx
  int v39; // eax
  unsigned int j; // ecx
  double v41; // st7
  float *v42; // edi
  _DWORD *k; // ebx
  _DWORD *v44; // edi
  int *v46; // ecx
  int v47; // esi
  LPVOID *v48; // ecx
  int v50; // [esp-68h] [ebp-68h]
  int v51; // [esp-64h] [ebp-64h]
  int v52; // [esp-60h] [ebp-60h]

  sub_58A5D8();
  v2 = v1;
  *(_DWORD *)(a1 - 44) = 0;
  *(_DWORD *)(a1 - 40) = 0;
  *(_DWORD *)(a1 - 88) = 0;
  *(_DWORD *)(a1 - 32) = 0;
  *(_DWORD *)(a1 - 92) = 0;
  v3 = (unsigned int)v1[2];
  *(_DWORD *)(a1 - 84) = ((v3 >> 18) & 1) == 0;
  v4 = ((v3 >> 17) & 1) == 0;
  v5 = sub_502C28((*v2)[1046], v2[1][1046], (v3 & 0x10000) == 0);
  *(_DWORD *)(a1 - 68) = v5;
  if ( v5
    && (v6 = sub_502C28((*v2)[1047], v2[1][1047], v4), (*(_DWORD *)(a1 - 44) = v6) != 0)
    && (v7 = sub_502C28((*v2)[1048], v2[1][1048], *(_DWORD *)(a1 - 84)), (*(_DWORD *)(a1 - 40) = v7) != 0) )
  {
    v8 = *(_DWORD **)(a1 - 44);
    *(_DWORD *)(a1 - 76) = *(_DWORD *)(a1 - 68) + **(_DWORD **)(a1 - 68);
    v9 = (char *)v8 + *v8;
    v10 = *(_DWORD **)(a1 - 40);
    *(_DWORD *)(a1 - 80) = v9;
    *(_DWORD *)(a1 - 36) = (char *)v10 + *v10;
    v11 = v2[1][1048];
    v12 = (_DWORD *)sub_587C03(12 * v11 + 4);
    *(_DWORD *)(a1 - 84) = v12;
    *(_DWORD *)(a1 - 4) = 0;
    if ( v12 )
    {
      *v12 = v11;
      *(_DWORD *)(a1 - 88) = v12 + 1;
      sub_58A6EB(v12 + 1, 12, v11, sub_502C12, sub_502C1F);
      v13 = *(_DWORD *)(a1 - 88);
      *(_DWORD *)(a1 - 20) = v13;
    }
    else
    {
      *(_DWORD *)(a1 - 20) = 0;
      v13 = *(_DWORD *)(a1 - 20);
    }
    *(_DWORD *)(a1 - 4) = -1;
    *(_DWORD *)(a1 - 88) = v13;
    if ( !v13 )
      goto LABEL_54;
    v14 = (*v2)[1046];
    v15 = sub_587C03(16 * v14);
    *(_DWORD *)(a1 - 92) = v15;
    *(_DWORD *)(a1 - 4) = 1;
    if ( v15 )
    {
      sub_5008C2(v15, 16, v14, (int (__thiscall *)(int))sub_5007EC);
      v16 = *(_DWORD *)(a1 - 92);
      *(_DWORD *)(a1 - 28) = v16;
    }
    else
    {
      *(_DWORD *)(a1 - 28) = 0;
      v16 = *(_DWORD *)(a1 - 28);
    }
    *(_DWORD *)(a1 - 4) = -1;
    *(_DWORD *)(a1 - 92) = v16;
    if ( v16 )
    {
      v17 = *(_DWORD *)(a1 - 40) + 4;
      v18 = (_DWORD *)v17;
      if ( v17 < *(_DWORD *)(a1 - 36) )
      {
        do
        {
          v19 = (_DWORD *)((char *)v18 + *v18);
          for ( i = v18 + 1; i < v19; i += 2 )
            ++*(_DWORD *)(*(_DWORD *)(a1 - 20) + 12 * *i + 8);
          v18 = v19;
        }
        while ( (unsigned int)v19 < *(_DWORD *)(a1 - 36) );
      }
      *(_DWORD *)(a1 - 64) = 0;
      v21 = (_DWORD *)v17;
      if ( v17 < *(_DWORD *)(a1 - 36) )
      {
        do
        {
          v22 = (_DWORD *)((char *)v21 + *v21);
          v23 = v21 + 1;
          *(_DWORD *)(a1 - 24) = v22;
          *(_DWORD *)(a1 - 84) = v23;
          *(_DWORD *)(a1 - 16) = v23;
          if ( v23 < v22 )
          {
            do
            {
              v24 = (void **)(*(_DWORD *)(a1 - 20) + 12 * **(_DWORD **)(a1 - 16));
              if ( !*v24 )
              {
                v25 = *(void ***)(a1 - 32);
                if ( v25 )
                {
                  *v24 = *v25;
                  *v25 = 0;
                  *(_DWORD *)(a1 - 32) = v25[1];
                }
                else
                {
                  v26 = v2[1][1046] * v2[1][1047];
                  v27 = sub_587C03(16 * v26);
                  *(_DWORD *)(a1 - 72) = v27;
                  *(_DWORD *)(a1 - 4) = 2;
                  if ( v27 )
                  {
                    sub_5008C2(v27, 16, v26, (int (__thiscall *)(int))sub_5007EC);
                    v28 = *(void **)(a1 - 72);
                  }
                  else
                  {
                    v28 = 0;
                  }
                  *(_DWORD *)(a1 - 4) = -1;
                  *v24 = v28;
                  if ( !v28 )
                    goto LABEL_54;
                  v22 = *(_DWORD **)(a1 - 24);
                }
                memset(*v24, 0, 16 * v2[1][1046] * v2[1][1047]);
              }
              *(_DWORD *)(a1 - 16) += 8;
            }
            while ( *(_DWORD *)(a1 - 16) < (unsigned int)v22 );
          }
          v29 = *(_DWORD *)(a1 - 44);
          *(_DWORD *)(a1 - 56) = 0;
          v29 += 4;
          v30 = v29 < *(_DWORD *)(a1 - 80);
          *(_DWORD *)(a1 - 60) = v29;
          if ( v30 )
          {
            do
            {
              v52 = *(_DWORD *)(a1 - 28);
              v51 = *(_DWORD *)(a1 - 64);
              v31 = *v2;
              v50 = *(_DWORD *)(a1 - 56);
              v32 = *(_DWORD *)(a1 - 60) + **(_DWORD **)(a1 - 60);
              v33 = **v2;
              *(_DWORD *)(a1 - 72) = v32;
              (*(void (__thiscall **)(int *, int, int, int))(v33 + 4))(v31, v50, v51, v52);
              v34 = *(_DWORD *)(a1 - 68) + 4;
              v30 = v34 < *(_DWORD *)(a1 - 76);
              *(_DWORD *)(a1 - 52) = v34;
              if ( v30 )
              {
                v35 = (float *)(*(_DWORD *)(a1 - 28) + 8);
                do
                {
                  v36 = *(_DWORD *)(a1 - 52) + **(_DWORD **)(a1 - 52);
                  v37 = *(_DWORD **)(a1 - 84);
                  *(_DWORD *)(a1 - 48) = v36;
                  while ( 1 )
                  {
                    v30 = (unsigned int)v37 < *(_DWORD *)(a1 - 24);
                    *(_DWORD *)(a1 - 16) = v37;
                    if ( !v30 )
                      break;
                    v38 = *(_DWORD *)(a1 - 60) + 4;
                    if ( v38 < v32 )
                    {
                      do
                      {
                        v39 = *(_DWORD *)(*(_DWORD *)(a1 - 20) + 12 * *v37) + 16 * *(_DWORD *)v38 * v2[1][1046];
                        for ( j = *(_DWORD *)(a1 - 52) + 4; j < *(_DWORD *)(a1 - 48); j += 8 )
                        {
                          v41 = *(float *)(j + 4) * *(float *)(v38 + 4) * *(float *)(*(_DWORD *)(a1 - 16) + 4);
                          *(float *)(v39 + 16 * *(_DWORD *)j) = v41 * *(v35 - 2) + *(float *)(v39 + 16 * *(_DWORD *)j);
                          *(float *)(16 * *(_DWORD *)j + v39 + 4) = v41 * *(v35 - 1)
                                                                  + *(float *)(16 * *(_DWORD *)j + v39 + 4);
                          *(float *)(16 * *(_DWORD *)j + v39 + 8) = v41 * *v35 + *(float *)(16 * *(_DWORD *)j + v39 + 8);
                          v42 = (float *)(16 * *(_DWORD *)j + v39 + 12);
                          *v42 = v41 * v35[1] + *v42;
                        }
                        v37 = *(_DWORD **)(a1 - 16);
                        v38 += 8;
                      }
                      while ( v38 < *(_DWORD *)(a1 - 72) );
                      v32 = *(_DWORD *)(a1 - 72);
                      v36 = *(_DWORD *)(a1 - 48);
                    }
                    v37 += 2;
                  }
                  v35 += 4;
                  v30 = v36 < *(_DWORD *)(a1 - 76);
                  *(_DWORD *)(a1 - 52) = v36;
                }
                while ( v30 );
              }
              ++*(_DWORD *)(a1 - 56);
              v30 = v32 < *(_DWORD *)(a1 - 80);
              *(_DWORD *)(a1 - 60) = v32;
            }
            while ( v30 );
            v22 = *(_DWORD **)(a1 - 24);
          }
          for ( k = *(_DWORD **)(a1 - 84); k < v22; k += 2 )
          {
            v44 = (_DWORD *)(*(_DWORD *)(a1 - 20) + 12 * *k);
            if ( v44[2]-- == 1 )
            {
              v46 = v2[1];
              *(_DWORD *)(a1 - 16) = 0;
              if ( v46[1047] )
              {
                do
                {
                  (*(void (__stdcall **)(_DWORD, _DWORD, int))(*v46 + 8))(
                    *(_DWORD *)(a1 - 16),
                    *k,
                    *v44 + 16 * *(_DWORD *)(a1 - 16) * v46[1046]);
                  ++*(_DWORD *)(a1 - 16);
                  v46 = v2[1];
                }
                while ( *(_DWORD *)(a1 - 16) < (unsigned int)v46[1047] );
                v22 = *(_DWORD **)(a1 - 24);
              }
              v44[1] = *(_DWORD *)(a1 - 32);
              *(_DWORD *)(a1 - 32) = v44;
            }
          }
          ++*(_DWORD *)(a1 - 64);
          v21 = v22;
        }
        while ( (unsigned int)v22 < *(_DWORD *)(a1 - 36) );
      }
      v47 = 0;
    }
    else
    {
LABEL_54:
      v47 = -2147024882;
    }
  }
  else
  {
    v47 = -2147467259;
  }
  v48 = *(LPVOID **)(a1 - 88);
  if ( v48 )
    sub_502EE5(v48, 3);
  sub_587BCF(*(LPVOID *)(a1 - 40));
  sub_587BCF(*(LPVOID *)(a1 - 44));
  sub_587BCF(*(LPVOID *)(a1 - 68));
  sub_587BCF(*(LPVOID *)(a1 - 92));
  sub_587BCF(0);
  return v47;
}
