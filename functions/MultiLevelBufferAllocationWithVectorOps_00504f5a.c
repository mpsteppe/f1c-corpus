int __usercall sub_504F5A@<eax>(int a1@<ebx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  int v4; // ecx
  _DWORD *v5; // ebx
  _DWORD *v7; // ecx
  unsigned int v8; // eax
  _DWORD *v9; // edx
  int v10; // esi
  int v11; // esi
  _DWORD *v12; // ecx
  _DWORD *v13; // ecx
  int v14; // esi
  int v15; // eax
  int v16; // esi
  int v17; // esi
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // esi
  int v22; // edx
  int v23; // esi
  int v24; // eax
  int v25; // edx
  int v26; // esi
  bool v27; // zf
  int v28; // eax
  int v29; // eax
  int v30; // edi
  int v31; // eax
  int v32; // eax
  int v33; // eax
  float *v34; // ecx
  float *v35; // edx
  double v36; // st6
  double v37; // st5
  double v38; // st6
  double v39; // st5
  float *v40; // ecx
  double v41; // st6
  double v42; // st5
  float *v43; // ecx
  double v44; // st5
  float *v45; // ecx
  double v46; // st6
  double v47; // st5
  float *v48; // ecx
  double v49; // st5
  _DWORD *v50; // edi
  double v51; // st6
  double v52; // st5
  double v53; // st4
  float *v54; // eax
  unsigned int v55; // ecx
  double v56; // st6
  double v57; // st5

  SEHHandlerInit();
  v5 = (_DWORD *)v4;
  if ( *(_BYTE *)(v4 + 8) != 5 )
    return -2147467259;
  v7 = *(_DWORD **)v4;
  v8 = *(_DWORD *)(*v5 + 4184);
  v9 = (_DWORD *)v5[1];
  v10 = v9[1046];
  if ( v10 != v8 >> 1 && (v10 != 1 || v8 != 1) )
    return -2147467259;
  v11 = v9[1047];
  if ( v11 != v7[1047] >> 1 && (v11 != 1 || v7[1047] != 1) )
    return -2147467259;
  if ( v9[1048] != v7[1048] >> 1 )
    return -2147467259;
  if ( v8 > 1 && (v8 & 1) != 0 )
  {
    v7[1046] = v8 & 0xFFFFFFFE;
    *(_DWORD *)(*v5 + 4196) -= *(_DWORD *)(*v5 + 4200);
  }
  v12 = (_DWORD *)(*v5 + 4188);
  if ( *v12 > 1u )
    *v12 &= ~1u;
  v13 = (_DWORD *)(*v5 + 4192);
  if ( *v13 > 1u )
    *v13 &= ~1u;
  v14 = *(_DWORD *)(v5[1] + 4184);
  v15 = OperatorNewNhMallocWrapper(16 * v14);
  *(_DWORD *)(a2 - 20) = v15;
  *(_DWORD *)(a2 - 4) = 0;
  if ( v15 )
  {
    sub_5008C2(v15, 16, v14, (int (__thiscall *)(int))sub_5007EC);
    *(_DWORD *)(a2 - 32) = *(_DWORD *)(a2 - 20);
  }
  else
  {
    *(_DWORD *)(a2 - 32) = 0;
  }
  *(_DWORD *)(a2 - 4) = -1;
  if ( !*(_DWORD *)(a2 - 32) )
    return -2147024882;
  v16 = *(_DWORD *)(*v5 + 4184);
  if ( *(_DWORD *)(*v5 + 4188) == 1 )
  {
    v17 = 2 * v16;
    v18 = OperatorNewNhMallocWrapper(16 * v17);
    *(_DWORD *)(a2 - 20) = v18;
    *(_DWORD *)(a2 - 4) = 1;
    if ( v18 )
    {
      sub_5008C2(v18, 16, v17, (int (__thiscall *)(int))sub_5007EC);
      v19 = *(_DWORD *)(a2 - 20);
    }
    else
    {
      v19 = 0;
    }
    v20 = *(_DWORD *)(*v5 + 4184);
    *(_DWORD *)(a2 - 4) = -1;
    v21 = v19 + 16 * v20;
    v22 = v21;
    *(_DWORD *)(a2 - 56) = v19;
    *(_DWORD *)(a2 - 24) = v19;
    *(_DWORD *)(a2 - 48) = v21;
    *(_DWORD *)(a2 - 28) = v19;
    *(_DWORD *)(a2 - 40) = v21;
  }
  else
  {
    v23 = 4 * v16;
    v24 = OperatorNewNhMallocWrapper(16 * v23);
    *(_DWORD *)(a2 - 20) = v24;
    *(_DWORD *)(a2 - 4) = 2;
    if ( v24 )
    {
      sub_5008C2(v24, 16, v23, (int (__thiscall *)(int))sub_5007EC);
      v25 = *(_DWORD *)(a2 - 20);
    }
    else
    {
      v25 = 0;
    }
    v20 = *(_DWORD *)(*v5 + 4184);
    *(_DWORD *)(a2 - 4) = -1;
    *(_DWORD *)(a2 - 48) = v25 + 16 * v20;
    v21 = *(_DWORD *)(a2 - 48);
    *(_DWORD *)(a2 - 28) = v25 + 32 * v20;
    *(_DWORD *)(a2 - 40) = v25 + 48 * v20;
    v19 = *(_DWORD *)(a2 - 28);
    *(_DWORD *)(a2 - 56) = v25;
    *(_DWORD *)(a2 - 24) = v25;
    v22 = *(_DWORD *)(a2 - 40);
  }
  if ( *(_DWORD *)(a2 - 56) )
  {
    v27 = v20 == 1;
    v28 = *(_DWORD *)(a2 - 24);
    if ( v27 )
    {
      *(_DWORD *)(a2 - 60) = v28;
      *(_DWORD *)(a2 - 64) = v21;
    }
    else
    {
      *(_DWORD *)(a2 - 60) = v28 + 16;
      v19 += 16;
      *(_DWORD *)(a2 - 64) = v21 + 16;
      v22 += 16;
    }
    v29 = v5[1];
    *(_DWORD *)(a2 - 36) = 0;
    v27 = *(_DWORD *)(v29 + 4192) == 0;
    *(_DWORD *)(a2 - 68) = v19;
    *(_DWORD *)(a2 - 20) = v22;
    if ( !v27 )
    {
      do
      {
        *(_DWORD *)(a2 - 16) = 0;
        if ( *(_DWORD *)(v29 + 4188) )
        {
          do
          {
            v30 = 2 * *(_DWORD *)(a2 - 36);
            (*(void (__thiscall **)(_DWORD, int, int, _DWORD, int, int, int))(*(_DWORD *)*v5 + 4))(
              *v5,
              2 * *(_DWORD *)(a2 - 16),
              v30,
              *(_DWORD *)(a2 - 24),
              a3,
              a4,
              a1);
            if ( v21 != *(_DWORD *)(a2 - 24) )
              (*(void (__thiscall **)(_DWORD, int, int, int))(*(_DWORD *)*v5 + 4))(
                *v5,
                2 * *(_DWORD *)(a2 - 16),
                v30 + 1,
                v21);
            if ( *(_DWORD *)(a2 - 28) != *(_DWORD *)(a2 - 24) )
              (*(void (__thiscall **)(_DWORD, int, int, _DWORD))(*(_DWORD *)*v5 + 4))(
                *v5,
                2 * *(_DWORD *)(a2 - 16) + 1,
                v30,
                *(_DWORD *)(a2 - 28));
            v31 = *(_DWORD *)(a2 - 40);
            if ( v31 != v21 && v31 != *(_DWORD *)(a2 - 28) )
              (*(void (__thiscall **)(_DWORD, int, int, _DWORD))(*(_DWORD *)*v5 + 4))(
                *v5,
                2 * *(_DWORD *)(a2 - 16) + 1,
                v30 + 1,
                *(_DWORD *)(a2 - 40));
            v32 = v5[1];
            *(_DWORD *)(a2 - 44) = 0;
            if ( *(_DWORD *)(v32 + 4184) )
            {
              *(_DWORD *)(a2 - 52) = *(_DWORD *)(a2 - 32);
              do
              {
                v33 = 32 * *(_DWORD *)(a2 - 44);
                v34 = (float *)(v33 + *(_DWORD *)(a2 - 60));
                v35 = (float *)(v33 + *(_DWORD *)(a2 - 24));
                v36 = *v34 + *v35;
                v37 = v34[1] + v35[1];
                *(float *)(a2 - 140) = v34[2] + v35[2];
                *(float *)(a2 - 136) = v34[3] + v35[3];
                *(float *)(a2 - 180) = v36 + *(float *)(v33 + v21);
                v38 = v37 + *(float *)(v33 + v21 + 4);
                v39 = *(float *)(a2 - 140) + *(float *)(v33 + v21 + 8);
                v40 = (float *)(v33 + *(_DWORD *)(a2 - 64));
                *(float *)(a2 - 168) = *(float *)(a2 - 136) + *(float *)(v33 + v21 + 12);
                *(float *)(a2 - 132) = *(float *)(a2 - 180) + *v40;
                *(float *)(a2 - 128) = v38 + v40[1];
                v41 = v39 + v40[2];
                v42 = *(float *)(a2 - 168) + v40[3];
                v43 = (float *)(v33 + *(_DWORD *)(a2 - 28));
                *(float *)(a2 - 84) = *(float *)(a2 - 132) + *v43;
                *(float *)(a2 - 80) = *(float *)(a2 - 128) + v43[1];
                *(float *)(a2 - 76) = v41 + v43[2];
                v44 = v42 + v43[3];
                v45 = (float *)(v33 + *(_DWORD *)(a2 - 68));
                v46 = v44;
                v47 = *(float *)(a2 - 84) + *v45;
                *(float *)(a2 - 96) = *(float *)(a2 - 80) + v45[1];
                *(float *)(a2 - 92) = *(float *)(a2 - 76) + v45[2];
                *(float *)(a2 - 88) = v46 + v45[3];
                v48 = (float *)(v33 + *(_DWORD *)(a2 - 40));
                v49 = v47 + *v48;
                v50 = *(_DWORD **)(a2 - 52);
                *(_DWORD *)(a2 - 52) = v50 + 4;
                v51 = v49;
                v52 = *(float *)(a2 - 96) + v48[1];
                *(float *)(a2 - 156) = *(float *)(a2 - 92) + v48[2];
                v53 = *(float *)(a2 - 88) + v48[3];
                v54 = (float *)(*(_DWORD *)(a2 - 20) + v33);
                ++*(_DWORD *)(a2 - 44);
                *(float *)(a2 - 152) = v53;
                v55 = *(_DWORD *)(a2 - 44);
                *(float *)(a2 - 196) = v51 + *v54;
                v56 = v52 + v54[1];
                v57 = *(float *)(a2 - 156) + v54[2];
                *(float *)(a2 - 184) = *(float *)(a2 - 152) + v54[3];
                *(float *)(a2 - 116) = *(float *)(a2 - 196) * 0.125;
                *(float *)(a2 - 112) = v56 * 0.125;
                *(float *)(a2 - 108) = v57 * 0.125;
                *(float *)(a2 - 104) = *(float *)(a2 - 184) * 0.125;
                *v50++ = *(_DWORD *)(a2 - 116);
                *v50++ = *(_DWORD *)(a2 - 116 + 4);
                *v50 = *(_DWORD *)(a2 - 116 + 8);
                v50[1] = *(_DWORD *)(a2 - 116 + 12);
                v21 = *(_DWORD *)(a2 - 48);
              }
              while ( v55 < *(_DWORD *)(v5[1] + 4184) );
            }
            a1 = *(_DWORD *)(a2 - 32);
            a4 = *(_DWORD *)(a2 - 36);
            a3 = *(_DWORD *)(a2 - 16);
            (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v5[1] + 8))(v5[1]);
            ++*(_DWORD *)(a2 - 16);
          }
          while ( *(_DWORD *)(a2 - 16) < *(_DWORD *)(v5[1] + 4188) );
        }
        ++*(_DWORD *)(a2 - 36);
        v29 = v5[1];
      }
      while ( *(_DWORD *)(a2 - 36) < *(_DWORD *)(v29 + 4192) );
    }
    FreeWrapper_7bcf(*(LPVOID *)(a2 - 56));
    v26 = 0;
  }
  else
  {
    v26 = -2147024882;
  }
  FreeWrapper_7bcf(*(LPVOID *)(a2 - 32));
  return v26;
}
