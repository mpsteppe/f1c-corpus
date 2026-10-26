double __thiscall PitStopOperationTimer(F1CPitMachine *this)
{
  float *p_refuel_progress; // edi
  float *v3; // ecx
  _DWORD *vehicle; // ecx
  int v5; // eax
  _DWORD *v6; // ecx
  double v7; // st7
  int v8; // ebp
  int v9; // edi
  int v10; // edx
  unsigned __int8 *v11; // ecx
  int v12; // eax
  int v13; // eax
  unsigned __int8 *v14; // ecx
  float *v15; // ecx
  double v16; // st6
  double fuel_target; // st6
  double v18; // st6
  double v19; // st6
  double v20; // st6
  double v21; // st6
  int v22; // edx
  int i; // ecx
  double v24; // st7
  double v25; // st7
  double v26; // st7
  int valid; // eax
  _DWORD *v28; // ecx
  int v29; // ebp
  int v30; // edi
  double v31; // st7
  int v32; // ecx
  double v33; // st7
  double v34; // st7
  _DWORD *v35; // ecx
  _BYTE *v36; // ecx
  double v37; // st7
  double v38; // st7
  double v39; // st7
  _DWORD *v40; // ecx
  _DWORD *v41; // ecx
  int v43; // [esp+0h] [ebp-68h]
  int v44; // [esp+0h] [ebp-68h]
  int v45; // [esp+4h] [ebp-64h]
  float v46; // [esp+14h] [ebp-54h]
  float v47; // [esp+18h] [ebp-50h]
  float v48; // [esp+18h] [ebp-50h]
  float v49[5]; // [esp+1Ch] [ebp-4Ch] BYREF
  float v50; // [esp+30h] [ebp-38h] BYREF
  char v51; // [esp+34h] [ebp-34h]
  float v52[6]; // [esp+38h] [ebp-30h]
  char v53; // [esp+50h] [ebp-18h]
  float v54; // [esp+54h] [ebp-14h]
  int v55; // [esp+58h] [ebp-10h]
  float v56; // [esp+5Ch] [ebp-Ch]
  int v57; // [esp+60h] [ebp-8h]
  float v58; // [esp+64h] [ebp-4h]

  p_refuel_progress = &this->refuel_progress;
  v3 = &this->refuel_progress;
  *v3 = 0.0;
  v3[1] = 0.0;
  v3[2] = 0.0;
  v3[3] = 0.0;
  v3[4] = 0.0;
  vehicle = this->vehicle;
  v46 = 0.0;
  if ( *(_DWORD *)&this->gap_008[36] )
  {
    v5 = ProgressBarIncrement(vehicle + 4109);
    v6 = *(_DWORD **)this->gap_008;
    LODWORD(v49[0]) = v5;
    *(_DWORD *)p_refuel_progress = 1;
    v46 = (float)v5;
    if ( v6 )
    {
      v49[0] = (float)v5;
      PhysicsChannelProcessingWithLocals(v6, v49);
      FlagSetterWithOR(*(_DWORD **)this->gap_008, LODWORD(this->stop_start_time));
    }
  }
  else
  {
    v7 = 0.0;
    if ( !vehicle[3250] )
    {
      v7 = (this->state_enter_time + 25.0 - dbl_8AFEA0) * 0.5;
      if ( v7 >= 0.0 )
      {
        if ( v7 > 4.5 )
          v7 = 4.5;
      }
      else
      {
        v7 = 0.0;
      }
      v8 = vehicle[4111];
      if ( vehicle[4112] == 2 )
        ++v8;
      v9 = *(_DWORD *)&this->gap_008[344];
      v10 = 0;
      if ( v9 > 0 )
      {
        v11 = &this->gap_008[348];
        while ( 1 )
        {
          v12 = *(_DWORD *)v11;
          if ( *(int *)v11 >= 0 )
            break;
          ++v10;
          v11 += 8;
          if ( v10 >= v9 )
            goto LABEL_22;
        }
        if ( v8 <= v12 + 1 && v8 < v12 - 1 )
        {
          v13 = v10 + 1;
          if ( v10 + 1 < v9 )
          {
            v14 = &this->gap_008[8 * v13 + 348];
            do
            {
              *(_DWORD *)v14 = 0x80000000;
              ++v13;
              v14 += 8;
            }
            while ( v13 < *(_DWORD *)&this->gap_008[344] );
          }
        }
        *(_DWORD *)&this->gap_008[8 * v10 + 348] = 0x80000000;
      }
    }
LABEL_22:
    v15 = (float *)this->vehicle;
    v50 = v7;
    v52[4] = 5.5;
    v52[5] = 1.0;
    v55 = 1065353216;
    v57 = 1056964608;
    v58 = 0.0;
    this->fuel_start = v15[3681];
    v16 = (double)*(int *)&this->gap_008[100] * *(double *)&this->gap_008[88] + *(double *)&this->gap_008[80];
    this->fuel_target = v16;
    v49[0] = v16;
    if ( v16 <= this->fuel_start )
    {
      if ( dword_7C56A4 != 7 )
        SpeedValueSetterWithGlobalMirror((int)(v15 + 3), v49[0]);
      v53 = 0;
    }
    else
    {
      fuel_target = this->fuel_target;
      this->refuel_active = 1;
      v49[0] = (fuel_target - this->fuel_start) * 0.083333336;
      v18 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
      v19 = v18 + v18;
      v47 = v19;
      v20 = v19 + v49[0] + v7 + 1.5;
      if ( v20 > 0.0 )
        v46 = v20;
      v21 = v47 + this->stop_start_time;
      v53 = 1;
      v54 = v47;
      v56 = v49[0];
      this->fuel_start_time = v21 + v7 + 1.0;
    }
    if ( *(_DWORD *)&this->gap_008[164] )
    {
      v22 = dword_8AAE70;
      v48 = 0.0;
      for ( i = 0; i < 4; ++i )
      {
        v24 = flt_8AAE74[(unsigned __int8)v22++];
        dword_8AAE70 = v22;
        v25 = v24 * (v24 * v24) + v24 * (v24 * v24);
        v49[i + 1] = v25;
        if ( v48 < v25 )
          v48 = v25;
        v52[i] = v25;
      }
      v26 = v48 + v50 + 6.5;
      if ( v46 < v26 )
        v46 = v26;
      v43 = *(_DWORD *)&this->gap_008[164];
      this->tire_change_active = 1;
      v51 = 1;
      valid = NthValidPartLookup(this, v43);
      v28 = *(_DWORD **)&this->gap_008[336];
      v29 = valid;
      v30 = 0;
      if ( (int)v28[4] > 0 )
      {
        while ( v29 != CompoundIndexLookup(v28, v30) )
        {
          v28 = *(_DWORD **)&this->gap_008[336];
          if ( ++v30 >= v28[4] )
            goto LABEL_41;
        }
        LoopWithConditionalSubCall((char *)this->vehicle + 12, v30, 1);
      }
LABEL_41:
      v31 = v48 + this->stop_start_time;
      this->tire_service_start_time = this->stop_start_time;
      this->tire_service_end_time = v31 + v50 + 5.5;
    }
    else
    {
      v51 = 0;
    }
    v32 = *(_DWORD *)&this->gap_008[228];
    if ( v32 != *(_DWORD *)&this->gap_008[232] )
    {
      v33 = v50;
      this->wing_adjustment_active = 1;
      v34 = v33 + 8.0;
      if ( v46 < v34 )
        v46 = v34;
      if ( v58 < 8.0 )
        v58 = 8.0;
      *(_DWORD *)&this->gap_008[232] = v32;
      ConditionalMathDispatch(
        (_DWORD *)this->vehicle + 3,
        27,
        (double)*(int *)&this->gap_008[228] * *(double *)&this->gap_008[216] + *(double *)&this->gap_008[208]);
    }
    if ( *(_DWORD *)&this->gap_008[292] )
    {
      this->repair_active = 1;
      v35 = dword_8AAE64;
      if ( dword_83EE60 < 1023 )
      {
        ++dword_83EE60;
        dword_8AAE64 = (char *)dword_8AAE64 + 432;
      }
      *(float *)&v44 = dbl_8AFEA0;
      ProgressBarEventEncode(v35, 6, 0, 0, this->pit_team_index, v44, 0);
      v36 = this->vehicle;
      v37 = v50 + 8.5;
      if ( *((_DWORD *)this->vehicle + 821) )
      {
        if ( !v36[3348] )
        {
          v49[0] = v50 + 8.0;
          if ( v37 <= v49[0] )
            v37 = v49[0];
        }
      }
      if ( *((_DWORD *)v36 + 838) )
      {
        if ( !v36[3416] )
        {
          v49[0] = v50 + 39.0;
          if ( v37 <= v49[0] )
            v37 = v49[0];
        }
      }
      v38 = v37 + flt_8AAE74[(unsigned __int8)dword_8AAE70++];
      if ( v46 < v38 )
        v46 = v38;
      v39 = v38 - v50;
      if ( v58 < v39 )
        v58 = v39;
    }
    v40 = *(_DWORD **)this->gap_008;
    if ( v40 )
    {
      sub_4A35F0(v40, (int)&v50);
      FlagSetterWithOR(*(_DWORD **)this->gap_008, LODWORD(this->stop_start_time));
      PerElementConditionalActionDispatcher(*(_DWORD **)this->gap_008, 1);
      if ( dword_7CF884 > 0 )
      {
        v41 = (char *)this->vehicle + 1776;
        if ( *((_BYTE *)this->vehicle + 4188) )
        {
          v45 = *((_DWORD *)this->vehicle + 1045);
          *((_BYTE *)this->vehicle + 4188) = 0;
          AudioSoundEffectController(v41, v45);
        }
      }
    }
  }
  if ( *((_DWORD *)this->vehicle + 3250) == 1 && PitStopBlockingCondition((F1CVehicle *)this->vehicle) )
    return 0.0;
  else
    return v46;
}

