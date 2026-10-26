char __thiscall sub_4B6360(_DWORD *this, _DWORD *a2, int a3, _DWORD *a4)
{
  _DWORD *v4; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // ebp
  int v10; // esi
  char v11; // bl
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  float v18; // [esp+0h] [ebp-234h]
  float v19; // [esp+0h] [ebp-234h]
  float v20; // [esp+0h] [ebp-234h]
  float v21; // [esp+18h] [ebp-21Ch]
  float v22; // [esp+18h] [ebp-21Ch]
  float v23; // [esp+18h] [ebp-21Ch]
  float v24; // [esp+18h] [ebp-21Ch]
  float v25; // [esp+1Ch] [ebp-218h] BYREF
  float v26; // [esp+20h] [ebp-214h]
  float v27; // [esp+24h] [ebp-210h]
  float v28; // [esp+28h] [ebp-20Ch] BYREF
  float v29; // [esp+2Ch] [ebp-208h]
  float v30; // [esp+30h] [ebp-204h]
  float v31; // [esp+34h] [ebp-200h] BYREF
  float v32; // [esp+38h] [ebp-1FCh]
  float v33; // [esp+3Ch] [ebp-1F8h]
  float v34; // [esp+40h] [ebp-1F4h] BYREF
  float v35; // [esp+44h] [ebp-1F0h]
  float v36; // [esp+48h] [ebp-1ECh]
  int v37; // [esp+4Ch] [ebp-1E8h]
  float v38; // [esp+50h] [ebp-1E4h]
  float v39[3]; // [esp+54h] [ebp-1E0h] BYREF
  float v40[3]; // [esp+60h] [ebp-1D4h] BYREF
  float v41[3]; // [esp+6Ch] [ebp-1C8h] BYREF
  float v42[3]; // [esp+78h] [ebp-1BCh] BYREF
  int v43; // [esp+84h] [ebp-1B0h] BYREF
  _DWORD v44[106]; // [esp+8Ch] [ebp-1A8h] BYREF

  v4 = a2;
  if ( *a2 >> 29 != 1 )
    return 0;
  if ( (*a2 & 0xFC0000) != 0 )
    return 0;
  v7 = this[619];
  if ( v7 >= 3 && v7 <= 4 )
  {
    v8 = 0;
    while ( 1 )
    {
      v9 = BitTest(a4 + 2, v8);
      if ( BitTest(a2 + 2, v8) != v9 )
        return 0;
      if ( ++v8 >= 14 )
      {
        v4 = a2;
        break;
      }
    }
  }
  ArithmeticComparison_3a90(this + 734, v4);
  ArithmeticComparison_3a90(this + 626, a4);
  ArithmeticComparison_2420(this + 736, v42, &v34);
  ArithmeticComparison_2420(this + 628, v39, &v31);
  AudioSamplePlaybackWithPitchModulationAndStereoP(*(float *)(a3 + 4), (int)&v43);
  ArithmeticComparison_2420((_DWORD *)(a3 + 8), v41, &v28);
  ArithmeticComparison_2420(v44, v40, &v25);
  v10 = 0;
  v37 = 0;
  do
  {
    v11 = 1;
    if ( v10 )
    {
      if ( v31 <= (double)v34 )
        v12 = v34 - v31;
      else
        v12 = v31 - v34;
      v22 = v12;
      if ( v12 > 3.141592653589793 )
        v22 = v22 - (v22 - 3.141592653589793);
      if ( v28 <= (double)v25 )
        v13 = v25 - v28;
      else
        v13 = v28 - v25;
      if ( v13 > 3.141592653589793 )
        v13 = v13 - (v13 - 3.141592653589793);
      v18 = v13;
      if ( !(unsigned __int8)SteeringAlignmentToleranceCheck(v18, v22) )
        return 0;
      if ( v32 <= (double)v35 )
        v14 = v35 - v32;
      else
        v14 = v32 - v35;
      v23 = v14;
      if ( v14 > 3.141592653589793 )
        v23 = v23 - (v23 - 3.141592653589793);
      if ( v29 <= (double)v26 )
        v15 = v26 - v29;
      else
        v15 = v29 - v26;
      if ( v15 > 3.141592653589793 )
        v15 = v15 - (v15 - 3.141592653589793);
      v19 = v15;
      if ( !(unsigned __int8)SteeringAlignmentToleranceCheck(v19, v23) )
        return 0;
      if ( v33 <= (double)v36 )
        v16 = v36 - v33;
      else
        v16 = v33 - v36;
      v24 = v16;
      if ( v16 > 3.141592653589793 )
        v24 = v24 - (v24 - 3.141592653589793);
      if ( v30 <= (double)v27 )
        v17 = v27 - v30;
      else
        v17 = v30 - v27;
      if ( v17 > 3.141592653589793 )
        v17 = v17 - (v17 - 3.141592653589793);
      v20 = v17;
      if ( !(unsigned __int8)SteeringAlignmentToleranceCheck(v20, v24) )
        return 0;
    }
    else
    {
      do
      {
        v38 = v39[v10] - v42[v10];
        v21 = v40[v10] - v41[v10];
        if ( v10 == 1 )
          v21 = v21 + v21;
        if ( !(unsigned __int8)LapSpeedComparisonWithSwitchSelectableThresholds(v21, v38) )
          break;
        if ( v10 == 2 )
          v11 = 0;
        ++v10;
      }
      while ( v10 < 3 );
      if ( v11 )
        return 0;
      v10 = v37;
    }
    v37 = ++v10;
  }
  while ( v10 < 2 );
  return 1;
}
