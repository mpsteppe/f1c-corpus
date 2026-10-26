int __usercall sub_506003@<eax>(int a1@<ebp>)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // ebx
  int v3; // edx
  bool v4; // zf
  BOOL v5; // edi
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  unsigned int v8; // edi
  int v9; // esi
  _DWORD *v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // eax
  _DWORD *v15; // ecx
  _DWORD *v16; // edx
  _DWORD *i; // ecx
  _DWORD *v18; // eax
  _DWORD *v19; // eax
  _DWORD *v20; // esi
  _DWORD *v21; // eax
  void **v22; // edi
  void **v23; // eax
  int v24; // esi
  int v25; // eax
  void *v26; // eax
  int v27; // edi
  _DWORD *v28; // eax
  float *v29; // edx
  _DWORD *v30; // ecx
  _DWORD *v31; // edi
  int v32; // ecx
  unsigned int v33; // eax
  double v34; // st7
  float *v35; // esi
  _DWORD *v36; // edi
  _DWORD *v37; // esi
  int v38; // esi
  LPVOID *v39; // ecx

  SEHHandlerInit();
  v2 = v1;
  v3 = v1[1];
  v4 = *(_DWORD *)(v3 + 4192) == 1;
  *(_DWORD *)(a1 - 32) = 0;
  *(_DWORD *)(a1 - 52) = 0;
  *(_DWORD *)(a1 - 24) = 0;
  *(_DWORD *)(a1 - 60) = 0;
  if ( !v4 || *(_DWORD *)(*v1 + 4192) != 1 )
    return -2147467259;
  v5 = ((v1[2] >> 17) & 1) == 0;
  v6 = ComplexMemoryAllocationWithFloatComputation(
         *(_DWORD *)(*v1 + 4184),
         *(_DWORD *)(v3 + 4184),
         (v1[2] & 0x10000) == 0);
  *(_DWORD *)(a1 - 56) = v6;
  if ( v6
    && (v7 = ComplexMemoryAllocationWithFloatComputation(*(_DWORD *)(*v2 + 4188), *(_DWORD *)(v2[1] + 4188), v5),
        (*(_DWORD *)(a1 - 32) = v7) != 0) )
  {
    *(_DWORD *)(a1 - 44) = (char *)v6 + *v6;
    v8 = *(_DWORD *)(a1 - 32) + **(_DWORD **)(a1 - 32);
    v9 = *(_DWORD *)(v2[1] + 4188);
    *(_DWORD *)(a1 - 68) = v8;
    v10 = (_DWORD *)OperatorNewNhMallocWrapper(12 * v9 + 4);
    *(_DWORD *)(a1 - 64) = v10;
    *(_DWORD *)(a1 - 4) = 0;
    if ( v10 )
    {
      *v10 = v9;
      *(_DWORD *)(a1 - 52) = v10 + 1;
      NTimeCallbackLoopWithSEH_a6eb(v10 + 1, 12, v9, TripleDwordZeroInit, FreeWrapper);
      v11 = *(_DWORD *)(a1 - 52);
      *(_DWORD *)(a1 - 20) = v11;
    }
    else
    {
      *(_DWORD *)(a1 - 20) = 0;
      v11 = *(_DWORD *)(a1 - 20);
    }
    *(_DWORD *)(a1 - 4) = -1;
    *(_DWORD *)(a1 - 52) = v11;
    if ( !v11 )
      goto LABEL_47;
    v12 = *(_DWORD *)(*v2 + 4184);
    v13 = OperatorNewNhMallocWrapper(16 * v12);
    *(_DWORD *)(a1 - 60) = v13;
    *(_DWORD *)(a1 - 4) = 1;
    if ( v13 )
    {
      sub_5008C2(v13, 16, v12, (int (__thiscall *)(int))sub_5007EC);
      v14 = *(_DWORD *)(a1 - 60);
      *(_DWORD *)(a1 - 36) = v14;
    }
    else
    {
      *(_DWORD *)(a1 - 36) = 0;
      v14 = *(_DWORD *)(a1 - 36);
    }
    *(_DWORD *)(a1 - 4) = -1;
    *(_DWORD *)(a1 - 60) = v14;
    if ( v14 )
    {
      v15 = (_DWORD *)(*(_DWORD *)(a1 - 32) + 4);
      *(_DWORD *)(a1 - 48) = v15;
      if ( (unsigned int)v15 < v8 )
      {
        do
        {
          v16 = (_DWORD *)((char *)v15 + *v15);
          for ( i = v15 + 1; i < v16; i += 2 )
          {
            v18 = (_DWORD *)(*(_DWORD *)(a1 - 20) + 12 * *i + 8);
            ++*v18;
          }
          v15 = v16;
        }
        while ( (unsigned int)v16 < v8 );
      }
      v19 = *(_DWORD **)(a1 - 48);
      *(_DWORD *)(a1 - 40) = 0;
      if ( (unsigned int)v19 < v8 )
      {
        do
        {
          v20 = (_DWORD *)((char *)v19 + *v19);
          v21 = v19 + 1;
          *(_DWORD *)(a1 - 28) = v20;
          *(_DWORD *)(a1 - 48) = v21;
          while ( 1 )
          {
            *(_DWORD *)(a1 - 16) = v21;
            if ( v21 >= v20 )
              break;
            v22 = (void **)(*(_DWORD *)(a1 - 20) + 12 * *v21);
            if ( !*v22 )
            {
              v23 = *(void ***)(a1 - 24);
              if ( v23 )
              {
                *v22 = *v23;
                *v23 = 0;
                *(_DWORD *)(a1 - 24) = v23[1];
              }
              else
              {
                v24 = *(_DWORD *)(v2[1] + 4184);
                v25 = OperatorNewNhMallocWrapper(16 * v24);
                *(_DWORD *)(a1 - 64) = v25;
                *(_DWORD *)(a1 - 4) = 2;
                if ( v25 )
                {
                  sub_5008C2(v25, 16, v24, (int (__thiscall *)(int))sub_5007EC);
                  v26 = *(void **)(a1 - 64);
                }
                else
                {
                  v26 = 0;
                }
                *(_DWORD *)(a1 - 4) = -1;
                *v22 = v26;
                if ( !v26 )
                  goto LABEL_47;
              }
              v20 = *(_DWORD **)(a1 - 28);
              memset(*v22, 0, 16 * *(_DWORD *)(v2[1] + 4184));
            }
            v21 = (_DWORD *)(*(_DWORD *)(a1 - 16) + 8);
          }
          v27 = *(_DWORD *)(a1 - 36);
          (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, int))(*(_DWORD *)*v2 + 4))(*v2, *(_DWORD *)(a1 - 40), 0, v27);
          v28 = (_DWORD *)(*(_DWORD *)(a1 - 56) + 4);
          if ( (unsigned int)v28 < *(_DWORD *)(a1 - 44) )
          {
            v29 = (float *)(v27 + 8);
            do
            {
              v30 = *(_DWORD **)(a1 - 48);
              v31 = (_DWORD *)((char *)v28 + *v28);
              *(_DWORD *)(a1 - 16) = v30;
              if ( v30 < v20 )
              {
                *(_DWORD *)(a1 - 64) = v28 + 1;
                while ( 1 )
                {
                  v32 = *(_DWORD *)(*(_DWORD *)(a1 - 20) + 12 * *v30);
                  v33 = *(_DWORD *)(a1 - 64);
                  if ( v33 < (unsigned int)v31 )
                  {
                    do
                    {
                      v34 = *(float *)(v33 + 4) * *(float *)(*(_DWORD *)(a1 - 16) + 4);
                      *(float *)(v32 + 16 * *(_DWORD *)v33) = v34 * *(v29 - 2) + *(float *)(v32 + 16 * *(_DWORD *)v33);
                      *(float *)(16 * *(_DWORD *)v33 + v32 + 4) = v34 * *(v29 - 1)
                                                                + *(float *)(16 * *(_DWORD *)v33 + v32 + 4);
                      *(float *)(16 * *(_DWORD *)v33 + v32 + 8) = v34 * *v29 + *(float *)(16 * *(_DWORD *)v33 + v32 + 8);
                      v35 = (float *)(16 * *(_DWORD *)v33 + v32 + 12);
                      v33 += 8;
                      *v35 = v34 * v29[1] + *v35;
                    }
                    while ( v33 < (unsigned int)v31 );
                    v20 = *(_DWORD **)(a1 - 28);
                  }
                  *(_DWORD *)(a1 - 16) += 8;
                  if ( *(_DWORD *)(a1 - 16) >= (unsigned int)v20 )
                    break;
                  v30 = *(_DWORD **)(a1 - 16);
                }
              }
              v29 += 4;
              v28 = v31;
            }
            while ( (unsigned int)v31 < *(_DWORD *)(a1 - 44) );
          }
          v36 = *(_DWORD **)(a1 - 48);
          if ( v36 < v20 )
          {
            do
            {
              v37 = (_DWORD *)(*(_DWORD *)(a1 - 20) + 12 * *v36);
              v4 = v37[2]-- == 1;
              if ( v4 )
              {
                (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2[1] + 8))(v2[1], *v36, 0, *v37);
                v37[1] = *(_DWORD *)(a1 - 24);
                *(_DWORD *)(a1 - 24) = v37;
              }
              v36 += 2;
            }
            while ( (unsigned int)v36 < *(_DWORD *)(a1 - 28) );
            v20 = *(_DWORD **)(a1 - 28);
          }
          ++*(_DWORD *)(a1 - 40);
          v19 = v20;
        }
        while ( (unsigned int)v20 < *(_DWORD *)(a1 - 68) );
      }
      v38 = 0;
    }
    else
    {
LABEL_47:
      v38 = -2147024882;
    }
  }
  else
  {
    v38 = -2147467259;
  }
  v39 = *(LPVOID **)(a1 - 52);
  if ( v39 )
    ConditionalFree_2ee5(v39, 3);
  FreeWrapper_7bcf(*(LPVOID *)(a1 - 32));
  FreeWrapper_7bcf(*(LPVOID *)(a1 - 56));
  FreeWrapper_7bcf(*(LPVOID *)(a1 - 60));
  FreeWrapper_7bcf(0);
  return v38;
}
