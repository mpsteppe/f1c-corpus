char __thiscall PitStopDecisionTireCompound(F1CVehicle *this)
{
  int v2; // eax
  int v3; // edx
  double v4; // st7
  int lapNumber; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // ecx
  double v10; // st7
  double v11; // st7
  float postProcessInput; // eax
  int v13; // edi
  float nextChosenTires__rw; // eax
  int i; // ebp
  unsigned __int8 *gap_32CC; // ecx
  char v18; // [esp+13h] [ebp-9h]
  float v19; // [esp+14h] [ebp-8h]
  int nextChosenTires_low; // [esp+14h] [ebp-8h]
  float v21; // [esp+18h] [ebp-4h]
  unsigned __int8 *v22; // [esp+18h] [ebp-4h]

  v2 = *(_DWORD *)&this->gap_45D4[12];
  v3 = *(_DWORD *)&this->gap_4578[16];
  v18 = 1;
  LOBYTE(this->PitLaneRouteFlag) = 1;
  this->gap_4578[12] = 0;
  if ( v2 + 1 > v3 )
  {
    if ( dword_7C56A4 == 7 )
    {
      if ( dword_7C56A8 != 8 )
        this->gap_4578[12] = 1;
      v4 = (double)(dword_8ACF8C - this->lapNumber) + 1.5;
    }
    else
    {
      v4 = (double)*(&this->PitStopSchedule0 + 4 * v2) - (double)this->lapNumber;
    }
  }
  else
  {
    v4 = (double)(*(_DWORD *)&this->gap_4594[16 * v2 + 12] - this->lapNumber) + 1.5;
  }
  v19 = v4;
  if ( *(_DWORD *)(LODWORD(this->postProcessInput) + 3352)
    && !*(_BYTE *)(LODWORD(this->postProcessInput) + 3416)
    && dword_7C56A4 == 7 )
  {
    ConditionalGate(&this->gap_0004[8]);
    lapNumber = this->lapNumber;
    v6 = 16 * (*(_DWORD *)&this->gap_45D4[12] + 1113);
    this->gap_4578[12] = 0;
    *(_DWORD *)((char *)&this->postProcessInput + v6) = lapNumber;
    *(_DWORD *)&this->gap_4594[16 * *(_DWORD *)&this->gap_45D4[12] + 8] = 8;
  }
  if ( this->gap_39A8[82] && dword_7C56A4 == 7 )
  {
    ConditionalGate(&this->gap_0004[8]);
    v7 = this->lapNumber;
    v8 = 16 * (*(_DWORD *)&this->gap_45D4[12] + 1113);
    this->gap_4578[12] = 0;
    *(_DWORD *)((char *)&this->postProcessInput + v8) = v7;
    *(_DWORD *)&this->gap_4594[16 * *(_DWORD *)&this->gap_45D4[12] + 8] = 8;
  }
  if ( PitStopBlockingCondition(this) || dword_7C56A4 != 7 )
  {
    v18 = 0;
    SceneRenderUpdate((int *)LODWORD(this->postProcessInput), 0.0);
    this->timeOfNextExit = dbl_8AFEA0 + 180.0;
    if ( dword_7C56A4 == 7 )
    {
      v9 = LODWORD(this->postProcessInput) + 16436;
      LOBYTE(this->RetiredFlag) = 1;
      LOBYTE(this->AIControlFlag) = 0;
      sub_4BC060(v9, 1);
    }
  }
  if ( v19 >= 3.0 )
    v10 = v19;
  else
    v10 = 3.0;
  v11 = v10 * *(float *)&this->gap_45D4[20];
  if ( *(float *)this->gap_3988 < v11 )
    v11 = *(float *)this->gap_3988;
  v21 = v11;
  *(float *)&this->gap_4594[16 * *(_DWORD *)&this->gap_45D4[12]] = v11;
  ClampedIndexAssignment((int)this->gap_32CC, v21);
  if ( !v18 )
  {
    SpeedValueSetterWithGlobalMirror((int)&this->gap_0004[8], v21);
    PostPitCleanup(this);
  }
  postProcessInput = this->postProcessInput;
  if ( *(_DWORD *)(LODWORD(this->postProcessInput) + 3284) && !*(_BYTE *)(LODWORD(postProcessInput) + 3348)
    || *(_DWORD *)(LODWORD(postProcessInput) + 3352) && !*(_BYTE *)(LODWORD(postProcessInput) + 3416) )
  {
    StateTransition(this->gap_32CC, 1);
  }
  if ( flt_8AFEE8 >= 0.0099999998 )
  {
    if ( flt_8AFEE8 >= 0.33000001 )
    {
      nextChosenTires_low = 5;
      if ( flt_8AFEE8 >= 0.66000003 )
        nextChosenTires_low = 6;
    }
    else
    {
      nextChosenTires_low = 4;
    }
  }
  else
  {
    nextChosenTires_low = LODWORD(this->nextChosenTires);
  }
  v13 = 0;
  v22 = &this->gap_45F8[8];
  do
  {
    if ( *(_DWORD *)v22 == nextChosenTires_low )
    {
      nextChosenTires__rw = this->nextChosenTires__rw_;
      for ( i = 0; LODWORD(nextChosenTires__rw) != v13; nextChosenTires__rw = this->nextChosenTires__rw_ )
      {
        gap_32CC = this->gap_32CC;
        if ( SLODWORD(nextChosenTires__rw) >= v13 )
          IndexDecrementWithBoundsWrap(gap_32CC, 2);
        else
          UtilityFunction_5750(gap_32CC, 2);
        if ( ++i > 7 )
          break;
      }
    }
    ++v13;
    v22 += 4;
  }
  while ( v13 < 7 );
  return v18;
}

