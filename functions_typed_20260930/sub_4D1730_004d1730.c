void __thiscall sub_4D1730(int this)
{
  int i; // edx
  int v3; // edx
  int j; // edi
  int v5; // ecx
  int v6; // edx
  double v7; // st7
  double v8; // st7
  int v9; // eax
  char v10; // bl
  int v11; // edi
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  unsigned int *v16; // edi
  int v17; // eax
  int k; // ebx
  int v19; // ebp
  int v20; // [esp+0h] [ebp-1Ch]
  int v21; // [esp+4h] [ebp-18h]
  float v22; // [esp+18h] [ebp-4h]
  float v23; // [esp+18h] [ebp-4h]

  for ( i = 0; i < *(_DWORD *)(this + 268); i = v3 + 1 )
    StewardZoneStateSet((_DWORD *)(*(_DWORD *)(this + 272) + 8 * i), 0);
  for ( j = 0; j < dword_5C329C; ++j )
  {
    v5 = dword_7C54F0[j];
    if ( *(_DWORD *)(v5 + 16484) != 2 )
    {
      v6 = *(_DWORD *)(v5 + 15016);
      if ( *(_DWORD *)(v6 + 300) )
      {
        if ( *(_BYTE *)(v5 + 13388) )
          v7 = -1.0;
        else
          v7 = *(float *)(this + 212) * 0.5;
      }
      else
      {
        v7 = *(float *)(v6 + 140) - 60.0;
        v22 = *(float *)(v6 + 140) * 0.22499999;
        if ( v7 <= v22 )
          v7 = v22;
      }
      if ( dword_7C56A4 == 7 && dword_7C56A8 == 5 && dbl_8AFEA0 < *(float *)(this + 176) + 20.0 )
      {
        v23 = (dbl_8AFEA0 - *(float *)(this + 176)) * 6.0 - 10.0;
        if ( v7 > v23 )
          v7 = v23;
      }
      if ( *(float *)(v6 + 172) * *(float *)(v5 + 13568)
         + *(float *)(v6 + 168) * *(float *)(v5 + 13564)
         + *(float *)(v6 + 164) * *(float *)(v5 + 13560) < v7 )
      {
        v8 = DistanceProjectionCalc(v5 + 12);
        v9 = CRTFtol(v8 * *(float *)(this + 264)) - 1;
        if ( v9 < 0 )
          v9 += *(_DWORD *)(this + 268);
        if ( v9 >= 0 )
        {
          if ( v9 > *(_DWORD *)(this + 268) - 1 )
            v9 = *(_DWORD *)(this + 268) - 1;
        }
        else
        {
          v9 = 0;
        }
        StewardZoneStateSet((_DWORD *)(*(_DWORD *)(this + 272) + 8 * v9), 2);
      }
    }
  }
  v10 = 0;
  v11 = 0;
  if ( *(int *)(this + 268) > 0 )
  {
    do
    {
      v12 = *(_DWORD *)(this + 272);
      v13 = *(_DWORD *)(v12 + 8 * v11);
      v14 = v12 + 8 * v11;
      v15 = *(_DWORD *)(*(_DWORD *)(this + 276) + 4 * v11);
      if ( v15 != v13 )
      {
        PitSelectionStateMachine(dword_5EB978, v13, v15, *(float *)(v14 + 4), 0, 0);
        *(_DWORD *)(*(_DWORD *)(this + 276) + 4 * v11) = *(_DWORD *)(*(_DWORD *)(this + 272) + 8 * v11);
        v10 = 1;
      }
      ++v11;
    }
    while ( v11 < *(_DWORD *)(this + 268) );
    if ( v10 )
      goto LABEL_31;
  }
  if ( dbl_8AFEA0 - *(float *)(this + 280) > 5.0 )
  {
LABEL_31:
    *(float *)(this + 280) = dbl_8AFEA0;
    v16 = (unsigned int *)dword_8AAE64;
    if ( dword_83EE60 < 1023 )
    {
      ++dword_83EE60;
      dword_8AAE64 += 432;
    }
    *(float *)&v21 = dbl_8AFEA0;
    ProgressBarEventEncode(v16, 4, 10, 0, 255, v21, 0);
    v17 = 0;
    for ( k = 0; k < *(_DWORD *)(this + 268); ++k )
    {
      v19 = *(_DWORD *)(*(_DWORD *)(this + 272) + 8 * k);
      if ( v19 )
      {
        if ( v17 >= 16 )
        {
          v16 = (unsigned int *)dword_8AAE64;
          if ( dword_83EE60 < 1023 )
          {
            ++dword_83EE60;
            dword_8AAE64 += 432;
          }
          *(float *)&v20 = dbl_8AFEA0;
          ProgressBarEventEncode(v16, 4, 11, 0, 255, v20, 0);
          v17 = 0;
        }
        *((_WORD *)v16 + v17++ + 4) = v19 + ((_WORD)k << 6);
        *v16 = (v17 << 9) | *v16 & 0xFFFC00FF;
      }
    }
  }
}

