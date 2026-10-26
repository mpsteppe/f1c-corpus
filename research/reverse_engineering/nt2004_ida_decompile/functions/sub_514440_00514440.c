double __thiscall sub_514440(float *this, float a2, float a3, float a4)
{
  double v4; // st7
  double X; // st7
  int v7; // eax
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v13; // st7
  long double v14; // st5
  float v15; // [esp+Ch] [ebp-14h]
  float v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+10h] [ebp-10h]
  float v18; // [esp+14h] [ebp-Ch]
  float v19; // [esp+1Ch] [ebp-4h]

  v4 = a2 * a2;
  v19 = v4;
  v15 = v4;
  X = (v4 * this[4739] - (v15 * 0.0 - 9.8100004) * this[4396]) * this[4841];
  v18 = X;
  v16 = floor(X);
  v7 = (int)v16;
  v17 = v7;
  if ( v7 >= 0 )
  {
    if ( v7 >= 14 )
    {
      v7 = 13;
      v17 = 13;
    }
    v9 = this[v7 + 4842];
    v8 = v9 + (this[v7 + 4843] - v9) * (v18 - (double)v17);
  }
  else
  {
    v8 = this[4842];
  }
  v10 = v8 * this[4397];
  if ( v10 > this[4921] )
    v10 = this[4921];
  v11 = v10 + this[4923] * this[4397] * v15;
  if ( v11 > 0.0 )
  {
    v13 = v11 * a4;
    v14 = v19 - -a3 * (-0.5 * v13) * 4.0;
    if ( v14 > 0.0 )
      return a2 - v13 * ((sqrt(v14) - a2) / (-0.5 * v13 + -0.5 * v13));
    else
      return 0.0;
  }
  else if ( a2 >= 1.0 )
  {
    return a2;
  }
  else
  {
    return 0.0;
  }
}
