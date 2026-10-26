double __thiscall sub_430A50(int this, double a2)
{
  int v4; // eax
  int v5; // ecx
  unsigned int v6; // edx
  double v7; // st7
  int v8; // edx
  unsigned int v9; // ecx
  unsigned int v10; // edx
  double v11; // st7
  double v12; // st6
  double v13; // st5
  int v14; // edi
  double v15; // st7
  double v16; // [esp+0h] [ebp-B0h]
  double v17; // [esp+0h] [ebp-B0h]
  double v18; // [esp+8h] [ebp-A8h]
  double v19; // [esp+10h] [ebp-A0h]
  double v20; // [esp+10h] [ebp-A0h]
  double v21; // [esp+20h] [ebp-90h]
  double v22; // [esp+20h] [ebp-90h]
  double v23; // [esp+28h] [ebp-88h]
  double v24; // [esp+28h] [ebp-88h]
  int v25[2]; // [esp+30h] [ebp-80h] BYREF
  double v26; // [esp+38h] [ebp-78h] BYREF
  int v27[2]; // [esp+40h] [ebp-70h] BYREF
  double v28; // [esp+48h] [ebp-68h]
  double v29; // [esp+50h] [ebp-60h] BYREF
  double i; // [esp+58h] [ebp-58h]
  double v31; // [esp+60h] [ebp-50h]
  double v32; // [esp+68h] [ebp-48h]
  double v33; // [esp+70h] [ebp-40h]
  double v34; // [esp+78h] [ebp-38h]
  int v35[2]; // [esp+80h] [ebp-30h] BYREF
  double v36; // [esp+88h] [ebp-28h]
  double v37; // [esp+90h] [ebp-20h]
  double v38; // [esp+98h] [ebp-18h]
  double v39; // [esp+A0h] [ebp-10h]
  double v40; // [esp+A8h] [ebp-8h]

  if ( !TireBrandLookup(&unk_8ADB88) )
    return 0.0;
  v4 = CompoundIndexLookup(*(_DWORD *)(this + 3012));
  if ( !v4 )
    return 0.0;
  v26 = (double)*(int *)(this + 3140) * *(double *)(this + 3128) + *(double *)(this + 3120);
  v21 = 1.0 - v26;
  if ( dword_8AEEC0 )
  {
    if ( dword_8AEEC0 == 1 )
    {
      v7 = *(double *)(v4 + 384) + *(double *)(v4 + 56);
      v25[0] = 0;
      v25[1] = 1072693248;
      v27[0] = 4;
      v28 = v7 * 0.5;
      v23 = 0.5
          / (v21 * 0.8200000000000001 + v26 * 1.18)
          * (v26 * *(double *)(v4 + 360) * 1.18 + v21 * *(double *)(v4 + 32) * 0.8200000000000001);
      QuaternionTransformComputation(
        (*(double *)(v4 + 432) + *(double *)(v4 + 104)) * 0.5,
        (*(double *)(v4 + 440) + *(double *)(v4 + 112)) * 0.5,
        (*(double *)(v4 + 448) + *(double *)(v4 + 120)) * 0.5);
      v21 = 1.0;
    }
    else
    {
      if ( dword_8AEEC0 != 2 )
        return 0.0;
      v5 = *(_DWORD *)(v4 + 60);
      LODWORD(v28) = *(_DWORD *)(v4 + 56);
      v6 = *(_DWORD *)(v4 + 32);
      HIDWORD(v28) = v5;
      *(double *)v25 = v21 * 0.8200000000000001;
      v23 = COERCE_DOUBLE(__PAIR64__(*(_DWORD *)(v4 + 36), v6));
      v19 = *(double *)(v4 + 120);
      v18 = *(double *)(v4 + 112);
      v16 = *(double *)(v4 + 104);
      v27[0] = 2;
      QuaternionTransformComputation(v16, v18, v19);
    }
  }
  else
  {
    v8 = *(_DWORD *)(v4 + 364);
    LODWORD(v23) = *(_DWORD *)(v4 + 360);
    HIDWORD(v20) = *(_DWORD *)(v4 + 452);
    v28 = *(double *)(v4 + 384) * 0.98;
    v9 = *(_DWORD *)(v4 + 444);
    HIDWORD(v23) = v8;
    LODWORD(v20) = *(_DWORD *)(v4 + 448);
    v10 = *(_DWORD *)(v4 + 440);
    *(double *)v25 = v26 * 1.18;
    v17 = *(double *)(v4 + 432);
    v27[0] = 2;
    QuaternionTransformComputation(v17, COERCE_DOUBLE(__PAIR64__(v9, v10)), v20);
    v21 = v26;
  }
  v28 = v28 * 0.98;
  if ( v28 <= 0.0 )
    return 0.0;
  WheelForceAggregate(this, (int)&dword_8ADB00, (float *)&v26, (float *)&v29);
  v33 = ((double)*(int *)(this + 3268) * *(double *)(this + 3256) + *(double *)(this + 3248)) * 0.75 + dbl_8ADB40;
  v11 = (double)v27[0];
  v12 = (v33 * *(double *)v25 * 9.81 - *(float *)&v29 * v21 * a2 * a2) / v11;
  if ( v12 <= v40 )
    v13 = v12;
  else
    v13 = v40;
  v29 = 0.0;
  v14 = 44;
  v32 = (((v36 * v13 + v37) * v13 + v38) * v13 + v39) * v12 * v11 * v23;
  do
  {
    if ( !*(_BYTE *)((v14 << 6) + this + 3020) )
      break;
    v31 = SessionStateIndexedLookup((int *)this, v14);
    if ( v31 <= 0.0 )
      return 0.0;
    v34 = 1.0 / v28;
    v22 = v34 * v31 * a2;
    i = (double)*(int *)(this + 5508) * *(double *)(this + 5496) + *(double *)(this + 5488);
    if ( v22 <= i )
    {
      ParameterizedCurveInterpolation(v22, (int)v35, (int)v25);
      if ( v14 == 44 )
      {
        v24 = v22;
        for ( i = (i - v22) * 0.04; v24 <= dbl_8AE194; v24 = v24 + i )
        {
          ParameterizedCurveInterpolation(v24, (int)v35, (int)v27);
          if ( *(double *)v25 < *(double *)v27 )
          {
            v25[0] = v27[0];
            v25[1] = v27[1];
          }
        }
      }
      v15 = v34 * *(double *)v25 * v31;
      if ( v15 > v32 )
        v15 = v32;
      if ( v29 < v15 )
        v29 = v15;
    }
    ++v14;
  }
  while ( v14 <= 50 );
  return (v29 - *(float *)&v26 * a2 * a2) / v33;
}

