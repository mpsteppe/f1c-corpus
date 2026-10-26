double __thiscall sub_5149B0(float *this, float a2, float a3, float *a4, float a5)
{
  double v5; // st7
  double v9; // st7
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c2
  double X; // st7
  int v13; // eax
  double v14; // st7
  double v15; // st7
  double v16; // st6
  double v17; // st7
  int v18; // eax
  long double v19; // st6
  double v20; // st7
  int v21; // eax
  double v22; // st7
  double v23; // st7
  float v25; // [esp+10h] [ebp-8h]
  float v26; // [esp+14h] [ebp-4h]
  float v27; // [esp+1Ch] [ebp+4h]
  float v28; // [esp+20h] [ebp+8h]
  float v29; // [esp+20h] [ebp+8h]
  int v30; // [esp+20h] [ebp+8h]
  float v31; // [esp+24h] [ebp+Ch]
  int v32; // [esp+24h] [ebp+Ch]
  float v33; // [esp+24h] [ebp+Ch]
  int v34; // [esp+24h] [ebp+Ch]
  float v35; // [esp+28h] [ebp+10h]

  v5 = a2 * a2;
  v27 = v5;
  v28 = v5 * this[4739] - (v27 * a3 + a4[1]) * this[4396];
  v25 = fabs(v27 * a5 - *a4) * this[4396];
  v9 = v28;
  if ( v10 | v11 )
  {
    X = v9 * this[4857];
    v35 = X;
    v31 = floor(X);
    v13 = (int)v31;
    v32 = v13;
    if ( v13 < 0 )
    {
      v14 = this[4858];
      goto LABEL_13;
    }
    if ( v13 >= 14 )
    {
      v13 = 13;
      v32 = 13;
    }
    v15 = this[v13 + 4858];
    v16 = this[v13 + 4859];
  }
  else
  {
    v17 = v9 * this[4873];
    v35 = v17;
    v33 = floor(v17);
    v18 = (int)v33;
    v32 = v18;
    if ( v18 < 0 )
    {
      v14 = this[4874];
      goto LABEL_13;
    }
    if ( v18 >= 14 )
    {
      v18 = 13;
      v32 = 13;
    }
    v15 = this[v18 + 4874];
    v16 = this[v18 + 4875];
  }
  v14 = v15 + (v16 - v15) * (v35 - (double)v32);
LABEL_13:
  v19 = v14 * v14 - v25 * v25;
  if ( v19 <= 0.0 )
  {
    v22 = 0.0;
  }
  else
  {
    v26 = sqrt(v19) / v14;
    v20 = v28 * this[4841];
    *(float *)&v34 = v20;
    v29 = floor(v20);
    v21 = (int)v29;
    v30 = v21;
    if ( v21 >= 0 )
    {
      if ( v21 >= 14 )
      {
        v21 = 13;
        v30 = 13;
      }
      v23 = this[v21 + 4842];
      v22 = (v23 + (this[v21 + 4843] - v23) * (*(float *)&v34 - (double)v30)) * this[4397] * v26;
    }
    else
    {
      v22 = this[4842] * this[4397] * v26;
    }
  }
  if ( v22 > this[4921] )
    v22 = this[4921];
  return v22 + this[4923] * this[4397] * v27 + a4[2];
}
