// AIAbility: Recalculates this[4431] (+0x453C) every frame. 3 write sites: +/-0.01 adjustment + probability override. External writes to this[4431] do NOT persist.
int __thiscall sub_429470(float *this)
{
  int v2; // ecx
  double v3; // st7
  double v4; // st7
  double v5; // st7
  int v6; // ecx
  float v7; // eax
  int v8; // eax
  int v9; // ecx
  double v10; // st7
  int v11; // ecx
  double v12; // st7
  float *v13; // ecx
  double v14; // st7
  double v15; // st7
  int v16; // eax
  int result; // eax
  float v18; // [esp+0h] [ebp-18h]
  float v19; // [esp+14h] [ebp-4h]
  float v20; // [esp+14h] [ebp-4h]
  float v21; // [esp+14h] [ebp-4h]
  float v22; // [esp+14h] [ebp-4h]

  v18 = this[4113];
  *((_DWORD *)this + 4433) = 1;
  if ( RingBufferAccessWithWrap(v18) == 2 )
  {
    this[4433] = 0.0;
    this[4447] = AIDifficultyScalar() * 0.75;
  }
  else if ( !RingBufferAccessWithWrap(this[4113]) || RingBufferAccessWithWrap(this[4113]) == 1 )
  {
    this[4447] = AIDifficultyScalar();
    if ( dword_7C56A4 == 7 )
    {
      if ( this[4418] == 0.0 )
      {
        v3 = this[4431] - 0.0099999998;
        if ( this[4413] > v3 )
          v3 = this[4413];
      }
      else
      {
        v3 = this[4406] + this[4413];
        v19 = this[4431] + 0.0099999998;
        if ( v3 >= v19 )
          v3 = v19;
      }
      this[4431] = v3;
      if ( this[4419] != 0.0 )
      {
        if ( (this[4405] - this[4419] * 0.5) * 100.0 >= (double)(RandLCGRandomNumberGenerator(v2) % 100) )
        {
          v4 = this[4406] + this[4413];
          v21 = this[4431] + 0.0099999998;
          if ( v4 >= v21 )
            v4 = v21;
        }
        else
        {
          v4 = this[4413] * 0.5;
          v20 = this[4431] - 0.0099999998;
          if ( v4 <= v20 )
            v4 = v20;
        }
        this[4431] = v4;
      }
      this[4418] = 0.0;
      this[4419] = 0.0;
    }
  }
  if ( *((_DWORD *)this + 4121) == 1 )
  {
    v5 = AIDifficultyScalar();
    this[4433] = 0.0;
    this[4447] = v5 * 0.75;
  }
  v6 = *((_DWORD *)this + 3931);
  if ( v6 != 2 && this[3681] > 0.001 && this[4096] <= 0.0 )
  {
    if ( v6 == 1 )
    {
      v7 = *this;
      if ( *(_DWORD *)(*(_DWORD *)this + 3284) && !*(_BYTE *)(LODWORD(v7) + 3348)
        || *(_DWORD *)(LODWORD(v7) + 3352) && !*(_BYTE *)(LODWORD(v7) + 3416)
        || *((_BYTE *)this + 14842) && *((_DWORD *)this + 4111) + 2 < dword_8ACF8C )
      {
        ForcePitExit(this);
      }
      this[4431] = this[4413] * 0.85000002;
    }
    goto LABEL_61;
  }
  if ( dword_7C56A4 != 7
    || *((_DWORD *)this + 4111) != dword_8ACF8C - 1
    || (v8 = *((_DWORD *)this + 4112), v8 != 2) && v8 != -1
    || this[4368] < 5.0 )
  {
    v9 = *((_DWORD *)this + 4309);
    this[4429] = dbl_8AFEA0 + 120.0;
    if ( this[4362] + *(float *)(v9 + 56) >= *(float *)(v9 + 52) - this[4362] )
      v10 = *(float *)(v9 + 56);
    else
      v10 = -*(float *)(v9 + 52);
    this[4360] = v10;
    *((_BYTE *)this + 17785) = 0;
    if ( dword_7C56A4 == 7 )
    {
      ConditionalGate(this + 3);
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
      PitStopDecisionTireCompound(this);
      v11 = 4 * *((_DWORD *)this + 4472);
      v12 = this[v11 + 4453];
      v13 = &this[v11 + 4453];
      if ( v12 >= 1.0 )
        v14 = *v13;
      else
        v14 = 1.0;
      if ( this[3682] >= v14 )
      {
        if ( *v13 < 1.0 )
        {
          SpeedValueSetterWithGlobalMirror(1065353216);
LABEL_57:
          PostPitCleanup(this);
          this[4433] = 0.0;
          ParameterValueSetter(18);
          *((_DWORD *)this + 4436) = 1;
          *((_BYTE *)this + 17736) = 1;
          this[4367] = 0.0;
          this[3390] = 0.0;
          this[3392] = 0.0;
          this[3391] = 0.0;
          this[4350] = 0.0;
          AIClearStateFlags(this);
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
          sub_426430((int)this);
          this[4429] = dbl_8AFEA0 + 180.0;
          goto LABEL_61;
        }
        v15 = *v13;
      }
      else
      {
        v15 = this[3682];
      }
      v22 = v15;
      SpeedValueSetterWithGlobalMirror(LODWORD(v22));
      goto LABEL_57;
    }
  }
LABEL_61:
  if ( *((_DWORD *)this + 4478) )
  {
    if ( dword_7C56A4 == 7 && FuelMultiplierValue(this) < 2 )
    {
      v16 = FuelMultiplierValue(*((_DWORD *)this + 4478));
      if ( v16 > 0
        && v16 < 3
        && !(unsigned __int8)FuelWeightLimitCheck(*((_DWORD *)this + 4478))
        && !(unsigned __int8)FuelWeightLimitCheck(this) )
      {
        ForcePitExit(this);
      }
    }
  }
  result = RacePhasePitEntryTrigger(this);
  this[4396] = NAN;
  return result;
}
