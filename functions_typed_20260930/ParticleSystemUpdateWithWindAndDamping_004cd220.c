int __usercall sub_4CD220@<eax>(float *a1@<ecx>, double a2@<st0>)
{
  float *v2; // ebx
  int v3; // eax
  float v4; // ecx
  float v5; // edx
  int result; // eax
  int v7; // ebp
  int v8; // ecx
  float *v9; // esi
  float *v10; // edi
  double v11; // st7
  double v12; // st7
  double v13; // st6
  double v14; // st7
  double v15; // st7
  double v16; // st6
  double v18; // st7
  char v19; // c0
  double v20; // st7
  long double v21; // st7
  float v22; // edx
  float *v23; // ebx
  int j; // ebp
  float v25; // ecx
  long double v26; // st7
  int v27; // edx
  double v28; // st7
  double v29; // st6
  float v30; // [esp+0h] [ebp-CCh]
  float v31; // [esp+1Ch] [ebp-B0h]
  int i; // [esp+24h] [ebp-A8h]
  float v34; // [esp+28h] [ebp-A4h]
  int v35; // [esp+2Ch] [ebp-A0h] BYREF
  float v36; // [esp+30h] [ebp-9Ch]
  float v37; // [esp+34h] [ebp-98h]
  float v38; // [esp+38h] [ebp-94h]
  float v39; // [esp+3Ch] [ebp-90h]
  float v40; // [esp+40h] [ebp-8Ch]
  float v41; // [esp+44h] [ebp-88h]
  float v42; // [esp+48h] [ebp-84h]
  float v43; // [esp+4Ch] [ebp-80h]
  float v44; // [esp+50h] [ebp-7Ch]
  float v45; // [esp+54h] [ebp-78h]
  float v46; // [esp+58h] [ebp-74h]
  float v47; // [esp+5Ch] [ebp-70h]
  float v48; // [esp+60h] [ebp-6Ch]
  float v49; // [esp+64h] [ebp-68h]
  float v50; // [esp+68h] [ebp-64h]
  float v51; // [esp+6Ch] [ebp-60h]
  int v52; // [esp+70h] [ebp-5Ch]
  float v53; // [esp+74h] [ebp-58h]
  float v54; // [esp+78h] [ebp-54h]
  int v55; // [esp+7Ch] [ebp-50h]
  float v56; // [esp+80h] [ebp-4Ch]
  float v57; // [esp+88h] [ebp-44h]
  float v58; // [esp+8Ch] [ebp-40h]
  float v59[4]; // [esp+90h] [ebp-3Ch] BYREF
  float v60; // [esp+A0h] [ebp-2Ch]
  float v61; // [esp+A4h] [ebp-28h]
  float v62[3]; // [esp+A8h] [ebp-24h] BYREF
  float v63[5]; // [esp+B4h] [ebp-18h] BYREF
  float v64; // [esp+C8h] [ebp-4h]

  v2 = a1;
  v3 = VirtualDispatchHelper(&dword_5EA510) + 36;
  v4 = *(float *)v3;
  v5 = *(float *)(v3 + 4);
  v41 = *(float *)(v3 + 8);
  v39 = v4;
  v40 = v5;
  if ( dword_8AB6E4 == 2 )
  {
    if ( VehicleDataAccessor(&dword_8AB6EC) == 5 )
    {
      v31 = 0.0;
      goto LABEL_7;
    }
    a2 = FloatDifference(&dword_8AB6EC);
  }
  else
  {
    a2 = dbl_8AFE98;
  }
  v31 = a2;
LABEL_7:
  if ( dword_8AB6E4 == 2 )
    Delegation(&dword_8AB6EC);
  else
    a2 = dbl_8AFEA0;
  result = *((_DWORD *)v2 + 25);
  v7 = 0;
  v34 = a2;
  for ( i = 0; v7 < result; i = v7 )
  {
    v8 = *((_DWORD *)v2 + 26);
    v9 = *(float **)(v8 + 4 * v7);
    if ( v34 > (double)v9[3] || v34 < (double)v9[2] )
    {
      ArrayElementRemoval(v2, *(_DWORD **)(v8 + 4 * v7--));
    }
    else
    {
      v10 = v9 + 11;
      v9[11] = v31 * v9[14] + v9[11];
      v9[12] = v31 * v9[15] + v9[12];
      v9[13] = v31 * v9[16] + v9[13];
      v9[15] = v9[15] - fabs(v31) * 9.8100004;
      v11 = v9[13] * v9[23] + v9[12] * v9[22] + v9[11] * v9[21];
      if ( v11 < v9[25] )
      {
        v12 = v9[25] - v11;
        v13 = v12 * v9[21];
        v57 = v12 * v9[22];
        v58 = v12 * v9[23];
        *v10 = v13 + *v10;
        v9[12] = v57 + v9[12];
        v9[13] = v58 + v9[13];
        v14 = v9[16] * v9[23] + v9[15] * v9[22] + v9[14] * v9[21];
        v15 = v14 + v14;
        v16 = v15 * v9[21];
        v60 = v15 * v9[22];
        v61 = v15 * v9[23];
        v9[14] = v9[14] - v16;
        v9[15] = v9[15] - v60;
        v9[16] = v9[16] - v61;
        v18 = v9[14];
        if ( v19 )
        {
          v9[14] = v18 + v18;
          v9[15] = v9[15] + v9[15];
          v20 = v9[16] + v9[16];
        }
        else
        {
          v9[14] = v18 * 0.5;
          v9[15] = v9[15] * 0.5;
          v20 = v9[16] * 0.5;
        }
        v9[16] = v20;
      }
      if ( (dword_7CFA4C & 3) != 0 )
      {
        v36 = v9[14] * 0.03125;
        v37 = v9[15] * 0.03125;
        v38 = v9[16] * 0.03125;
        if ( dword_7CFA4C == 1 )
        {
          if ( dword_7C54E0 )
          {
            v51 = *(float *)(dword_7C54E0 + 1860);
            v21 = v51 - *v10;
            v22 = *(float *)(dword_7C54E0 + 1868);
            v52 = *(_DWORD *)(dword_7C54E0 + 1864);
            v53 = v22;
            if ( fabs(v21) < 4.0 && fabs(v53 - v9[13]) < 4.0 )
            {
              v48 = v36 + *v10;
              v63[0] = v48;
              v49 = v37 + v9[12];
              v63[1] = v49;
              v50 = v38 + v9[13];
              v63[2] = v50;
              F_3DAABBOverlapTestWithSlidingResponse(v63, v9 + 11, (float *)(dword_7C54E0 + 1776));
            }
          }
        }
        else
        {
          v30 = *v10 + v9[13];
          v23 = FindDriversInRange(flt_8AC4E0, v30, 5.6568542, &v35);
          for ( j = 0; j < v35; ++j )
          {
            v25 = v23[j];
            v54 = *(float *)(LODWORD(v25) + 1848);
            v26 = v54 - *v10;
            v27 = *(_DWORD *)(LODWORD(v25) + 1852);
            v56 = *(float *)(LODWORD(v25) + 1856);
            v55 = v27;
            if ( fabs(v26) < 4.0
              && fabs(v56 - v9[13]) < 4.0
              && ((dword_7CFA4C & 1) != 0 || *(_DWORD *)(LODWORD(v25) + 4) != dword_7C54DC) )
            {
              v45 = v36 + *v10;
              v59[0] = v45;
              v46 = v37 + v9[12];
              v59[1] = v46;
              v47 = v38 + v9[13];
              v59[2] = v47;
              F_3DAABBOverlapTestWithSlidingResponse(v59, v9 + 11, (float *)(LODWORD(v25) + 1764));
            }
          }
          v7 = i;
          v2 = a1;
        }
      }
      v28 = v9[14] - v39;
      v29 = v9[15] - v40;
      v64 = v9[16] - v41;
      v42 = v28 * 0.03125;
      v62[0] = v42;
      v43 = v29 * 0.03125;
      v62[1] = v43;
      v44 = v64 * 0.03125;
      v62[2] = v44;
      ParticleEffectBillboardQuadSetup(v2, v9, v62);
    }
    result = *((_DWORD *)v2 + 25);
    ++v7;
  }
  return result;
}

