void __thiscall sub_443B70(int this, int a2, int a3)
{
  int v4; // ecx
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  double v8; // st7
  int v9; // edx
  unsigned int v10; // eax
  double v11; // st7
  unsigned __int8 v13; // c0
  unsigned __int8 v14; // c3
  double v15; // st7
  double v16; // st7
  double v17; // st6
  double v18; // st7
  double v19; // st7
  int v20; // eax
  int v21; // ecx
  int v22; // ecx
  double v23; // st7
  double v24; // st5
  unsigned int v25; // eax
  long double v26; // st5
  long double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st6
  int v32; // ecx
  double v33; // st7
  double v34; // st7
  double v35; // st6
  double v36; // st7
  double v37; // st7
  double v38; // st5
  double v39; // [esp+8h] [ebp-8h]
  double v40; // [esp+8h] [ebp-8h]
  double v41; // [esp+8h] [ebp-8h]
  int v42; // [esp+8h] [ebp-8h]

  v4 = *(_DWORD *)(this + 7928);
  v5 = 0;
  *(_DWORD *)(this + 24) = 0;
  *(_DWORD *)(this + 28) = 0;
  if ( !v4 )
    goto LABEL_21;
  v6 = *(_DWORD *)(this + 7700);
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( v7 )
    {
      if ( v7 == 1 )
        v8 = (*(double *)(this + 1964) + *(double *)(this + 840)) * -0.5;
      else
        v8 = v39;
    }
    else
    {
      v8 = (*(double *)(this + 4212) + *(double *)(this + 3088) + *(double *)(this + 1964) + *(double *)(this + 840))
         * -0.25;
    }
  }
  else
  {
    v8 = (*(double *)(this + 4212) + *(double *)(this + 3088)) * -0.5;
  }
  v9 = *(_DWORD *)(this + 7924);
  v10 = v9 == -1 ? 0 : v9;
  if ( v10 > 7 )
  {
    v4 = dword_5C7530;
    v37 = v8 * *(double *)(dword_5C7530 + 8 * v10);
  }
  else
  {
    v37 = v8 * *(double *)(this + 8 * v10 + 7856);
  }
  v40 = v37;
  v11 = *(double *)(this + 7804) - *(double *)(this + 104);
  *(double *)(this + 7804) = v11;
  if ( v13 | v14 )
    *(_DWORD *)(this + 7920) = v9;
  if ( *(double *)(this + 7260) != v40 )
  {
    if ( *(_BYTE *)(this + 7800) )
    {
      v17 = *(double *)(this + 7260);
      if ( v4 <= 0 )
      {
        if ( v17 < v40 )
        {
          *(_DWORD *)(this + 8) = 0;
          *(_DWORD *)(this + 12) = 1072693248;
        }
        if ( v11 >= 0.0 )
          goto LABEL_15;
        if ( v11 > *(double *)(this + 7836) )
        {
          *(double *)(this + 24) = 1.0 - v11 / *(double *)(this + 7836);
          goto LABEL_15;
        }
      }
      else
      {
        if ( v17 > v40 )
        {
          *(_DWORD *)(this + 8) = 0;
          *(_DWORD *)(this + 12) = 0;
        }
        if ( v11 >= 0.0 )
          goto LABEL_15;
        if ( v11 > *(double *)(this + 7820) )
        {
          *(double *)(this + 24) = 1.0 - v11 / *(double *)(this + 7820);
          goto LABEL_15;
        }
      }
      if ( *(double *)(this + 7736) == v40 )
        *(_DWORD *)(this + 7928) = 0;
      goto LABEL_15;
    }
    if ( !a3 )
      goto LABEL_15;
    if ( v4 <= 0 )
    {
      if ( (a2 == 2 || a2 == 3 || (*(_BYTE *)(this + 128) & 2) != 0) && *(double *)(this + 7260) < v40 )
      {
        *(_DWORD *)(this + 8) = 0;
        *(_DWORD *)(this + 12) = 1072693248;
      }
      if ( v11 >= 0.0 )
        goto LABEL_15;
      if ( v11 <= *(double *)(this + 7836) )
        goto LABEL_14;
      v18 = v11 / *(double *)(this + 7836);
    }
    else
    {
      if ( (a2 == 1 || a2 == 3 || (*(_BYTE *)(this + 128) & 1) != 0) && *(double *)(this + 7260) > v40 )
      {
        *(_DWORD *)(this + 8) = 0;
        *(_DWORD *)(this + 12) = 0;
      }
      if ( v11 >= 0.0 )
        goto LABEL_15;
      if ( v11 <= *(double *)(this + 7820) )
        goto LABEL_14;
      v18 = v11 / *(double *)(this + 7820);
    }
    v19 = 1.0 - v18;
    if ( v19 > *(double *)(this + 32) )
      *(double *)(this + 32) = v19;
    goto LABEL_15;
  }
  *(_DWORD *)(this + 7920) = v9;
LABEL_14:
  *(_DWORD *)(this + 7928) = 0;
