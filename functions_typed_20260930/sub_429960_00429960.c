int __thiscall sub_429960(F1CVehicle *this)
{
  char *v2; // eax
  unsigned __int8 *v3; // eax
  int v4; // ecx
  double v5; // st7
  double v6; // st7
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  int v10; // ebp
  int *p_PitStopSchedule0; // edi
  int i; // ecx
  int v13; // edx
  int v14; // edi
  _DWORD *v15; // edx
  int v16; // eax
  int v17; // ecx
  int *v18; // eax
  int v19; // edx
  int v20; // edi
  double v21; // st7
  int v22; // eax
  unsigned __int8 *gap_4594; // ecx
  int v24; // edx
  double v25; // st6
  int v26; // ecx
  int *v27; // eax
  int v28; // eax
  int v29; // ebp
  unsigned __int8 *v30; // edi
  double v31; // st7
  int v32; // ecx
  int *v33; // eax
  int result; // eax
  int v35; // eax
  float v36; // [esp+8h] [ebp-28h]
  float v37; // [esp+8h] [ebp-28h]
  int v38; // [esp+8h] [ebp-28h]
  float v39; // [esp+8h] [ebp-28h]
  int v40; // [esp+8h] [ebp-28h]
  float v41; // [esp+8h] [ebp-28h]
  int v42; // [esp+Ch] [ebp-24h]
  char v43[3]; // [esp+10h] [ebp-20h] BYREF
  _BYTE v44[29]; // [esp+13h] [ebp-1Dh] BYREF

  v2 = TireNameAccessor((int)&this->gap_0004[8]);
  LODWORD(this->nextChosenTires) = TireCompoundNameIDMapping(v2);
  v3 = &this->gap_4594[4];
  v4 = 5;
  do
  {
    *((_DWORD *)v3 - 2) = dword_8ACF8C;
    *(_DWORD *)v3 = 1;
    *((_DWORD *)v3 - 1) = 1176256410;
    *((_DWORD *)v3 + 1) = 0;
    v3 += 16;
    --v4;
  }
  while ( v4 );
  v5 = this->fuelConsumptionFactor * flt_5EA40C;
  if ( v5 < 1.0 )
    v5 = 1.0;
  *(float *)&this->gap_45D4[20] = v5;
  v36 = (double)dword_7D0B64 * 1.2;
  if ( v5 < v36 )
  {
    if ( v36 >= 1.0 )
      v6 = v36;
    else
      v6 = 1.0;
    *(float *)&this->gap_45D4[20] = v6;
  }
  *(_DWORD *)&this->gap_45D4[12] = 0;
  *(_DWORD *)&this->gap_45D4[28] = 1176255488;
  if ( dword_7C56A4 == 7 )
  {
    v7 = (_DWORD *)SeasonRacesSectionFinder(0);
    if ( v7 )
    {
      v8 = StringKeyedLinkedListSearch(v7, (int)aPitstopstrateg);
      if ( v8 )
      {
        v9 = StringKeyedLinkedListSearch(v8, LODWORD(this->postProcessInput) + 17952);
        if ( v9 )
        {
          strcpy(v43, DataEntryAccessor(v9));
          v37 = (float)dword_7D0B64;
          switch ( v43[0] )
          {
            case '1':
              *(_DWORD *)&this->gap_4578[16] = v43[0] - 48;
              StrlenFormatCallWrapper((int)v44, "%d", &this->PitStopSchedule0);
              *(_DWORD *)&this->gap_4594[12] = dword_8ACF8C;
              break;
            case '2':
              *(_DWORD *)&this->gap_4578[16] = 2;
              StrlenFormatCallWrapper((int)v44, "%d,%d", &this->PitStopSchedule0, &this->gap_4594[12]);
              *(_DWORD *)&this->gap_4594[28] = dword_8ACF8C;
              break;
            case '3':
              *(_DWORD *)&this->gap_4578[16] = 3;
              StrlenFormatCallWrapper(
                (int)v44,
                "%d,%d,%d",
                &this->PitStopSchedule0,
                &this->gap_4594[12],
                &this->gap_4594[28]);
              *(_DWORD *)&this->gap_4594[44] = dword_8ACF8C;
              break;
            default:
              *(_DWORD *)&this->gap_4578[16] = 4;
              StrlenFormatCallWrapper(
                (int)v44,
                "%d,%d,%d,%d",
                &this->PitStopSchedule0,
                &this->gap_4594[12],
                &this->gap_4594[28],
                &this->gap_4594[44]);
              LODWORD(this->numberOfLaps__wheel_) = dword_8ACF8C;
              break;
          }
          v10 = 0;
          if ( *(int *)&this->gap_4578[16] > 0 )
          {
            p_PitStopSchedule0 = &this->PitStopSchedule0;
            do
            {
              if ( v37 == 0.0 )
                *p_PitStopSchedule0 = 0;
              else
                *p_PitStopSchedule0 = CRTFtol((double)*p_PitStopSchedule0 / v37);
              ++v10;
              p_PitStopSchedule0 += 4;
            }
            while ( v10 < *(_DWORD *)&this->gap_4578[16] );
          }
          for ( i = 0; i < *(_DWORD *)&this->gap_4578[16]; ++i )
          {
            v13 = 16 * (i + 1113);
            v14 = *(_DWORD *)((char *)&this->postProcessInput + v13);
            v15 = (_DWORD *)((char *)&this->postProcessInput + v13);
            if ( v14 > dword_8ACF8C - 5 )
            {
              *(_DWORD *)&this->gap_4578[16] = i;
              if ( i < 5 )
              {
                v16 = 5 - i;
                i = 5;
                do
                {
                  *v15 = dword_8ACF8C;
                  v15 += 4;
                  --v16;
                }
                while ( v16 );
              }
            }
          }
          v17 = 0;
          if ( *(int *)&this->gap_4578[16] > 0 )
          {
            v18 = &this->PitStopSchedule0;
            do
            {
              v38 = v18[4] - *v18;
              ++v17;
              v18 += 4;
              *((float *)v18 - 3) = (double)v38 * *(float *)&this->gap_45D4[20];
            }
            while ( v17 < *(_DWORD *)&this->gap_4578[16] );
          }
        }
      }
    }
    if ( !dword_7D0B64 && !dword_7D0C60 )
    {
      *(_DWORD *)&this->gap_4578[16] = 0;
      this->PitStopSchedule0 = dword_8ACF8C;
    }
    *(_DWORD *)&this->gap_4594[16 * *(_DWORD *)&this->gap_4578[16] + 8] = 8;
  }
  else
  {
    switch ( dword_7C56A4 )
    {
      case 0:
      case 1:
      case 2:
      case 6:
        v28 = (RandLCGRandomNumberGenerator() % 2 != 0) + 3;
        v29 = 0;
        *(_DWORD *)&this->gap_4578[16] = v28;
        v41 = 0.0;
        if ( v28 > 0 )
        {
          v30 = &this->gap_4594[8];
          do
          {
            v31 = (double)(RandLCGRandomNumberGenerator() % 5 + 3) + v41;
            v41 = v31;
            *((_DWORD *)v30 - 3) = CRTFtol(v31);
            *(_DWORD *)v30 = 8;
            ++v29;
            v30 += 16;
          }
          while ( v29 < *(_DWORD *)&this->gap_4578[16] );
        }
        v32 = 0;
        if ( *(int *)&this->gap_4578[16] > 0 )
        {
          v33 = &this->PitStopSchedule0;
          do
          {
            v42 = v33[4] - *v33;
            ++v32;
            v33 += 4;
            *((float *)v33 - 3) = ((double)v42 + 2.0) * *(float *)&this->gap_45D4[20];
          }
          while ( v32 < *(_DWORD *)&this->gap_4578[16] );
        }
        break;
      case 3:
      case 4:
      case 5:
        v19 = (RandLCGRandomNumberGenerator() % 21 != 0) + 3;
        v20 = 0;
        *(_DWORD *)&this->gap_4578[16] = v19;
        if ( v19 > 0 )
        {
          v39 = 12.0 / (double)v19;
          v21 = v39 + 2.0;
          v22 = CRTFtol(v21);
          gap_4594 = this->gap_4594;
          v24 = v22 - 1;
          do
          {
            *((_DWORD *)gap_4594 - 1) = v24;
            v25 = v21 * *(float *)&this->gap_45D4[20];
            *((_DWORD *)gap_4594 + 2) = 8;
            ++v20;
            v24 += v22;
            *(float *)gap_4594 = v25;
            gap_4594 += 16;
          }
          while ( v20 < *(_DWORD *)&this->gap_4578[16] );
        }
        v26 = 0;
        if ( *(int *)&this->gap_4578[16] > 0 )
        {
          v27 = &this->PitStopSchedule0;
          do
          {
            v40 = v27[4] - *v27;
            ++v26;
            v27 += 4;
            *((float *)v27 - 3) = ((double)v40 + 2.0) * *(float *)&this->gap_45D4[20];
          }
          while ( v26 < *(_DWORD *)&this->gap_4578[16] );
        }
        break;
      default:
        break;
    }
  }
  if ( this->PitStopSchedule0 < 1 )
    this->PitStopSchedule0 = 1;
  *(float *)&this->gap_45D4[28] = ((double)this->PitStopSchedule0 + 2.0) * *(float *)&this->gap_45D4[20];
  if ( !dword_7D0B64 )
    *(_DWORD *)&this->gap_45D4[28] = 1065353216;
  if ( *(float *)this->gap_3988 < (double)*(float *)&this->gap_45D4[28] )
    *(float *)&this->gap_45D4[28] = *(float *)this->gap_3988;
  result = LODWORD(this->postProcessInput);
  if ( *(_DWORD *)(LODWORD(this->postProcessInput) + 13000) == 1 )
  {
    SpeedValueSetterWithGlobalMirror((int)&this->gap_0004[8], *(float *)&this->gap_45D4[28]);
    v35 = RandomWeightedTierSelection(this);
    LoopWithConditionalSubCall(&this->gap_0004[8], v35, 1);
  }
  return result;
}

