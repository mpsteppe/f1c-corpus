void __thiscall sub_425920(int this)
{
  int v2; // ebx
  int v3; // eax
  _DWORD *v4; // ecx
  int v5; // edi
  float *v6; // eax
  double v7; // st6
  double v8; // st7
  int v9; // ecx
  int v10; // eax
  double v11; // st5
  double v12; // st4
  long double v13; // st7
  double v14; // st7
  int v15; // ecx
  int v16; // eax
  double v17; // st5
  double v18; // st4
  long double v19; // st7
  int v20; // eax
  double v21; // st6
  double v22; // st4
  long double v23; // st5
  double v24; // st6
  float v25; // eax
  bool v26; // bl
  double v27; // st7
  int v28; // eax
  int v29; // ecx
  int v30; // edx
  float *v31; // ebp
  double v32; // st7
  int v33; // ecx
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  double v39; // st7
  int v40; // ecx
  double v41; // st7
  double v42; // st7
  double v43; // st6
  float v44; // [esp+0h] [ebp-44h]
  float v45; // [esp+1Ch] [ebp-28h]
  float v46; // [esp+1Ch] [ebp-28h]
  float v47; // [esp+1Ch] [ebp-28h]
  float v48; // [esp+20h] [ebp-24h]
  float v49; // [esp+20h] [ebp-24h]
  float v50; // [esp+20h] [ebp-24h]
  int v51; // [esp+24h] [ebp-20h]
  float v52; // [esp+28h] [ebp-1Ch]
  float v53[2]; // [esp+2Ch] [ebp-18h] BYREF
  float v54; // [esp+34h] [ebp-10h]
  _BYTE v55[12]; // [esp+38h] [ebp-Ch] BYREF

  v52 = *(float *)(this + 17464);
  v51 = 0;
  v2 = SpatialTreeNearestNeighborSearch(
         dword_5EA2C0,
         (float *)(this + 13536),
         *(_DWORD *)(this + 17236),
         *(_DWORD *)(this + 17744),
         0);
  v3 = *(_DWORD *)(this + 17740);
  if ( !v3 || (v4 = *(_DWORD **)(v2 + 276)) == 0 || v3 != v4[75] )
    v4 = *(_DWORD **)(v2 + 272);
  if ( !v3 || (v5 = v4[69]) == 0 || v3 != *(_DWORD *)(v5 + 300) )
    v5 = v4[68];
  if ( *(_DWORD *)(this + 17468) && *(_DWORD *)(this + 17408) )
  {
    F_3DTransformWithMatrixMultiplication(v53, v55);
    v6 = *(float **)(this + 17408);
    v7 = v54 - v6[2];
    v48 = sqrt(v7 * v7 + (v53[0] - *v6) * (v53[0] - *v6));
    v8 = v48 * 0.40000001;
    v45 = v8;
    AerodynamicForceCalc(*(float *)(this + 17472), v45, 0.75);
    if ( v8 > 0.0 )
    {
      *(_DWORD *)(this + 17468) = 0;
      *(float *)(this + 17700) = v48;
    }
    if ( *(float *)(this + 17444) == 0.0 )
    {
      v9 = *(_DWORD *)(this + 17408);
      v10 = *(_DWORD *)(v9 + 276);
      if ( v10 )
      {
        v11 = v54 - *(float *)(v10 + 156);
        v12 = v53[0] - *(float *)(v10 + 148);
        v45 = sqrt(v11 * v11 + v12 * v12);
        v13 = sqrt(*(float *)(v9 + 24) * *(float *)(v9 + 24)) + 19.0;
        if ( v13 > 28.0 )
          v13 = 28.0;
        if ( 0.67000002 * v13 <= v45 )
        {
          if ( v45 < v13 )
          {
            *(_DWORD *)(this + 17468) = 0;
            v14 = *(float *)(v9 + 24) * 0.5;
            *(float *)(this + 17700) = v48;
            *(float *)(this + 17444) = v14;
          }
        }
        else
        {
          *(_DWORD *)(this + 17468) = 0;
          *(_DWORD *)(this + 17444) = *(_DWORD *)(v9 + 24);
          *(float *)(this + 17700) = v48;
        }
      }
    }
  }
  if ( *(float *)(this + 17700) != 0.0 )
  {
    F_3DTransformWithMatrixMultiplication(v53, v55);
    v15 = *(_DWORD *)(this + 17408);
    v16 = *(_DWORD *)(v15 + 276);
    if ( v16 )
    {
      v17 = v54 - *(float *)(v16 + 156);
      v18 = v53[0] - *(float *)(v16 + 148);
      v45 = sqrt(v17 * v17 + v18 * v18);
      v19 = sqrt(*(float *)(v15 + 24) * *(float *)(v15 + 24)) * 1.2 + 17.0;
      if ( v19 > 28.0 )
        v19 = 28.0;
      if ( 0.67000002 * v19 <= v45 )
      {
        if ( v45 < v19 )
        {
          *(_DWORD *)(this + 17512) = 0;
          *(_DWORD *)(this + 17468) = 0;
          *(float *)(this + 17444) = *(float *)(v15 + 24) * 0.5;
        }
      }
      else
      {
        *(_DWORD *)(this + 17512) = 0;
        *(_DWORD *)(this + 17468) = 0;
        *(_DWORD *)(this + 17444) = *(_DWORD *)(v15 + 24);
      }
    }
    v20 = *(_DWORD *)(v15 + 276);
    v21 = v54 - *(float *)(v15 + 8);
    v22 = v53[0] - *(float *)v15;
    v23 = sqrt(v21 * v21 + v22 * v22);
    if ( v20 )
    {
      v24 = (*(float *)v15 - v53[0]) * *(float *)(v20 + 12) + (*(float *)(v15 + 8) - v54) * *(float *)(v20 + 20);
    }
    else
    {
      if ( v23 <= *(float *)(this + 17700) )
        goto LABEL_34;
      v24 = v45;
    }
    if ( v24 <= 0.0 )
    {
LABEL_38:
      if ( v23 < 5.0 )
        *(_BYTE *)(this + 17908) = 0;
      *(_DWORD *)(this + 17468) = 0;
      *(_DWORD *)(this + 13560) = 0;
      *(_DWORD *)(this + 13568) = 0;
      *(_DWORD *)(this + 13564) = 0;
      *(_DWORD *)(this + 17400) = 0;
      AIClearStateFlags(this);
      if ( dword_7C56A4 == 7 )
        *(_DWORD *)(this + 17680) = 4;
      else
        *(_DWORD *)(this + 17680) = 5;
      *(_DWORD *)(this + 17700) = 0;
      *(_DWORD *)(this + 17464) = 1065353216;
      *(_DWORD *)(this + 17460) = 0;
      *(_DWORD *)(this + 17740) = 0;
      *(_DWORD *)(this + 17744) = 1;
      *(_DWORD *)(this + 17444) = 0;
      sub_426430(this);
      return;
    }
LABEL_34:
    if ( v23 > 0.5 )
    {
      v25 = *(float *)(this + 17472);
      *(float *)(this + 17700) = v23;
      v44 = v23 * 0.30000001;
      AerodynamicForceCalc(v25, v44, 0.69999999);
      if ( v23 * 0.30000001 <= 0.0 )
      {
        *(_DWORD *)(this + 17464) = 0;
        *(float *)(this + 17460) = BrakeThermalModel(this + 12);
      }
      else
      {
        *(_DWORD *)(this + 17460) = 0;
        *(_DWORD *)(this + 17464) = 1065353216;
      }
      return;
    }
    goto LABEL_38;
  }
  v49 = *(float *)(this + 17472) * 1.05;
  v26 = AIComputePassScore(v2) < v49 || AIComputePassScore(*(_DWORD *)(v2 + 272)) < v49;
  if ( *(_DWORD *)(v5 + 308) == 1 )
    v27 = (double)*(int *)(v5 + 312);
  else
    v27 = AIComputePassScore(v5) * *(float *)(this + 17748);
  v50 = v27;
  v28 = this + 17236;
  v29 = 0;
  v46 = *(float *)(this + 17472);
  if ( v5 != *(_DWORD *)(this + 17236) )
  {
    do
    {
      *(float *)(v28 + 80) = v46;
      ++v29;
      v28 += 4;
    }
    while ( v29 < 20 && v5 != *(_DWORD *)v28 );
    v51 = v29;
  }
  *(_DWORD *)(this + 17400) = 0;
  *(_DWORD *)(this + 17404) = 1176255488;
  if ( v46 <= 0.0 )
    goto LABEL_86;
  v30 = v51;
  v31 = (float *)(this + 4 * v29 + 17316);
  while ( 1 )
  {
    v32 = v46;
    if ( v46 >= (double)v50 )
      break;
    v33 = *(_DWORD *)(this + 17740);
    if ( v33 && (v34 = *(_DWORD *)(v5 + 276)) != 0 && v33 == *(_DWORD *)(v34 + 300) )
      v5 = *(_DWORD *)(v5 + 276);
    else
      v5 = *(_DWORD *)(v5 + 272);
    if ( !v5 )
      goto LABEL_86;
    if ( *(_DWORD *)(v5 + 308) == 1 )
    {
      v32 = flt_8ACFB4;
    }
    else
    {
      v35 = *(_DWORD *)(v5 + 276);
      if ( v35 )
      {
        v36 = *(_DWORD *)(v35 + 300);
        if ( v36 == v33 && v33 != 1 && v36 )
        {
          v50 = 12.0;
          goto LABEL_73;
        }
      }
      v32 = AIComputePassScore(v5);
    }
    v50 = v32;
LABEL_73:
    TireForce(v46, *(float *)(v5 + 116), v5 + 120, *(float *)(v5 + 112));
    if ( v46 <= 1.0 || (v46 = v46 - *(float *)(v5 + 60) / v46 * *(float *)(this + 17612) * v32 * 0.91500002, v46 < 0.5) )
      v46 = 0.0;
    v30 = v51;
    if ( v51 < 20 )
    {
      v30 = v51 + 1;
      *v31 = v46;
      ++v51;
      ++v31;
    }
    if ( v46 <= 0.0 )
      goto LABEL_86;
  }
  if ( v30 >= 1 )
  {
    if ( v30 < 20 )
      goto LABEL_83;
  }
  else
  {
    v30 = 1;
LABEL_83:
    v37 = this + 4 * v30 + 17316;
    v38 = 20 - v30;
    do
    {
      v39 = *(float *)(v37 - 4);
      v37 += 4;
      --v38;
      *(float *)(v37 - 4) = v39 - 1.8;
    }
    while ( v38 );
  }
  byte_5C3160 = 0;
  *(_DWORD *)(this + 17400) = v5;
  *(float *)(this + 17404) = v50;
LABEL_86:
  v40 = *(_DWORD *)(this + 17236);
  *(_BYTE *)(this + 17500) = *(float *)(v40 + 84) + 1.5 > *(float *)(this + 17448)
                          && *(float *)(v40 + 80) + 1.5 > -*(float *)(this + 17448);
  if ( v46 <= 0.0 )
  {
    *(_DWORD *)(this + 17464) = 0;
    if ( v26 )
    {
      v42 = BrakeThermalModel(this + 12);
    }
    else
    {
      if ( *(_BYTE *)(this + 17500) )
      {
        if ( *(_DWORD *)(this + 17516) )
          v42 = BrakeThermalModel(this + 12);
        else
          v42 = 1.0;
      }
      else if ( *(float *)(this + 17472) <= 25.0 )
      {
        v42 = 0.40000001;
      }
      else
      {
        v42 = 0.5;
      }
      if ( byte_5C3160 )
        v43 = *(float *)(this + 17592);
      else
        v43 = *(float *)(this + 17604);
      v47 = v43 * 0.2;
      if ( v42 - *(float *)(this + 17460) > v47 )
      {
        *(float *)(this + 17460) = v47 + *(float *)(this + 17460);
        return;
      }
    }
    *(float *)(this + 17460) = v42;
  }
  else
  {
    v41 = TireGripCoefficient(this + 12);
    if ( v41 - v52 > 0.2 )
      v41 = v52 + 0.2;
    *(float *)(this + 17464) = v41;
    *(_DWORD *)(this + 17460) = 0;
  }
}
