void __thiscall AIRacingLine(F1CVehicle *this)
{
  int v2; // ebx
  int CallToBox; // eax
  _DWORD *v4; // ecx
  int v5; // edi
  float *v6; // eax
  double v7; // st6
  int v8; // ecx
  int v9; // eax
  double v10; // st5
  double v11; // st4
  long double v12; // st7
  double v13; // st7
  int v14; // ecx
  int v15; // eax
  double v16; // st5
  double v17; // st4
  long double v18; // st7
  int v19; // eax
  double v20; // st6
  double v21; // st4
  long double v22; // st5
  double v23; // st6
  float Speed; // eax
  double v25; // st7
  double v26; // st7
  bool v27; // bl
  double v28; // st7
  int *p_CurrentWaypointPtr; // eax
  int v30; // ecx
  int v31; // edx
  float *v32; // ebp
  int v33; // ecx
  int v34; // eax
  double v35; // st7
  int v36; // eax
  int v37; // eax
  double v38; // st7
  unsigned __int8 *v39; // eax
  int v40; // ecx
  double v41; // st7
  int CurrentWaypointPtr; // ecx
  double v43; // st7
  double v44; // st7
  double RaceAbilityNorm; // st6
  float v46; // [esp+0h] [ebp-44h]
  float v47; // [esp+1Ch] [ebp-28h]
  float v48; // [esp+1Ch] [ebp-28h]
  float v49; // [esp+1Ch] [ebp-28h]
  float v50; // [esp+20h] [ebp-24h]
  float v51; // [esp+20h] [ebp-24h]
  float v52; // [esp+20h] [ebp-24h]
  int v53; // [esp+24h] [ebp-20h]
  float v54; // [esp+28h] [ebp-1Ch]
  float v55[2]; // [esp+2Ch] [ebp-18h] BYREF
  float v56; // [esp+34h] [ebp-10h]
  _DWORD v57[3]; // [esp+38h] [ebp-Ch] BYREF

  v54 = *(float *)&this->gap_4414[36];
  v53 = 0;
  v2 = SpatialTreeNearestNeighborSearch(
         dword_5EA2C0,
         &this->WorldPositionX,
         this->CurrentWaypointPtr,
         this->WaypointSetSelector,
         0);
  CallToBox = this->CallToBox;
  if ( !CallToBox || (v4 = *(_DWORD **)(v2 + 276)) == 0 || CallToBox != v4[75] )
    v4 = *(_DWORD **)(v2 + 272);
  if ( !CallToBox || (v5 = v4[69]) == 0 || CallToBox != *(_DWORD *)(v5 + 300) )
    v5 = v4[68];
  if ( *(_DWORD *)&this->gap_4414[40] && *(_DWORD *)&this->gap_4358[168] )
  {
    F_3DTransformWithMatrixMultiplication((float *)&this->gap_0004[8], v55, v57);
    v6 = *(float **)&this->gap_4358[168];
    v7 = v56 - v6[2];
    v50 = sqrt(v7 * v7 + (v55[0] - *v6) * (v55[0] - *v6));
    v47 = v50 * 0.40000001;
    if ( AerodynamicForceCalc((float *)&this->gap_0004[8], this->Speed, v47, 0.75) > 0.0 )
    {
      *(_DWORD *)&this->gap_4414[40] = 0;
      *(float *)&this->gap_4514[16] = v50;
    }
    if ( *(float *)&this->gap_4414[16] == 0.0 )
    {
      v8 = *(_DWORD *)&this->gap_4358[168];
      v9 = *(_DWORD *)(v8 + 276);
      if ( v9 )
      {
        v10 = v56 - *(float *)(v9 + 156);
        v11 = v55[0] - *(float *)(v9 + 148);
        v47 = sqrt(v10 * v10 + v11 * v11);
        v12 = sqrt(*(float *)(v8 + 24) * *(float *)(v8 + 24)) + 19.0;
        if ( v12 > 28.0 )
          v12 = 28.0;
        if ( 0.67000002 * v12 <= v47 )
        {
          if ( v47 < v12 )
          {
            *(_DWORD *)&this->gap_4414[40] = 0;
            v13 = *(float *)(v8 + 24) * 0.5;
            *(float *)&this->gap_4514[16] = v50;
            *(float *)&this->gap_4414[16] = v13;
          }
        }
        else
        {
          *(_DWORD *)&this->gap_4414[40] = 0;
          *(_DWORD *)&this->gap_4414[16] = *(_DWORD *)(v8 + 24);
          *(float *)&this->gap_4514[16] = v50;
        }
      }
    }
  }
  if ( *(float *)&this->gap_4514[16] != 0.0 )
  {
    F_3DTransformWithMatrixMultiplication((float *)&this->gap_0004[8], v55, v57);
    v14 = *(_DWORD *)&this->gap_4358[168];
    v15 = *(_DWORD *)(v14 + 276);
    if ( v15 )
    {
      v16 = v56 - *(float *)(v15 + 156);
      v17 = v55[0] - *(float *)(v15 + 148);
      v47 = sqrt(v16 * v16 + v17 * v17);
      v18 = sqrt(*(float *)(v14 + 24) * *(float *)(v14 + 24)) * 1.2 + 17.0;
      if ( v18 > 28.0 )
        v18 = 28.0;
      if ( 0.67000002 * v18 <= v47 )
      {
        if ( v47 < v18 )
        {
          *(_DWORD *)&this->gap_4454[20] = 0;
          *(_DWORD *)&this->gap_4414[40] = 0;
          *(float *)&this->gap_4414[16] = *(float *)(v14 + 24) * 0.5;
        }
      }
      else
      {
        *(_DWORD *)&this->gap_4454[20] = 0;
        *(_DWORD *)&this->gap_4414[40] = 0;
        *(_DWORD *)&this->gap_4414[16] = *(_DWORD *)(v14 + 24);
      }
    }
    v19 = *(_DWORD *)(v14 + 276);
    v20 = v56 - *(float *)(v14 + 8);
    v21 = v55[0] - *(float *)v14;
    v22 = sqrt(v20 * v20 + v21 * v21);
    if ( v19 )
    {
      v23 = (*(float *)v14 - v55[0]) * *(float *)(v19 + 12) + (*(float *)(v14 + 8) - v56) * *(float *)(v19 + 20);
    }
    else
    {
      if ( v22 <= *(float *)&this->gap_4514[16] )
        goto LABEL_34;
      v23 = v47;
    }
    if ( v23 <= 0.0 )
    {
LABEL_38:
      if ( v22 < 5.0 )
        LOBYTE(this->AIControlFlag) = 0;
      *(_DWORD *)&this->gap_4414[40] = 0;
      this->RenderZ = 0.0;
      *(_DWORD *)&this->gap_34FC[4] = 0;
      *(_DWORD *)this->gap_34FC = 0;
      *(_DWORD *)&this->gap_4358[160] = 0;
      AIClearStateFlags((int)this);
      if ( dword_7C56A4 == 7 )
        this->driverStatus = 4;
      else
        this->driverStatus = 5;
      *(_DWORD *)&this->gap_4514[16] = 0;
      *(_DWORD *)&this->gap_4414[36] = 1065353216;
      *(_DWORD *)&this->gap_4414[32] = 0;
      this->CallToBox = 0;
      this->WaypointSetSelector = 1;
      *(_DWORD *)&this->gap_4414[16] = 0;
      sub_426430(this);
      return;
    }
LABEL_34:
    if ( v22 > 0.5 )
    {
      Speed = this->Speed;
      *(float *)&this->gap_4514[16] = v22;
      v46 = v22 * 0.30000001;
      if ( AerodynamicForceCalc((float *)&this->gap_0004[8], Speed, v46, 0.69999999) <= 0.0 )
      {
        *(_DWORD *)&this->gap_4414[36] = 0;
        *(float *)&this->gap_4414[32] = BrakeThermalModel((float *)&this->gap_0004[8]);
      }
      else
      {
        *(_DWORD *)&this->gap_4414[32] = 0;
        *(_DWORD *)&this->gap_4414[36] = 1065353216;
      }
      return;
    }
    goto LABEL_38;
  }
  v25 = this->Speed * 1.05;
  v51 = v25;
  v26 = AIComputePassScore(&this->postProcessInput, v25, (float *)v2);
  v27 = 1;
  if ( v26 >= v51 )
  {
    v26 = AIComputePassScore(&this->postProcessInput, v26, (float *)*(_DWORD *)(v2 + 272));
    if ( v26 >= v51 )
      v27 = 0;
  }
  if ( *(_DWORD *)(v5 + 308) == 1 )
    v28 = (double)*(int *)(v5 + 312);
  else
    v28 = AIComputePassScore(&this->postProcessInput, v26, (float *)v5) * *(float *)this->gap_4554;
  v52 = v28;
  p_CurrentWaypointPtr = &this->CurrentWaypointPtr;
  v30 = 0;
  v48 = this->Speed;
  if ( v5 != this->CurrentWaypointPtr )
  {
    do
    {
      *((float *)p_CurrentWaypointPtr + 20) = v48;
      ++v30;
      ++p_CurrentWaypointPtr;
    }
    while ( v30 < 20 && v5 != *p_CurrentWaypointPtr );
    v53 = v30;
  }
  *(_DWORD *)&this->gap_4358[160] = 0;
  *(_DWORD *)&this->gap_4358[164] = 1176255488;
  if ( v48 <= 0.0 )
    goto LABEL_86;
  v31 = v53;
  v32 = (float *)&this->gap_4358[4 * v30 + 76];
  while ( v48 < (double)v52 )
  {
    v33 = this->CallToBox;
    if ( v33 && (v34 = *(_DWORD *)(v5 + 276)) != 0 && v33 == *(_DWORD *)(v34 + 300) )
      v5 = *(_DWORD *)(v5 + 276);
    else
      v5 = *(_DWORD *)(v5 + 272);
    if ( !v5 )
      goto LABEL_86;
    if ( *(_DWORD *)(v5 + 308) == 1 )
    {
      v35 = flt_8ACFB4;
    }
    else
    {
      v36 = *(_DWORD *)(v5 + 276);
      if ( v36 )
      {
        v37 = *(_DWORD *)(v36 + 300);
        if ( v37 == v33 && v33 != 1 && v37 )
        {
          v52 = 12.0;
          goto LABEL_73;
        }
      }
      v35 = AIComputePassScore(&this->postProcessInput, v48, (float *)v5);
    }
    v52 = v35;
LABEL_73:
    v38 = TireForce((float *)&this->gap_0004[8], v48, *(float *)(v5 + 116), (float *)(v5 + 120), *(float *)(v5 + 112));
    if ( v48 <= 1.0 || (v48 = v48 - *(float *)(v5 + 60) / v48 * this->PassingNorm * v38 * 0.91500002, v48 < 0.5) )
      v48 = 0.0;
    v31 = v53;
    if ( v53 < 20 )
    {
      v31 = v53 + 1;
      *v32 = v48;
      ++v53;
      ++v32;
    }
    if ( v48 <= 0.0 )
      goto LABEL_86;
  }
  if ( v31 >= 1 )
  {
    if ( v31 < 20 )
      goto LABEL_83;
  }
  else
  {
    v31 = 1;
LABEL_83:
    v39 = &this->gap_4358[4 * v31 + 76];
    v40 = 20 - v31;
    do
    {
      v41 = *((float *)v39 - 1);
      v39 += 4;
      --v40;
      *((float *)v39 - 1) = v41 - 1.8;
    }
    while ( v40 );
  }
  byte_5C3160 = 0;
  *(_DWORD *)&this->gap_4358[160] = v5;
  *(float *)&this->gap_4358[164] = v52;
LABEL_86:
  CurrentWaypointPtr = this->CurrentWaypointPtr;
  this->gap_4454[8] = *(float *)(CurrentWaypointPtr + 84) + 1.5 > *(float *)&this->gap_4414[20]
                   && *(float *)(CurrentWaypointPtr + 80) + 1.5 > -*(float *)&this->gap_4414[20];
  if ( v48 <= 0.0 )
  {
    *(_DWORD *)&this->gap_4414[36] = 0;
    if ( v27 )
    {
      v44 = BrakeThermalModel((float *)&this->gap_0004[8]);
    }
    else
    {
      if ( this->gap_4454[8] )
      {
        if ( *(_DWORD *)&this->gap_4454[24] )
          v44 = BrakeThermalModel((float *)&this->gap_0004[8]);
        else
          v44 = 1.0;
      }
      else if ( this->Speed <= 25.0 )
      {
        v44 = 0.40000001;
      }
      else
      {
        v44 = 0.5;
      }
      if ( byte_5C3160 )
        RaceAbilityNorm = *(float *)&this->gap_4454[100];
      else
        RaceAbilityNorm = this->RaceAbilityNorm;
      v49 = RaceAbilityNorm * 0.2;
      if ( v44 - *(float *)&this->gap_4414[32] > v49 )
      {
        *(float *)&this->gap_4414[32] = v49 + *(float *)&this->gap_4414[32];
        return;
      }
    }
    *(float *)&this->gap_4414[32] = v44;
  }
  else
  {
    v43 = TireGripCoefficient((int)&this->gap_0004[8]);
    if ( v43 - v54 > 0.2 )
      v43 = v54 + 0.2;
    *(float *)&this->gap_4414[36] = v43;
    *(_DWORD *)&this->gap_4414[32] = 0;
  }
}