LABEL_15:
  if ( *(int *)(this + 7928) < 0
    && v9 >= 1
    && *(double *)(this + 16) > 0.0
    && *(double *)(this + 412) > 0.0
    && *(double *)(this + 7388) * 0.5 < *(double *)(this + 7260) )
  {
    PositionUpdateWithTelemetryRecording(*(_DWORD *)(this + 7936) + 12);
  }
LABEL_21:
  v15 = (double)(*(double *)(this + 7260) > *(double *)(this + 7396));
  if ( v15 != 0.0 || *(_BYTE *)(this + 7256) )
  {
    v41 = *(double *)(this + 8);
    if ( v15 != 0.0 )
    {
      v16 = (*(double *)(this + 7404) - *(double *)(this + 7260))
          / (*(double *)(this + 7404) - *(double *)(this + 7396));
      if ( v16 < *(double *)(this + 8) )
      {
        if ( v16 < 0.0 )
          v16 = 0.0;
        *(double *)(this + 8) = v16;
      }
    }
    if ( *(_BYTE *)(this + 7256) )
    {
      v20 = *(_DWORD *)(this + 7920);
      if ( v20 )
      {
        v21 = *(_DWORD *)(this + 7700);
        if ( v21 )
        {
          v22 = v21 - 1;
          if ( v22 )
            v23 = v22 == 1 ? (*(double *)(this + 2300) + *(double *)(this + 1176)) * 0.5 : v41;
          else
            v23 = (*(double *)(this + 4548)
                 + *(double *)(this + 3424)
                 + *(double *)(this + 2300)
                 + *(double *)(this + 1176))
                * 0.25;
        }
        else
        {
          v23 = (*(double *)(this + 4548) + *(double *)(this + 3424)) * 0.5;
        }
        v24 = *(double *)(this + 7260);
        v25 = v20 == -1 ? 0 : v20;
        if ( v25 > 7 )
        {
          v5 = dword_5C7530;
          v38 = v24 / *(double *)(dword_5C7530 + 8 * v25);
        }
        else
        {
          v38 = v24 / *(double *)(this + 8 * v25 + 7856);
        }
        v26 = fabs(v38 * v23);
        v27 = flt_8ACFB4 - v26 + flt_8ACFB4 - v26;
        if ( v27 < *(double *)(this + 8) )
        {
          if ( v27 < 0.0 )
            v27 = 0.0;
          *(long double *)(this + 8) = v27;
        }
      }
    }
    v28 = (v41 - *(double *)(this + 8)) * 0.166;
    if ( v28 > *(double *)(this + 368) )
      *(double *)(this + 368) = v28;
  }
  if ( *(double *)(this + 7260) < *(double *)(this + 7308) )
  {
    if ( *(double *)(this + 7260) <= *(double *)(this + 7300) )
      v29 = *(double *)(this + 7292);
    else
      v29 = (*(double *)(this + 7308) - *(double *)(this + 7260))
          * *(double *)(this + 7292)
          / (*(double *)(this + 7308) - *(double *)(this + 7300));
    if ( v29 > *(double *)(this + 8) )
      *(double *)(this + 8) = v29;
    if ( *(double *)(this + 7300) * 0.0078125 >= *(double *)(this + 7260)
      && *(double *)(this + 7440) <= 0.0
      && dword_7C56A8 != 2
      && byte_7CE254 == (_BYTE)v5
      && dword_7CC6E0 == v5
      && dword_7CC6E4 == 89
      && (unsigned __int8)VehicleActive(this) )
    {
      PositionLapStateUpdate(v5, 4);
      SuspensionVibration(v5);
    }
  }
  if ( *(double *)(this + 7440) > 0.0 )
  {
    v30 = *(double *)(this + 7440);
    v31 = v30 - *(double *)(this + 104);
    *(double *)(this + 7440) = v31;
    if ( v31 <= *(double *)(this + 7464)
      && v30 > *(double *)(this + 7464)
      && *(double *)(this + 7260) < *(double *)(this + 7300) )
    {
      HUDElementConfig(39, 2, 1.0, 1.0);
    }
    if ( *(double *)(this + 7440) <= 0.0 && *(double *)(this + 7260) < *(double *)(this + 7300) )
    {
      v32 = *(_DWORD *)(this + 7304);
      *(_DWORD *)(this + 7260) = *(_DWORD *)(this + 7300);
      *(_DWORD *)(this + 7264) = v32;
    }
  }
  if ( *(double *)(this + 7596) > 0.0 )
  {
    v33 = 11.5 / *(double *)(this + 7388) * dbl_8AFEA0 * *(double *)(this + 7260);
    InterruptDispatch(v33);
    v34 = fabs(v33);
    v42 = CRTFtol(v34);
    v35 = flt_8AAE74[(unsigned __int8)v42];
    v36 = (flt_8AAE74[(unsigned __int8)(v42 + 1)] - v35) * (v34 - (double)v42) + v35;
    *(double *)(this + 8) = (1.0 - v36 * *(double *)(this + 7596) * v36) * *(double *)(this + 8);
  }
  *(double *)(this + 8) = RandomPhysicsParameterGenerator(this) * *(double *)(this + 8);
}
