void __thiscall sub_42B0E0(float *this)
{
  int v1; // ebp
  int v3; // edi
  double v4; // st7
  double v5; // st6
  double v6; // st7
  float *v7; // eax
  int v8; // eax
  double v9; // st7
  int v10; // eax
  double v11; // st7
  double v12; // st7
  double v13; // st7
  long double v14; // st7
  int v15; // ebx
  int v16; // edi
  long double v17; // st7
  double v18; // st7
  int v19; // eax
  int v20; // eax
  double v21; // st6
  double v22; // st7
  float v23; // [esp+0h] [ebp-B0h]
  float v24; // [esp+14h] [ebp-9Ch]
  float v25; // [esp+14h] [ebp-9Ch]
  int v26; // [esp+18h] [ebp-98h]
  float v27; // [esp+18h] [ebp-98h]
  float v28; // [esp+18h] [ebp-98h]
  float v29; // [esp+18h] [ebp-98h]
  float v30; // [esp+1Ch] [ebp-94h] BYREF
  float v31; // [esp+20h] [ebp-90h]
  float v32; // [esp+24h] [ebp-8Ch]
  float v33; // [esp+28h] [ebp-88h]
  float v34; // [esp+2Ch] [ebp-84h]
  float v35; // [esp+30h] [ebp-80h]
  float v36; // [esp+34h] [ebp-7Ch]
  float v37; // [esp+38h] [ebp-78h] BYREF
  float v38; // [esp+3Ch] [ebp-74h]
  float v39; // [esp+40h] [ebp-70h]
  float v40[2]; // [esp+44h] [ebp-6Ch] BYREF
  float v41; // [esp+4Ch] [ebp-64h]
  float v42[3]; // [esp+50h] [ebp-60h] BYREF
  float v43[9]; // [esp+5Ch] [ebp-54h] BYREF
  _BYTE v44[12]; // [esp+80h] [ebp-30h] BYREF
  _DWORD v45[3]; // [esp+8Ch] [ebp-24h] BYREF
  _DWORD v46[3]; // [esp+98h] [ebp-18h] BYREF
  _BYTE v47[12]; // [esp+A4h] [ebp-Ch] BYREF

  v1 = 0;
  if ( dword_7C56A8 == 3 )
  {
    v3 = 0;
    v26 = *((_DWORD *)this + 4120) - 1;
    if ( dword_5C329C > 0 )
    {
      while ( *(_DWORD *)(dword_7C54F0[v3] + 16480) != *((_DWORD *)this + 4120) - 1 )
      {
        if ( ++v3 >= dword_5C329C )
          goto LABEL_18;
      }
      v36 = DistanceProjectionCalc(this + 3);
      v4 = DistanceProjectionCalc(dword_7C54F0[v3] + 12) - v36;
      v5 = flt_5EA3FC;
      if ( v4 <= 0.5 * flt_5EA3FC )
      {
        if ( v4 < -0.5 * v5 )
          v4 = v4 + v5;
      }
      else
      {
        v4 = v4 - v5;
      }
      if ( v4 > -200.0 )
      {
        v6 = v4 + v4;
        if ( v6 >= 15.0 )
        {
          v24 = v6;
          TrackParameterMinimumClamp(this, v24);
        }
        else
        {
          TrackParameterMinimumClamp(this, 15.0);
        }
        if ( this[4368] < 1.0 )
        {
          v7 = (float *)dword_7C54F0[v3];
          if ( sqrt(v7[3390] * v7[3390] + v7[3391] * v7[3391] + v7[3392] * v7[3392]) < 0.2
            && ((double)v26 + 5.0) * 0.40000001 + flt_8ACF94 > dbl_8AFEA0 )
          {
            this[4365] = 0.0;
          }
        }
      }
    }
LABEL_18:
    if ( v3 == dword_5C329C )
      TrackParameterMinimumClamp(this, 49.0);
    if ( this[4365] > 0.89999998 )
      this[4365] = 0.89999998;
  }
  if ( dword_7C56A8 == 1 || dword_7C56A8 == 3 && flt_8ACF94 + 30.0 <= dbl_8AFEA0 )
  {
    v8 = *((_DWORD *)this + 3754);
    if ( v8 && *(_DWORD *)(v8 + 300) )
    {
      if ( dword_7C56A8 == 1 )
      {
        if ( (unsigned __int8)DistanceComparison(this + 3) )
        {
          if ( this[3690] > (double)this[3688] )
          {
            v27 = dbl_8AFEA0;
            if ( fabs(dbl_8AFEA0 - this[4376]) > 10.0 )
            {
              v9 = (double)*((int *)this + 1) * 8.5;
              InterruptDispatch(v9);
              if ( v27 <= v9 + 1.0 + this[4370] * 20.0 + flt_8ACF90 )
              {
                this[4363] = 0.0;
              }
              else
              {
                v10 = RandomWeightedTierSelection(this);
                LoopWithConditionalSubCall(v10, 1);
                v11 = this[4474] * 1.5 + this[3681];
                if ( v11 >= this[3682] )
                  v11 = this[3682];
                v28 = v11;
                SpeedValueSetterWithGlobalMirror(LODWORD(v28));
                VehicleClimbAdjust(0);
                v12 = dbl_8AFEA0;
                this[4309] = 0.0;
                this[4310] = 0.0;
                this[4376] = v12;
                *((_DWORD *)this + 4420) = 5;
                *((_DWORD *)this + 4436) = 1;
                this[4430] = flt_8ACFB4;
              }
            }
          }
        }
      }
    }
    else
    {
      SingleFunctionDispatch_10e0(*(_DWORD *)this, v42, v44);
      F_3DTransformWithMatrixMultiplication(&v37, v47);
      v33 = v42[0] - v37;
      v34 = v42[1] - v38;
      v13 = v42[2] - v39;
      v35 = v13;
      v14 = sqrt(v13 * v35 + v34 * v34 + v33 * v33);
      v36 = v14;
      v23 = v14 * 0.40000001 + 3.0;
      TrackParameterMinimumClamp(this, v23);
      if ( byte_7CEC18 )
      {
        v25 = 3.4028235e38;
        v15 = 104;
        if ( dword_5C329C + 2 <= 104 )
          v15 = dword_5C329C + 2;
        v16 = 0;
        if ( v15 > 0 )
        {
          do
          {
            sub_403CD0(dword_5EA2C0, v16, &v30, v40);
            v30 = v30 - v37;
            v31 = v31 - v38;
            v32 = v32 - v39;
            v17 = sqrt(v30 * v30 + v32 * v32 + v31 * v31);
            if ( v17 < v25 )
            {
              v25 = v17;
              v1 = v16;
            }
            ++v16;
          }
          while ( v16 < v15 );
          if ( v25 < 80.0 )
          {
            v18 = v25 - 20.0;
            if ( v18 >= 35.0 )
            {
              v29 = v18;
              TrackParameterMinimumClamp(this, v29);
            }
            else
            {
              TrackParameterMinimumClamp(this, 35.0);
            }
            if ( v25 < 35.0 )
            {
              if ( v1 >= 2 )
                v19 = v1 - 2;
              else
                v19 = 0;
              sub_403CD0(dword_5EA2C0, v19, v40, v45);
              v20 = 1;
              if ( v1 >= 1 )
                v20 = v1 - 1;
              sub_403CD0(dword_5EA2C0, v20, &v30, v46);
              v41 = v32 + v41;
              v30 = (v30 + v40[0]) * 0.5;
              v30 = v30 - v37;
              v31 = (v31 + v40[1]) * 0.5 - v38;
              v21 = v41 * 0.5 - v39;
              this[4363] = atan2(
                             -(v21 * this[3381] + v31 * this[3378] + v30 * this[3375]),
                             -(v21 * this[3383] + v31 * this[3380] + v30 * this[3377]))
                         / this[4397];
              if ( this[4363] >= -1.0 )
              {
                if ( this[4363] > 1.0 )
                  this[4363] = 1.0;
              }
              else
              {
                this[4363] = -1.0;
              }
            }
          }
        }
      }
      if ( v36 < 40.0 )
      {
        EulerToRotationMatrix(v44, v43);
        v22 = (v43[6] * 0.0 + v43[7] * 0.0 + v43[8] * -1.0) * v35
            + (v43[3] * 0.0 + v43[4] * 0.0 + v43[5] * -1.0) * v34
            + (v43[1] * 0.0 + v43[2] * -1.0 + v43[0] * 0.0) * v33;
        if ( v22 >= 0.0 )
        {
          if ( v22 < 15.0 )
          {
            this[4363] = atan2(
                           -(v35 * this[3381] + v34 * this[3378] + v33 * this[3375]),
                           -(v35 * this[3383] + v34 * this[3380] + v33 * this[3377]))
                       / this[4397];
            if ( this[4363] >= -1.0 )
            {
              if ( this[4363] > 1.0 )
                this[4363] = 1.0;
            }
            else
            {
              this[4363] = -1.0;
            }
          }
        }
        else
        {
          VehicleDynamicsStateReset(this + 3);
          AIVehiclePathPositionTracking(v42, v44);
          *((_BYTE *)this + 17908) = 0;
          if ( dword_7C56A8 == 1 )
            ConditionalGate(this + 3);
        }
      }
    }
  }
}
