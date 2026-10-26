void __thiscall sub_53F8A0(int this, int a2, float a3)
{
  double v4; // st7
  __int16 *v5; // ebp
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  double v10; // st7
  int v11; // esi
  int v12; // edx
  int v13; // eax
  int v14; // edx
  float v15; // edx
  float v16; // ecx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  float v20; // edx
  int v21; // ecx
  int v22; // eax
  int v23; // edx
  int v24; // ecx
  int v25; // eax
  int v26; // edx
  long double v27; // st7
  int i; // esi
  int v29; // eax
  int j; // esi
  int k; // esi
  int v32; // eax
  int v33; // ecx
  int v34; // edx
  int v35; // eax
  int v36; // ecx
  int v37; // edx
  int v38; // eax
  int v39; // ecx
  int m; // esi
  int n; // esi
  int v42; // eax
  float *v43; // eax
  int v44; // edx
  int v45; // ecx
  char v46; // al
  bool v47; // al
  int v48; // [esp-18h] [ebp-B4h]
  float v49; // [esp+4h] [ebp-98h]
  float *v50; // [esp+8h] [ebp-94h]
  float v51; // [esp+8h] [ebp-94h]
  float v52; // [esp+Ch] [ebp-90h]
  float v53; // [esp+10h] [ebp-8Ch]
  int v54; // [esp+10h] [ebp-8Ch]
  int v55; // [esp+14h] [ebp-88h] BYREF
  int v56; // [esp+18h] [ebp-84h]
  int v57; // [esp+1Ch] [ebp-80h]
  int v58; // [esp+20h] [ebp-7Ch] BYREF
  int v59; // [esp+24h] [ebp-78h]
  int v60; // [esp+28h] [ebp-74h]
  int v61; // [esp+2Ch] [ebp-70h]
  float v62; // [esp+30h] [ebp-6Ch] BYREF
  int v63; // [esp+34h] [ebp-68h]
  int v64; // [esp+38h] [ebp-64h]
  int v65; // [esp+3Ch] [ebp-60h]
  _DWORD v66[3]; // [esp+40h] [ebp-5Ch] BYREF
  float v67; // [esp+4Ch] [ebp-50h]
  float v68[3]; // [esp+50h] [ebp-4Ch] BYREF
  float v69; // [esp+5Ch] [ebp-40h]
  _BYTE v70[12]; // [esp+60h] [ebp-3Ch] BYREF
  float v71[3]; // [esp+6Ch] [ebp-30h] BYREF
  _BYTE v72[36]; // [esp+78h] [ebp-24h] BYREF

  v4 = a3 - *(float *)(this + 22568);
  *(float *)(this + 22568) = a3;
  v5 = (__int16 *)(a2 + 8);
  v53 = v4;
  v6 = *(_DWORD *)(a2 + 40);
  v7 = *(_DWORD *)(a2 + 44);
  v55 = *(_DWORD *)(a2 + 36);
  v56 = v6;
  v8 = *(_DWORD *)(a2 + 48);
  v57 = v7;
  v9 = *(_DWORD *)(a2 + 56);
  v66[1] = *(_DWORD *)(a2 + 52);
  v66[2] = v9;
  v66[0] = v8;
  sub_614A90(v66, v72);
  sub_569300(&v55, v66, v72);
  v10 = sub_51A1E0((_DWORD *)(a2 + 8));
  v49 = v10;
  if ( v10 >= -1.0 )
  {
    if ( v49 > 1.0 )
      v49 = 1.0;
    sub_56B6A0(v49);
  }
  else
  {
    v49 = -1.0;
    sub_56B6A0(-1.0);
  }
  v11 = 0;
  v50 = (float *)(this + 3308);
  v69 = v49 * *(float *)(this + 5704);
  do
  {
    sub_519FF0(v5, v11, &v62 + v11, (float *)&v58 + v11);
    v67 = v53 * *((float *)&v58 + v11) + *v50;
    if ( v11 >= 2 )
      sub_5693D0(v11, *(&v62 + v11), v67, 0.0);
    else
      sub_5693D0(v11, *(&v62 + v11), v67, v69);
    ++v11;
    v50 += 74;
  }
  while ( v11 < 4 );
  sub_519E70((_DWORD *)(a2 + 24), v68);
  sub_519ED0(a2 + 24, v71);
  sub_519FA0((int)v5, (int)v70);
  v51 = sub_51A170(v5);
  v52 = sub_51A190(v5);
  v12 = v55;
  *(float *)(this + 184) = v52;
  v13 = v56;
  *(_DWORD *)(this + 32) = v12;
  v14 = v57;
  *(_DWORD *)(this + 36) = v13;
  *(_DWORD *)(this + 40) = v14;
  v15 = v68[1];
  qmemcpy((void *)(this + 56), v72, 0x24u);
  *(float *)(this + 92) = v68[0];
  v16 = v68[2];
  *(float *)(this + 96) = v15;
  *(float *)(this + 100) = v16;
  *(float *)(this + 180) = v51;
  v17 = (*(_DWORD *)v5 >> 17) & 1;
  if ( *(_DWORD *)(this + 21788) != v17 && *(int *)(this + 14820) >= 3 )
    *(_DWORD *)(this + 21788) = v17;
  *(_BYTE *)(this + 5776) = (*(_DWORD *)v5 & 0x80) != 0;
  *(_BYTE *)(this + 5765) = (*(_DWORD *)(a2 + 12) & 0x2000000) != 0;
  v18 = sub_51A1D0(v5);
  v19 = *(_DWORD *)(this + 14820);
  v54 = v18;
  switch ( v19 )
  {
    case 2:
      *(float *)(this + 16152) = v49;
      sub_5735E0(&v55, v66, v72, v68, v71, v70, v18);
      sub_573730(SLODWORD(v51), 0.5, SLODWORD(v52));
      v20 = v62;
      v21 = v63;
      *(_DWORD *)(this + 16212) = v58;
      v22 = v64;
      *(float *)(this + 16180) = v20;
      v23 = v59;
      *(_DWORD *)(this + 16432) = v21;
      v24 = v60;
      *(_DWORD *)(this + 16684) = v22;
      v25 = v61;
      *(_DWORD *)(this + 16464) = v23;
      v26 = v65;
      *(_DWORD *)(this + 16716) = v24;
      *(_DWORD *)(this + 16968) = v25;
      *(_DWORD *)(this + 16936) = v26;
      v27 = fabs(a3 - *(float *)(this + 22564));
      *(_BYTE *)(this + 15572) = *(int *)(a2 + 12) < 0;
      if ( v27 > 15.0 )
      {
        *(float *)(this + 22564) = a3;
        for ( i = 0; i < 14; ++i )
        {
          v29 = sub_51A200(v5, i);
          sub_572490(i, v29);
        }
      }
      break;
    case 3:
      sub_573780(v72, v70);
      for ( j = 0; j < 4; ++j )
        sub_5691C0(j);
      for ( k = 0; k < 14; ++k )
      {
        v32 = sub_51A200(v5, k);
        sub_572490(k, v32);
      }
      break;
    case 4:
      *(float *)(this + 16152) = v49;
      sub_5735E0(&v55, v66, v72, v68, v71, v70, v18);
      sub_573760(LODWORD(v51), LODWORD(v52));
      v33 = v58;
      v34 = v63;
      *(float *)(this + 16180) = v62;
      v35 = v59;
      *(_DWORD *)(this + 16212) = v33;
      v36 = v64;
      *(_DWORD *)(this + 16432) = v34;
      v37 = v60;
      *(_DWORD *)(this + 16464) = v35;
      v38 = v65;
      *(_DWORD *)(this + 16684) = v36;
      v39 = v61;
      *(_DWORD *)(this + 16716) = v37;
      *(_DWORD *)(this + 16936) = v38;
      *(_DWORD *)(this + 16968) = v39;
      *(_BYTE *)(this + 15572) = *(int *)(a2 + 12) < 0;
      for ( m = 0; m < 4; ++m )
        sub_5691C0(m);
      for ( n = 0; n < 14; ++n )
      {
        v42 = sub_51A200(v5, n);
        sub_572490(n, v42);
      }
      if ( *(_DWORD *)dword_B72314 == 8 )
      {
        v43 = sub_402D40(&flt_91BCA0, (float *)(this + 15988), *(_DWORD *)(this + 17492));
        v44 = *((_DWORD *)v43 + 18);
        v45 = *(_DWORD *)(this + 19288);
        if ( v45 != v44 )
        {
          if ( v45 == 2 && !v44 )
            ++*(_DWORD *)(this + 19284);
          *(float *)(this + 19288) = v43[18];
        }
      }
      break;
  }
  sub_569170(this + 2704);
  v46 = (*(_DWORD *)(a2 + 12) & 0x8000000) != 0;
  if ( *(_BYTE *)(this + 5754) != v46 )
  {
    v48 = *(_DWORD *)(this + 5744);
    *(_BYTE *)(this + 5754) = v46;
    sub_56AE80(v48, 1);
  }
  if ( *(_DWORD *)(this + 14820) == 3 )
    sub_53F190((void *)this, ((*(_DWORD *)(a2 + 12) >> 29) & 1) == 0, v54);
  v47 = (*(_DWORD *)(a2 + 12) & 0x4000000) != 0;
  *(_BYTE *)(this + 5763) = LODWORD(v51) == -1;
  *(_BYTE *)(this + 5761) = v47;
  *(_BYTE *)(this + 5767) = (*(_DWORD *)(a2 + 12) & 0x40000000) != 0;
  *(_DWORD *)(this + 22556) = sub_51A210(v5);
  *(_WORD *)(this + 22560) = sub_51A260(v5);
  *(_BYTE *)(this + 19240) = *(_BYTE *)(a2 + 15) & 1;
  *(float *)(this + 19244) = sub_51A220(v5);
}
