void __userpurge sub_4F6590(int *a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4)
{
  bool v5; // zf
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // esi
  double v14; // st7
  float v15; // ecx
  int v16; // esi
  double v17; // st7
  float v18; // eax
  int v19; // eax
  double v20; // st7
  float *v21; // eax
  double v22; // st6
  int v23; // edx
  _DWORD *v24; // eax
  int v25; // edx
  int v26; // ecx
  int v27; // eax
  int v28; // eax
  int *v29; // ecx
  int v30; // edx
  _DWORD *v31; // esi
  int v32; // eax
  int v33; // eax
  int *v34; // ecx
  int v35; // edx
  _DWORD *v36; // esi
  int v37; // eax
  int v38; // eax
  int *v39; // ecx
  int v40; // edx
  _DWORD *v41; // esi
  double v42; // st7
  int v43; // edi
  int v44; // eax
  bool v45; // cc
  int v46; // edx
  int v47; // eax
  int v48; // ecx
  float v49; // ecx
  int v50; // ecx
  int v51; // eax
  _DWORD *i; // esi
  int v53; // esi
  int v54; // ecx
  int v55; // edx
  _DWORD *v56; // ecx
  int v57; // eax
  int v58; // eax
  int v59; // eax
  int v60; // ecx
  int v61; // edx
  int v62; // esi
  int v63; // eax
  int v64; // ecx
  int v65; // ebp
  int *v66; // [esp+0h] [ebp-90h]
  _BYTE v67[8]; // [esp+24h] [ebp-6Ch] BYREF
  int v68; // [esp+2Ch] [ebp-64h] BYREF
  int v69; // [esp+30h] [ebp-60h]
  int v70; // [esp+34h] [ebp-5Ch] BYREF
  int v71; // [esp+38h] [ebp-58h] BYREF
  int v72; // [esp+3Ch] [ebp-54h]
  int v73; // [esp+40h] [ebp-50h]
  float v74[19]; // [esp+44h] [ebp-4Ch] BYREF
  int v75; // [esp+94h] [ebp+4h]

  v5 = *(_BYTE *)a4 == 0;
  *((_BYTE *)a1 + 8) = *(_BYTE *)a4;
  if ( !v5 )
  {
    v7 = a1[34];
    if ( v7 )
    {
      if ( *(_BYTE *)(a4 + 1) )
        sub_5DB590(v7);
      else
        sub_5DB5A0(a2, a3);
    }
    *((_BYTE *)a1 + 12) = *(_BYTE *)(a4 + 2);
    *((_BYTE *)a1 + 13) = *(_BYTE *)(a4 + 3);
    *((_BYTE *)a1 + 14) = *(_BYTE *)(a4 + 4);
    a1[21] = *(_DWORD *)(a4 + 8);
    a1[22] = *(_DWORD *)(a4 + 12);
    a1[23] = *(_DWORD *)(a4 + 16);
    a1[24] = *(_DWORD *)(a4 + 20);
    a1[25] = *(_DWORD *)(a4 + 24);
    a1[26] = *(_DWORD *)(a4 + 28);
    sub_4F4440();
    a1[30] = *(_DWORD *)(a4 + 32);
    a1[31] = *(_DWORD *)(a4 + 36);
    a1[32] = *(_DWORD *)(a4 + 40);
    a1[33] = *(_DWORD *)(a4 + 44);
    a1[46] = 0;
    v8 = *(_DWORD *)(a4 + 68);
    v9 = *(_DWORD *)(a4 + 60);
    v68 = *(_DWORD *)(a4 + 72);
    v10 = v8;
    v75 = v8;
    v69 = v9;
    v11 = *(_DWORD *)(a4 + 64);
    v72 = v68;
    v12 = *a1;
    v5 = *a1 == 7;
    v70 = v11;
    v71 = v10;
    v73 = v69;
    if ( (v5 || v12 == 8) && (v13 = *(_DWORD *)a1[58]) != 0 )
    {
      sub_4F2340((float *)&v70, v74);
      v14 = *(float *)(a4 + 56);
      v15 = *(float *)(a4 + 48);
      v74[13] = *(float *)(a4 + 52);
      v74[12] = v15;
      v74[14] = v14;
      qmemcpy((void *)(v13 + 4), v74, 0x40u);
    }
    else
    {
      v16 = a1[34];
      if ( v16 )
      {
        sub_4F2340((float *)&v70, v74);
        v17 = *(float *)(a4 + 56);
        v18 = *(float *)(a4 + 48);
        v74[13] = *(float *)(a4 + 52);
        v74[12] = v18;
        v74[14] = v17;
        qmemcpy((void *)(v16 + 76), v74, 0x40u);
        *(_DWORD *)a1[34] |= 0x40u;
      }
      v19 = a1[35];
      if ( v19 )
      {
        v20 = *(float *)(a4 + 56);
        v21 = *(float **)(v19 + 8);
        v22 = *(float *)(a4 + 52);
        v23 = v70;
        v21[57] = *(float *)(a4 + 48);
        v21[58] = v22;
        v21[59] = v20;
        v24 = *(_DWORD **)(a1[35] + 8);
        v24[53] = v23;
        v25 = v68;
        v24[54] = v75;
        v26 = v69;
        v24[55] = v25;
        v24[56] = v26;
      }
    }
    v27 = *(_DWORD *)(a4 + 76);
    if ( v27 == -1 )
    {
      v31 = (_DWORD *)a1[54];
      if ( v31 )
      {
        (*(void (__thiscall **)(_DWORD *, _DWORD))(*v31 + 20))(v31, 0);
        v31[5] = 0;
      }
      a1[48] = 0;
    }
    else
    {
      v28 = *(_DWORD *)(a1[1] + 292) + 768 * v27;
      a1[48] = v28;
      if ( v28 )
      {
        v29 = (int *)a1[54];
        if ( v29 )
        {
          v30 = *v29;
          v29[5] = v28;
          (*(void (__cdecl **)(int))(v30 + 20))(1);
        }
      }
    }
    v32 = *(_DWORD *)(a4 + 80);
    if ( v32 == -1 )
    {
      v36 = (_DWORD *)a1[55];
      if ( v36 )
      {
        (*(void (__thiscall **)(_DWORD *, _DWORD))(*v36 + 20))(v36, 0);
        v36[5] = 0;
      }
      a1[49] = 0;
    }
    else
    {
      v33 = 768 * v32 + *(_DWORD *)(a1[1] + 292);
      a1[49] = v33;
      if ( v33 )
      {
        v34 = (int *)a1[55];
        if ( v34 )
        {
          v35 = *v34;
          v34[5] = v33;
          (*(void (__cdecl **)(int))(v35 + 20))(1);
        }
      }
    }
    v37 = *(_DWORD *)(a4 + 84);
    if ( v37 == -1 )
    {
      v41 = (_DWORD *)a1[56];
      if ( v41 )
      {
        (*(void (__thiscall **)(_DWORD *, _DWORD))(*v41 + 20))(v41, 0);
        v41[5] = 0;
      }
      a1[50] = 0;
    }
    else
    {
      v38 = 768 * v37 + *(_DWORD *)(a1[1] + 292);
      a1[50] = v38;
      if ( v38 )
      {
        v39 = (int *)a1[56];
        if ( v39 )
        {
          v40 = *v39;
          v39[5] = v38;
          (*(void (__cdecl **)(int))(v40 + 20))(1);
        }
      }
    }
    *((_BYTE *)a1 + 240) = *(_BYTE *)(a4 + 88);
    a1[61] = *(_DWORD *)(a4 + 92);
    a1[62] = *(_DWORD *)(a4 + 96);
    a1[63] = *(_DWORD *)(a4 + 100);
    a1[64] = *(_DWORD *)(a4 + 104);
    a1[65] = *(_DWORD *)(a4 + 108);
    a1[66] = *(_DWORD *)(a4 + 112);
    a1[67] = *(_DWORD *)(a4 + 116);
    qmemcpy(a1 + 68, (const void *)(a4 + 120), 0x3Cu);
    qmemcpy(a1 + 83, (const void *)(a4 + 180), 0x3Cu);
    qmemcpy(a1 + 98, (const void *)(a4 + 240), 0x3Cu);
    qmemcpy(a1 + 113, (const void *)(a4 + 300), 0x3Cu);
    qmemcpy(a1 + 128, (const void *)(a4 + 360), 0x3Cu);
    qmemcpy(a1 + 143, (const void *)(a4 + 420), 0x3Cu);
    qmemcpy(a1 + 158, (const void *)(a4 + 480), 0x3Cu);
    qmemcpy(a1 + 173, (const void *)(a4 + 540), 0x3Cu);
    v5 = *a1 == 9;
    a1[188] = *(_DWORD *)(a4 + 600);
    if ( v5 )
    {
      v42 = *(float *)(a4 + 604);
      a1[191] = *(int *)(a4 + 604);
      if ( a1[189] )
        sub_5EC5C0(&byte_FFFFFF[0x1000000 * (unsigned int)(unsigned __int64)(v42 * 254.0 + 0.5)]);
      if ( a1[190] )
        sub_5EC5C0(&byte_FFFFFF[0x1000000 * (unsigned int)(unsigned __int64)(v42 * 254.0 + 0.5)]);
    }
    v43 = 0;
    if ( a1[35] )
    {
      sub_5BFC10(&v71);
      v44 = *(_DWORD *)(a4 + 636);
      v45 = v44 < a1[38];
      v74[15] = 0.0;
      if ( v45 )
      {
        v46 = a1[39];
        a1[41] = v44;
        v47 = v46 + 120 * v44;
        a1[40] = v47;
        v48 = *(_DWORD *)(a4 + 652);
        v72 = *(_DWORD *)(a4 + 660);
        LOBYTE(v46) = *(_BYTE *)(a4 + 664);
        v73 = v48;
        v49 = *(float *)(a4 + 672);
        BYTE2(v74[5]) = v46;
        v74[1] = v49;
        v50 = a1[35];
        v71 = 0;
        v51 = sub_5BBFE0(*(_DWORD *)(v50 + 8), *(_DWORD *)(v47 + 112), &v71);
        a1[42] = v51;
        if ( v51 )
        {
          *(_DWORD *)(v51 + 44) = *(_DWORD *)(a4 + 668);
          *(double *)a1[42] = *(float *)(a4 + 648);
          sub_5C24B0(0.0);
          *(double *)a1[42] = *(float *)(a4 + 644);
          *(double *)(a1[42] + 8) = -*(float *)(a4 + 640);
        }
      }
      for ( i = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(a1[35] + 8) + 532) + 8); *i; sub_5C21F0(i, 0) )
        ;
      v53 = a4 + 680;
      if ( *(int *)(a4 + 676) > 0 )
      {
        do
        {
          if ( *(_DWORD *)(a4 + 636) < a1[38] )
          {
            v54 = *(_DWORD *)(v53 + 20);
            v55 = *(_DWORD *)(v53 + 24);
            v70 = *(_DWORD *)(v53 + 16);
            v72 = *(_DWORD *)(v53 + 36);
            v68 = v54;
            LOBYTE(v54) = *(_BYTE *)(v53 + 28);
            v69 = v55;
            BYTE2(v74[2]) = v54;
            v66 = &v68;
            BYTE1(v74[2]) = 0;
            sub_405080();
          }
          ++v43;
          v53 += 40;
        }
        while ( v43 < *(_DWORD *)(a4 + 676) );
      }
      v74[10] = NAN;
      nullsub_7(v67);
    }
    v56 = (_DWORD *)a1[43];
    if ( v56 )
    {
      v57 = *(_DWORD *)(a4 + 608);
      if ( v57 == -1 )
      {
        (*(void (__thiscall **)(_DWORD *, _DWORD))(*v56 + 20))(v56, 0);
      }
      else
      {
        if ( v57 == 1 && *(_DWORD *)(a4 + 612) == a1[41] )
        {
          v58 = a1[42];
          v56[7] = 1;
          v56[8] = v58;
        }
        else if ( v57 == 2 && *(_DWORD *)(a4 + 612) == a1[41] )
        {
          v59 = a1[42];
          v56[7] = 2;
          v56[8] = v59;
        }
        else if ( v57 == 3 )
        {
          v56[7] = 3;
        }
        else
        {
          v56[7] = 0;
          v56[8] = 0;
          v56[6] = 0;
        }
        v60 = *(_DWORD *)(a4 + 616);
        v61 = *(_DWORD *)(a4 + 620);
        v62 = *(_DWORD *)(a4 + 624);
        v63 = a1[43];
        *(float *)(v63 + 56) = *(float *)(a4 + 628) * 0.01745433;
        *(_DWORD *)(v63 + 44) = v60;
        *(_DWORD *)(v63 + 48) = v61;
        *(_DWORD *)(v63 + 52) = v62;
        (*(void (__thiscall **)(int, int))(*(_DWORD *)a1[43] + 20))(a1[43], 1);
      }
    }
    v64 = a1[44];
    if ( v64 )
      (*(void (__thiscall **)(int, _DWORD, int *))(*(_DWORD *)v64 + 20))(v64, *(unsigned __int8 *)(a4 + 632), v66);
    v65 = a1[45];
    if ( v65 )
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v65 + 20))(v65, *(unsigned __int8 *)(a4 + 633));
  }
}
