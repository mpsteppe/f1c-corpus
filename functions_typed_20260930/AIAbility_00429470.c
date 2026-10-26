// AIAbility: Recalculates this[4431] (+0x453C) every frame. 3 write sites: +/-0.01 adjustment + probability override. External writes to this[4431] do NOT persist.
int __thiscall AIAbility(float *this)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  double v9; // st7
  int v10; // ecx
  double v11; // st7
  float *v12; // ecx
  double v13; // st7
  double v14; // st7
  int v15; // eax
  int result; // eax
  float v17; // [esp+0h] [ebp-18h]
  float v18; // [esp+14h] [ebp-4h]
  float v19; // [esp+14h] [ebp-4h]
  float v20; // [esp+14h] [ebp-4h]
  float v21; // [esp+14h] [ebp-4h]

  v17 = this[4113];
  *((_DWORD *)this + 4433) = 1;
  if ( RingBufferAccessWithWrap((int)dword_8ACEE0, v17) == 2 )
  {
    this[4433] = 0.0;
    this[4447] = AIDifficultyScalar() * 0.75;
  }
  else if ( !RingBufferAccessWithWrap((int)dword_8ACEE0, this[4113])
         || RingBufferAccessWithWrap((int)dword_8ACEE0, this[4113]) == 1 )
  {
    this[4447] = AIDifficultyScalar();
    if ( dword_7C56A4 == 7 )
    {
      if ( this[4418] == 0.0 )
      {
        v2 = this[4431] - 0.0099999998;
        if ( this[4413] > v2 )
          v2 = this[4413];
      }
      else
      {
        v2 = this[4406] + this[4413];
        v18 = this[4431] + 0.0099999998;
        if ( v2 >= v18 )
          v2 = v18;
      }
      this[4431] = v2;
      if ( this[4419] != 0.0 )
      {
        if ( (this[4405] - this[4419] * 0.5) * 100.0 >= (double)(RandLCGRandomNumberGenerator() % 100) )
        {
          v3 = this[4406] + this[4413];
          v20 = this[4431] + 0.0099999998;
          if ( v3 >= v20 )
            v3 = v20;
        }
        else
        {
          v3 = this[4413] * 0.5;
          v19 = this[4431] - 0.0099999998;
          if ( v3 <= v19 )
            v3 = v19;
        }
        this[4431] = v3;
      }
      this[4418] = 0.0;
      this[4419] = 0.0;
    }
  }
  if ( *((_DWORD *)this + 4121) == 1 )
  {
    v4 = AIDifficultyScalar();
    this[4433] = 0.0;
    this[4447] = v4 * 0.75;
  }
  v5 = *((_DWORD *)this + 3931);
  if ( v5 != 2 && this[3681] > 0.001 && this[4096] <= 0.0 )
  {
    if ( v5 == 1 )
    {
      v6 = *(_DWORD *)this;
      if ( *(_DWORD *)(*(_DWORD *)this + 3284) && !*(_BYTE *)(v6 + 3348)
        || *(_DWORD *)(v6 + 3352) && !*(_BYTE *)(v6 + 3416)
        || *((_BYTE *)this + 14842) && *((_DWORD *)this + 4111) + 2 < dword_8ACF8C )
      {
        RequestPitEntry((F1CVehicle *)this);
      }
      this[4431] = this[4413] * 0.85000002;
    }
    goto LABEL_61;
  }
  if ( dword_7C56A4 != 7
    || *((_DWORD *)this + 4111) != dword_8ACF8C - 1
    || (v7 = *((_DWORD *)this + 4112), v7 != 2) && v7 != -1
    || this[4368] < 5.0 )
  {
    v8 = *((_DWORD *)this + 4309);
    this[4429] = dbl_8AFEA0 + 120.0;
    if ( this[4362] + *(float *)(v8 + 56) >= *(float *)(v8 + 52) - this[4362] )
      v9 = *(float *)(v8 + 56);
    else
      v9 = -*(float *)(v8 + 52);
    this[4360] = v9;
    *((_BYTE *)this + 17785) = 0;
    if ( dword_7C56A4 == 7 )
    {
      ConditionalGate((_DWORD *)this + 3);
      if ( this[4096] > 0.0 && !*((_DWORD *)this + 4122) )
        *((_DWORD *)this + 4122) = 6;
    }
    if ( this[4368] < 1.0 )
    {
      if ( dword_7C56A4 == 7 )
      {
        *((_BYTE *)this + 17908) = 0;
        goto LABEL_61;
      }
      *((_BYTE *)this + 17785) = 0;
      PitStopDecisionTireCompound((F1CVehicle *)this);
      v10 = 4 * *((_DWORD *)this + 4472);
      v11 = this[v10 + 4453];
      v12 = &this[v10 + 4453];
      if ( v11 >= 1.0 )
        v13 = *v12;
      else
        v13 = 1.0;
      if ( this[3682] >= v13 )
      {
        if ( *v12 < 1.0 )
        {
          SpeedValueSetterWithGlobalMirror((int)(this + 3), 1.0);
LABEL_57:
          PostPitCleanup((F1CVehicle *)this);
          this[4433] = 0.0;
          ParameterValueSetter((F1CVehicle *)this, 18);
          *((_DWORD *)this + 4436) = 1;
          *((_BYTE *)this + 17736) = 1;
          this[4367] = 0.0;
          this[3390] = 0.0;
          this[3392] = 0.0;
          this[3391] = 0.0;
          this[4350] = 0.0;
          AIClearStateFlags((int)this);
          if ( dword_7C56A4 == 7 )
            *((_DWORD *)this + 4420) = 4;
          else
            *((_DWORD *)this + 4420) = 5;
          this[4425] = 0.0;
          this[4366] = 1.0;
          this[4365] = 0.0;
          this[4435] = 0.0;
          *((_DWORD *)this + 4436) = 1;
          this[4361] = 0.0;
          sub_426430((F1CVehicle *)this);
          this[4429] = dbl_8AFEA0 + 180.0;
          goto LABEL_61;
        }
        v14 = *v12;
      }
      else
      {
        v14 = this[3682];
      }
      v21 = v14;
      SpeedValueSetterWithGlobalMirror((int)(this + 3), v21);
      goto LABEL_57;
    }
  }
LABEL_61:
  if ( *((_DWORD *)this + 4478) )
  {
    if ( dword_7C56A4 == 7 && FuelMultiplierValue(this) < 2 )
    {
      v15 = FuelMultiplierValue(*((float **)this + 4478));
      if ( v15 > 0 && v15 < 3 && !FuelWeightLimitCheck(*((_DWORD *)this + 4478)) && !FuelWeightLimitCheck((int)this) )
        RequestPitEntry((F1CVehicle *)this);
    }
  }
  result = RacePhasePitEntryTrigger(this);
  this[4396] = NAN;
  return result;
}

