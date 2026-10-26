int __thiscall sub_434460(float *this)
{
  int v2; // ebp
  bool v3; // zf
  int v4; // eax
  double v5; // st7
  int v6; // eax
  int v7; // ecx
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // esi
  int v18; // [esp+0h] [ebp-3Ch]
  float v19; // [esp+4h] [ebp-38h]
  int v20; // [esp+8h] [ebp-34h]
  float v21; // [esp+1Ch] [ebp-20h] BYREF
  int v22; // [esp+20h] [ebp-1Ch]
  float v23; // [esp+24h] [ebp-18h] BYREF
  int v24; // [esp+28h] [ebp-14h] BYREF
  int v25; // [esp+2Ch] [ebp-10h] BYREF
  int v26; // [esp+30h] [ebp-Ch]

  v2 = 0;
  v3 = *(_BYTE *)this == 0;
  v22 = 0;
  if ( v3 )
  {
    v2 = ModuleInitializationWithFallback();
    v22 = v2;
    LOBYTE(v21) = 0;
    goto LABEL_40;
  }
  v4 = *((_DWORD *)this + 1);
  if ( !v4 )
  {
    sub_4D8760(2, 1);
    *((_DWORD *)this + 1) = 1;
    this[10] = 0.0;
    LOBYTE(v21) = 0;
    this[9] = 3.0;
    goto LABEL_40;
  }
  if ( v4 == 1 )
  {
    v5 = this[9];
    LOBYTE(v21) = 0;
    if ( v5 <= 0.0 )
    {
      *((_DWORD *)this + 1) = 2;
      this[9] = 2.0;
    }
    else
    {
      this[9] = this[9] - dbl_8AFE98;
    }
LABEL_39:
    this[10] = dbl_8AFE98 + this[10];
    goto LABEL_40;
  }
  LOBYTE(v21) = 1;
  if ( v4 != 2 )
  {
    if ( v4 == 5 )
    {
      if ( this[9] <= 0.0 )
      {
        v2 = 1;
        v22 = 1;
      }
      else
      {
        this[9] = this[9] - dbl_8AFE98;
      }
      goto LABEL_40;
    }
    if ( ScoreThresholdGateCheck(520) )
    {
      if ( (unsigned __int8)StateFlagCheck_5240(this) )
      {
        v6 = *((_DWORD *)this + 6) + 1;
        v7 = *((_DWORD *)this + 6) + 3;
        *((_DWORD *)this + 6) = v6;
        *((_DWORD *)this + 11) = v7;
        if ( v6 < dword_5C329C )
        {
          v8 = 0;
          if ( dword_5C329C > 0 )
          {
            v9 = v6 + 1;
            while ( 1 )
            {
              this[7] = 0.0;
              if ( *(_DWORD *)(dword_7C54F0[v8] + 16480) == v9 )
                break;
              if ( ++v8 >= dword_5C329C )
                goto LABEL_26;
            }
            *((_DWORD *)this + 7) = v8;
          }
LABEL_26:
          IteratorCheck(&dword_8AD298);
          PitExit(dword_5EB978, *((_DWORD *)this + 6));
        }
        else
        {
          *((_DWORD *)this + 1) = 5;
          *((_DWORD *)this + 6) = v6 - 1;
          this[9] = 3.0;
        }
      }
    }
    else if ( this[13] > 0.0 )
    {
      this[13] = this[13] - dbl_8AFE98;
    }
    else
    {
      v10 = *((_DWORD *)this + 6) + 1;
      v11 = *((_DWORD *)this + 6) + 3;
      this[13] = 2.25;
      *((_DWORD *)this + 6) = v10;
      *((_DWORD *)this + 11) = v11;
      if ( v10 < dword_5C329C )
      {
        v12 = 0;
        if ( dword_5C329C > 0 )
        {
          v13 = v10 + 1;
          while ( 1 )
          {
            this[7] = 0.0;
            if ( *(_DWORD *)(dword_7C54F0[v12] + 16480) == v13 )
              break;
            if ( ++v12 >= dword_5C329C )
              goto LABEL_34;
          }
          *((_DWORD *)this + 7) = v12;
        }
LABEL_34:
        IteratorCheck(&dword_8AD298);
      }
      else
      {
        *((_DWORD *)this + 1) = 5;
        *((_DWORD *)this + 6) = v10 - 1;
        this[9] = 3.0;
      }
    }
    v2 = v22;
    goto LABEL_39;
  }
  *((_DWORD *)this + 11) = 1;
  if ( (unsigned __int8)StateFlagCheck_5240(this) )
  {
    *((_DWORD *)this + 1) = 4;
    sub_4D8760(0, 1);
  }
LABEL_40:
  v14 = *((_DWORD *)this + 3);
  if ( !v14 || !*(_DWORD *)(v14 + 176) )
    return v2;
  v20 = *((_DWORD *)this + 11);
  v23 = *(float *)(v14 + 188);
  v15 = StridedArrayElementPointer(v20);
  if ( v15 )
  {
    if ( *(float *)(v15 + 24) > (double)v23 )
      SteeringInterpolationCameraFollow(SLOBYTE(v21));
  }
  ShortComputation_c910(&dword_5EA510);
  v16 = *((_DWORD *)this + 3);
  if ( !v16 )
    return v2;
  dword_5EA538 = v16;
  byte_5EA535 = 1;
  v26 = *(_DWORD *)(v16 + 24);
  UtilityFunction_1cd0(
    *(_DWORD *)(v16 + 12),
    *(_DWORD *)(v16 + 16),
    *(float *)(v16 + 20),
    v26,
    *(_DWORD *)(v16 + 28),
    *(_DWORD *)(v16 + 32));
  DualFieldGetter(&v21, &v23);
  ShortComputation_6080(&v25, &v24);
  v19 = v23 * 0.01745433;
  *(float *)&v18 = v21 * 0.01745433;
  sub_542050(v18, v19, 0);
  TwoFieldSetterCall(v25, v24);
  ConditionalFloatSetter(*(float *)(v16 + 72));
  return v22;
}

