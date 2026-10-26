char __thiscall sub_426430(F1CVehicle *this)
{
  float *CurrentWaypointPtr; // ebp
  float *p_WorldPositionX; // edi
  int v4; // eax
  double v6; // st7
  double v7; // st6
  int v8; // eax
  float *v9; // ecx
  unsigned __int8 *gap_4358; // ebx
  unsigned __int8 *v11; // eax
  int CallToBox; // ecx
  int v13; // edi
  int v14; // edx
  int v15; // eax
  float *v16; // eax
  double v17; // st7
  int v18; // ecx
  double v19; // st7
  int v20; // eax
  float WorldPositionZ; // ecx
  double v22; // st7
  double v23; // st6
  int v24; // edx
  int v25; // ecx
  double v26; // st7
  int carConditions; // edi
  double v28; // st5
  double v29; // st4
  double v30; // st7
  long double v31; // st7
  long double v32; // st6
  double v33; // st6
  long double v34; // st6
  long double v35; // st6
  long double v36; // st6
  long double v37; // st7
  float *v38; // eax
  long double v39; // st6
  long double v40; // st5
  double v41; // st4
  double v42; // st3
  long double v43; // st2
  long double v44; // st7
  long double v45; // st7
  long double v46; // st6
  int v47; // eax
  double v48; // st7
  unsigned __int8 *v49; // edx
  int v50; // edi
  int v51; // ecx
  double v52; // st7
  int v53; // [esp-Ch] [ebp-58h]
  int WaypointSetSelector; // [esp-8h] [ebp-54h]
  float v55; // [esp+10h] [ebp-3Ch]
  float v56; // [esp+10h] [ebp-3Ch]
  float v57; // [esp+14h] [ebp-38h]
  int v58; // [esp+18h] [ebp-34h]
  float RenderX; // [esp+18h] [ebp-34h]
  float WorldPositionX; // [esp+1Ch] [ebp-30h]
  float v61; // [esp+24h] [ebp-28h]
  float v62; // [esp+28h] [ebp-24h]
  float v63; // [esp+30h] [ebp-1Ch]
  float v64; // [esp+34h] [ebp-18h]
  float v65; // [esp+3Ch] [ebp-10h]
  float v66; // [esp+40h] [ebp-Ch]

  CurrentWaypointPtr = (float *)this->CurrentWaypointPtr;
  p_WorldPositionX = &this->WorldPositionX;
  this->Speed = sqrt(
                  this->RenderZ * this->RenderZ
                + *(float *)this->gap_34FC * *(float *)this->gap_34FC
                + *(float *)&this->gap_34FC[4] * *(float *)&this->gap_34FC[4]);
  if ( !CurrentWaypointPtr )
  {
    v4 = SpatialNearestNeighborQueryWithPlaneTest(dword_5EA2C0, &this->WorldPositionX, this->WaypointSetSelector);
    this->CurrentWaypointPtr = v4;
    if ( !v4 )
      return 0;
    CurrentWaypointPtr = (float *)v4;
    goto LABEL_12;
  }
  v6 = *p_WorldPositionX - CurrentWaypointPtr[37];
  v7 = this->WorldPositionZ - CurrentWaypointPtr[39];
  if ( v7 * v7 + v6 * v6 > 3200.0 )
  {
    v8 = SpatialNearestNeighborQueryWithPlaneTest(dword_5EA2C0, &this->WorldPositionX, this->WaypointSetSelector);
    this->CurrentWaypointPtr = v8;
    if ( !v8 )
      return 0;
    CurrentWaypointPtr = (float *)v8;
    this->gap_4454[52] = 1;
  }
  v9 = (float *)this->CurrentWaypointPtr;
  if ( v9[5] * (v9[39] - this->WorldPositionZ) + v9[3] * (v9[37] - *p_WorldPositionX) < 0.0 )
  {
    CurrentWaypointPtr = (float *)this->CurrentWaypointPtr;
    if ( *(float *)(*(_DWORD *)this->gap_4358 + 72) < (double)v9[18] )
      ++*(_DWORD *)&this->gap_4454[4];
LABEL_12:
    this->gap_4454[52] = 1;
  }
  if ( this->gap_4454[52] )
  {
    gap_4358 = this->gap_4358;
    WaypointSetSelector = this->WaypointSetSelector;
    v53 = *(_DWORD *)this->gap_4358;
    this->trackPartFromPitExit = *(float *)(this->CurrentWaypointPtr + 72);
    this->CurrentWaypointPtr = SpatialTreeNearestNeighborSearch(
                                 dword_5EA2C0,
                                 p_WorldPositionX,
                                 v53,
                                 WaypointSetSelector,
                                 1);
    v11 = this->gap_4358;
    v58 = 19;
    do
    {
      CallToBox = this->CallToBox;
      v13 = *((_DWORD *)v11 - 1);
      if ( !CallToBox || (v14 = *(_DWORD *)(v13 + 276)) == 0 || CallToBox != *(_DWORD *)(v14 + 300) )
        v14 = *(_DWORD *)(v13 + 272);
      *(_DWORD *)v11 = v14;
      v11 += 4;
      --v58;
    }
    while ( v58 );
    v15 = this->WaypointSetSelector;
    if ( v15 || *(_DWORD *)(*(_DWORD *)gap_4358 + 300) != 1 )
    {
      if ( v15 == 1 && !*(_DWORD *)(*(_DWORD *)gap_4358 + 300) )
        sub_4A46F0(dword_7CE2F0, (int)this, 0, 0);
    }
    else
    {
      AICommandMessageQueueDispatcher(this, 14, this->WaypointSetSelector);
      sub_4A46F0(dword_7CE2F0, (int)this, 1, 1);
    }
    v16 = (float *)this->CurrentWaypointPtr;
    this->WaypointSetSelector = *(_DWORD *)(*(_DWORD *)gap_4358 + 300);
    v17 = TireForceSolver((float *)&this->gap_0004[8], v16[29], v16 + 30, v16[28], 16.0) * *(float *)&this->gap_44FC[8]
        + *(float *)&this->gap_44FC[4];
    if ( v17 > 75.0 )
      v17 = 75.0;
    v18 = this->WaypointSetSelector;
    if ( v18 == 1 )
      v17 = flt_8ACFB4;
    v19 = this->Speed / v17;
    *(float *)this->gap_4444 = v19;
    if ( v19 > 1.0 )
      *(_DWORD *)this->gap_4444 = 1065353216;
    *(float *)this->gap_4454 = (double)*(int *)&this->gap_4454[4] * flt_5EA3FC[0] + this->trackPartFromPitExit;
    if ( this->Speed >= 15.0 || v18 == 1 )
    {
      if ( this->Speed >= 30.0 )
      {
        if ( this->Speed >= 65.0 )
          *(_DWORD *)&this->gap_4454[20] = 3;
        else
          *(_DWORD *)&this->gap_4454[20] = 2;
      }
      else
      {
        *(_DWORD *)&this->gap_4454[20] = 1;
      }
    }
    else
    {
      *(_DWORD *)&this->gap_4454[20] = 0;
    }
    v20 = this->CurrentWaypointPtr;
    WorldPositionZ = this->WorldPositionZ;
    v22 = *(float *)(v20 + 148) - this->WorldPositionX;
    v23 = *(float *)(v20 + 156) - WorldPositionZ;
    *(float *)&this->gap_4454[68] = this->WorldPositionX;
    *(float *)&this->gap_4454[76] = WorldPositionZ;
    *(float *)&this->gap_4358[156] = sqrt(v23 * v23 + v22 * v22);
  }
  else if ( !this->gap_4140[0] )
  {
    return 1;
  }
  v24 = *(_DWORD *)&this->gap_4454[20];
  if ( *(_DWORD *)&this->gap_4350[4 * v24 + 4] )
  {
    v25 = *(_DWORD *)this->gap_4358;
    v26 = CurrentWaypointPtr[37] - this->WorldPositionX;
    carConditions = this->carConditions;
    v28 = CurrentWaypointPtr[8];
    v29 = CurrentWaypointPtr[10] * (CurrentWaypointPtr[39] - this->WorldPositionZ);
    *(_DWORD *)&this->gap_4514[24] = 1065353216;
    *(_DWORD *)&this->gap_4514[20] = 1065353216;
    *(float *)&this->gap_4414[20] = -(v29 + v28 * v26);
    v30 = (1.0 - *(float *)this->gap_4444) * 0.15000001 + *(float *)(v25 + 4 * v24 + 188);
    v57 = v30;
    RenderX = v30 + this->RenderX;
    v31 = this->RenderX - v30;
    if ( carConditions != 2 || this->FuelLevel > 0.001 )
    {
      if ( *(float *)(v25 + 4 * v24 + 188) > 0.02421 )
      {
        v32 = *(float *)(*(_DWORD *)&this->gap_4358[12] + 184) - *(float *)(this->CurrentWaypointPtr + 184);
        if ( fabs(v32) >= 3.141592653589793 )
        {
          if ( v32 >= 0.0 )
            v32 = v32 - 6.2831855;
          else
            v32 = v32 + 6.2831855;
        }
        if ( v32 <= 0.0 )
        {
          *(_DWORD *)&this->gap_4514[24] = -1082130432;
          v33 = *(float *)(v25 + 184) - *(float *)(v25 + 4 * v24 + 188);
        }
        else
        {
          *(_DWORD *)&this->gap_4514[20] = -1082130432;
          v33 = *(float *)(v25 + 184) + *(float *)(v25 + 4 * v24 + 188);
        }
        v55 = v33;
      }
      else
      {
        v55 = *(float *)(v25 + 184);
      }
      if ( *(_DWORD *)(LODWORD(this->postProcessInput) + 13000) != 1 )
        return 1;
      v34 = RenderX - v55;
      if ( fabs(v34) >= 3.141592653589793 )
      {
        if ( v34 >= 0.0 )
          v34 = v34 - 6.2831855;
        else
          v34 = v34 + 6.2831855;
      }
      if ( v34 > v57 && carConditions != 2 && this->FuelLevel > 0.001 )
      {
        v35 = this->RenderX - v55;
        if ( fabs(v35) >= 3.141592653589793 )
        {
          if ( v35 >= 0.0 )
            v35 = v35 - 6.2831855;
          else
            v35 = v35 + 6.2831855;
        }
        if ( v35 <= v57 )
          RenderX = v55 + v57;
        else
          RenderX = this->RenderX;
      }
      v36 = v31 - v55;
      if ( fabs(v36) >= 3.141592653589793 )
      {
        if ( v36 >= 0.0 )
          v36 = v36 - 6.2831855;
        else
          v36 = v36 + 6.2831855;
      }
      if ( v36 < -v57 && carConditions != 2 && this->FuelLevel > 0.001 )
      {
        v37 = v55 - this->RenderX;
        if ( fabs(v37) >= 3.141592653589793 )
        {
          if ( v37 >= 0.0 )
            v37 = v37 - 6.2831855;
          else
            v37 = v37 + 6.2831855;
        }
        if ( v37 <= v57 )
          v31 = v55 - v57;
        else
          v31 = this->RenderX;
      }
    }
    v38 = *(float **)&this->gap_4350[4 * v24 + 4];
    v62 = v38[37];
    v61 = this->WorldPositionZ;
    v63 = v38[39];
    v39 = -sin(RenderX);
    v40 = -cos(RenderX);
    v41 = v38[8];
    v42 = v38[10];
    WorldPositionX = this->WorldPositionX;
    v43 = 1.0 / sqrt(v42 * v42 + v41 * v41);
    v64 = v43 * v41;
    v65 = v43 * v42;
    if ( v39 == 0.0 )
      *(_DWORD *)this->gap_4414 = 0;
    else
      *(float *)this->gap_4414 = (v62 * (v40 / v39) + v61 - WorldPositionX * (v40 / v39) - v63)
                               / (v65 - v64 * (v40 / v39));
    v66 = -sin(v31);
    v44 = -cos(v31);
    if ( v66 == 0.0 )
      *(_DWORD *)&this->gap_4414[4] = 0;
    else
      *(float *)&this->gap_4414[4] = (v62 * (v44 / v66) + v61 - WorldPositionX * (v44 / v66) - v63)
                                   / (v65 - v64 * (v44 / v66));
    v45 = -sin(this->RenderX);
    v46 = -cos(this->RenderX);
    if ( v45 == 0.0 )
      *(_DWORD *)&this->gap_4414[8] = 0;
    else
      *(float *)&this->gap_4414[8] = (v62 * (v46 / v45) + v61 - WorldPositionX * (v46 / v45) - v63)
                                   / (v65 - v64 * (v46 / v45));
    if ( carConditions != 2 && this->FuelLevel > 0.001 )
    {
      v47 = this->CurrentWaypointPtr;
      v48 = *(float *)(v47 + 80);
      v56 = *(float *)(v47 + 84);
      v49 = this->gap_4358;
      v50 = 5;
      do
      {
        v51 = *(_DWORD *)v49;
        if ( *(float *)(*(_DWORD *)v49 + 84) <= (double)v56 )
          v56 = *(float *)(v51 + 84);
        if ( v48 >= *(float *)(v51 + 80) )
          v48 = *(float *)(v51 + 80);
        v49 += 4;
        --v50;
      }
      while ( v50 );
      if ( *(float *)this->gap_4414 > (double)v56 )
      {
        if ( v56 <= (double)*(float *)&this->gap_4414[4] )
          *(_DWORD *)this->gap_4414 = *(_DWORD *)&this->gap_4414[4];
        else
          *(float *)this->gap_4414 = v56;
      }
      v52 = -v48;
      if ( v52 > *(float *)&this->gap_4414[4] )
      {
        if ( v52 < *(float *)this->gap_4414 )
        {
          *(float *)&this->gap_4414[4] = v52;
          this->gap_4140[0] = 0;
          return 1;
        }
        *(_DWORD *)&this->gap_4414[4] = *(_DWORD *)this->gap_4414;
      }
    }
    this->gap_4140[0] = 0;
  }
  return 1;
}

