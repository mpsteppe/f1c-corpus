bool __thiscall sub_5509C0(float *this, int a2)
{
  double v3; // st7
  double v4; // st6
  double v5; // st7
  double v6; // st7
  double v7; // st7
  int v8; // ecx
  float v10; // [esp+4h] [ebp-54h]
  float v11; // [esp+4h] [ebp-54h]
  float v12; // [esp+8h] [ebp-50h]
  float v13; // [esp+Ch] [ebp-4Ch]
  float v14; // [esp+10h] [ebp-48h]
  char String[64]; // [esp+18h] [ebp-40h] BYREF

  v14 = flt_903B68 - 100.0;
  v10 = flt_91BDE4;
  sub_52B390();
  v13 = v14;
  v3 = v14 + 30.0;
  if ( v14 <= v3 )
  {
    if ( v14 - (v10 - 30.0) <= v14 )
      goto LABEL_6;
    v4 = v14 + v10;
  }
  else
  {
    v4 = v14 - v10;
  }
  v13 = v4;
LABEL_6:
  v12 = flt_9034E0;
  if ( flt_9034E0 > v3 )
  {
    v5 = flt_9034E0 - v10;
LABEL_10:
    v12 = v5;
    goto LABEL_11;
  }
  if ( v14 - (v10 - 30.0) > flt_9034E0 )
  {
    v5 = flt_9034E0 + v10;
    goto LABEL_10;
  }
LABEL_11:
  if ( sub_53A2B0((int)String, 64, "AIRaceTimeMid", 0)
    || (v6 = atof(String), v6 <= 0.0)
    || (v7 = v6 * this[69] * 1.25, v7 < 200.0) )
  {
    v7 = 200.0;
  }
  v11 = v10 * 0.60000002;
  if ( v7 > v11 )
    v7 = v11;
  v8 = a2;
  if ( v12 > v14 - v7 )
    v8 = a2 + 1;
  return v13 > (double)v14 && dword_9034DC >= v8;
}
