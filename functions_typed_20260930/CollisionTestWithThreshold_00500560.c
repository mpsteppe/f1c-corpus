char __thiscall sub_500560(int this, int a2, int a3, float *a4, float a5, char a6)
{
  char v7; // dl
  float *v8; // ecx
  double v9; // st7
  double v10; // st7
  float *v11; // edi
  char v12; // al
  char v13; // bl
  float v15; // [esp+0h] [ebp-1CCh]
  int v16[108]; // [esp+1Ch] [ebp-1B0h] BYREF

  if ( !FloatComparisonCheck((float *)this) )
    return v7;
  if ( FieldCompareConstant(v8) && (v9 = *(float *)(this + 444), v9 < *(float *)&a2) )
  {
    v10 = *(float *)&a2 - v9;
    if ( v10 >= 0.001 )
    {
      if ( v10 > 0.5 )
        v10 = 0.5;
    }
    else
    {
      v10 = 0.001;
    }
    v15 = v10 + *(float *)&a2;
    AudioParameterInterpolation(v15, this + 8, (int)v16, 1.0);
    v11 = a4;
    v12 = AudioSampleCrossFadeInterpolation((void *)this, a2, this + 440, (int)v16, (int)a4);
  }
  else
  {
    v11 = a4;
    v12 = AudioParameterInterpolation(*(float *)&a2, this + 8, (int)a4, 1.0);
  }
  v13 = v12;
  ArithmeticComparison_3a90((_DWORD *)(this + 440), v11);
  if ( v13 )
  {
    if ( a6 )
      PhysicsFloatUpdateWithCompare(v11, a5);
  }
  return v13;
}

