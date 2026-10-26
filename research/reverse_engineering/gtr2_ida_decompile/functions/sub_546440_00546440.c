void __thiscall sub_546440(int *this, int a2, float a3, int a4, float *a5, int a6)
{
  unsigned int v6; // kr00_4
  int v7; // eax
  double v9; // st7
  double v10; // st6
  int v11; // edx
  double v12; // st7
  int v13; // edx
  double v14; // st7
  float *v15; // eax
  int v16; // ecx
  float v17; // edx
  int v18; // eax
  double v19; // st7
  double v20; // st6
  double v21; // st7
  int v22; // ecx
  double v23; // st7
  float *v24; // eax
  int v25; // ecx
  float v26; // edx
  int v27; // eax
  double v28; // st7
  double v29; // st6
  double v30; // st7
  int v31; // ecx
  double v32; // st7
  float *v33; // eax
  int v34; // ecx
  float v35; // edx
  int v36; // eax
  float *v37; // eax
  int v38; // ecx
  int v39; // edx
  int v40; // eax
  float *v41; // eax
  int v42; // ecx
  float v43; // edx
  double v44; // st7
  double v45; // st7
  float v46; // [esp+0h] [ebp-68h]
  float v47; // [esp+Ch] [ebp-5Ch]
  float v48; // [esp+Ch] [ebp-5Ch]
  float v49; // [esp+Ch] [ebp-5Ch]
  float v50; // [esp+Ch] [ebp-5Ch]
  int v51; // [esp+2Ch] [ebp-3Ch] BYREF
  int v52; // [esp+30h] [ebp-38h]
  float v53; // [esp+34h] [ebp-34h]
  int v54; // [esp+38h] [ebp-30h] BYREF
  float v55; // [esp+3Ch] [ebp-2Ch]
  int v56; // [esp+40h] [ebp-28h]
  int v57[3]; // [esp+44h] [ebp-24h] BYREF
  float v58[3]; // [esp+50h] [ebp-18h] BYREF
  float v59[3]; // [esp+5Ch] [ebp-Ch] BYREF

  if ( byte_B713F8 )
  {
    if ( byte_B71428 )
      a6 = 104;
  }
  else if ( !byte_B71428 )
  {
    a6 = -1;
  }
  if ( dword_B7129C > 2 || dword_BE1204 == 2 || !(dword_91E230 % 20) )
  {
    if ( *(float *)a2 != 0.0 )
    {
      if ( this[8] )
      {
        if ( fabs(a3 - *(float *)(a2 + 4)) > 0.15000001
          || (v10 = *(float *)(a4 + 8) - *(float *)(a2 + 16),
              v9 = *(float *)a4 - *(float *)(a2 + 8),
              v10 * v10 + v9 * v9 > 1.0) )
        {
          *(_DWORD *)(a2 + 8) = *(_DWORD *)a4;
          *(_DWORD *)(a2 + 12) = *(_DWORD *)(a4 + 4);
          v11 = *(_DWORD *)(a4 + 8);
          *(float *)(a2 + 4) = a3;
          *(_DWORD *)(a2 + 16) = v11;
          v12 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.25;
          v13 = *(_DWORD *)(a4 + 4);
          *(float *)&v51 = v12 + *(float *)a4;
          v52 = v13;
          v14 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
          v53 = v14 * 0.25 + *(float *)(a4 + 8);
          v15 = sub_4012D0(a5, (float *)v57, 0.1);
          v16 = *(_DWORD *)v15;
          v17 = v15[1];
          v18 = *((_DWORD *)v15 + 2);
          v54 = v16;
          v55 = v17;
          v47 = *(float *)a2;
          v55 = v17 + 0.25;
          v56 = v18;
          sub_543B10(this[8], a3, (float *)&v51, (float *)&v54, v47, 0, 0, a6);
        }
      }
    }
    if ( *(float *)(a2 + 20) != 0.0 )
    {
      if ( this[9] )
      {
        if ( fabs(a3 - *(float *)(a2 + 24)) > 0.15000001
          || (v20 = *(float *)(a4 + 8) - *(float *)(a2 + 36),
              v19 = *(float *)a4 - *(float *)(a2 + 28),
              v20 * v20 + v19 * v19 > 1.0) )
        {
          *(_DWORD *)(a2 + 28) = *(_DWORD *)a4;
          *(_DWORD *)(a2 + 32) = *(_DWORD *)(a4 + 4);
          *(_DWORD *)(a2 + 36) = *(_DWORD *)(a4 + 8);
          *(float *)(a2 + 24) = a3;
          v21 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.25;
          v22 = *(_DWORD *)(a4 + 4);
          *(float *)&v51 = v21 + *(float *)a4;
          v23 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
          v52 = v22;
          v53 = v23 * 0.25 + *(float *)(a4 + 8);
          v24 = sub_4012D0(a5, (float *)v57, 0.1);
          v25 = *(_DWORD *)v24;
          v26 = v24[1];
          v27 = *((_DWORD *)v24 + 2);
          v54 = v25;
          v55 = v26;
          v48 = *(float *)(a2 + 20);
          v55 = v26 + 0.25;
          v56 = v27;
          sub_543B10(this[9], a3, (float *)&v51, (float *)&v54, v48, 0, 0, a6);
        }
      }
    }
    if ( *(float *)(a2 + 40) != 0.0 )
    {
      if ( this[10] )
      {
        if ( fabs(a3 - *(float *)(a2 + 44)) > 0.059999999
          || (v29 = *(float *)(a4 + 8) - *(float *)(a2 + 56),
              v28 = *(float *)a4 - *(float *)(a2 + 48),
              v29 * v29 + v28 * v28 > 0.16000001) )
        {
          *(_DWORD *)(a2 + 48) = *(_DWORD *)a4;
          *(_DWORD *)(a2 + 52) = *(_DWORD *)(a4 + 4);
          *(_DWORD *)(a2 + 56) = *(_DWORD *)(a4 + 8);
          *(float *)(a2 + 44) = a3;
          v30 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.15000001;
          v31 = *(_DWORD *)(a4 + 4);
          *(float *)&v51 = v30 + *(float *)a4;
          v32 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
          v52 = v31;
          v53 = v32 * 0.15000001 + *(float *)(a4 + 8);
          v33 = sub_4012D0(a5, (float *)v57, 0.1);
          v34 = *(_DWORD *)v33;
          v35 = v33[1];
          v36 = *((_DWORD *)v33 + 2);
          v54 = v34;
          v55 = v35;
          v49 = *(float *)(a2 + 40);
          v55 = v35 + 0.25;
          v56 = v36;
          sub_543B10(this[10], a3, (float *)&v51, (float *)&v54, v49, 0, 0, a6);
          if ( dword_B7129C > 2 )
          {
            v37 = sub_4012D0(a5, v58, 0.0125);
            v38 = *(_DWORD *)v37;
            v39 = *((_DWORD *)v37 + 1);
            v40 = *((_DWORD *)v37 + 2);
            v57[0] = v38;
            v57[1] = v39;
            v57[2] = v40;
            v41 = sub_401290((float *)a4, (float *)v57, v59);
            v42 = *((_DWORD *)v41 + 1);
            v51 = *(int *)v41;
            v43 = v41[2];
            v6 = __readeflags();
            v7 = *(_DWORD *)(dword_16F027B + dword_16C6E9C);
            __writeeflags(v6);
            v52 = v42;
            v44 = flt_BE0CA4[(unsigned __int8)v7];
            v53 = v43;
            dword_BE08A0 = v7 + 1;
            *(float *)&v51 = v44 * 0.15000001 + *(float *)&v51;
            v45 = flt_BE0CA4[(unsigned __int8)(v7 + 1)];
            dword_BE08A0 = v7 + 2;
            v50 = *(float *)(a2 + 40);
            v53 = v45 * 0.15000001 + v43;
            v46 = a3 - 0.0125;
            sub_543B10(this[10], v46, (float *)&v51, (float *)&v54, v50, 0, 0, a6);
          }
        }
      }
    }
  }
}
