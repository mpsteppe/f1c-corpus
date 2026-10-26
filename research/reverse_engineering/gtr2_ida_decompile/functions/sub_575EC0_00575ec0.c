double __thiscall sub_575EC0(float *this, float a2, float a3, float *a4, float a5)
{
  double v5; // st7
  double v7; // st7
  float *v8; // ecx
  float v9; // edi
  long double v10; // st7
  double v11; // st7
  long double v12; // st7
  float v14; // [esp+0h] [ebp-4h]
  float v15; // [esp+8h] [ebp+4h]
  float v16; // [esp+8h] [ebp+4h]
  float v17; // [esp+Ch] [ebp+8h]
  float v18; // [esp+Ch] [ebp+8h]

  v5 = a2 * a2;
  v14 = v5;
  v7 = v5 * this[4358];
  v8 = this + 4529;
  v15 = v7 - (v14 * a3 + a4[1]) * this[4009];
  v9 = v15;
  v10 = fabs(v14 * a5 - *a4) * this[4009];
  v17 = v10;
  if ( v10 >= 0.0 )
    v8 = this + 4545;
  v16 = sub_5738D0(v8, v15);
  v11 = v16 * v16 - v17 * v17;
  if ( v11 <= 0.0 )
  {
    v12 = 0.0;
  }
  else
  {
    v18 = v11;
    v12 = sub_5738D0(this + 4513, v9) * (sqrt(v18) / v16) * this[4010];
  }
  if ( v12 > this[4593] )
    v12 = this[4593];
  return v12 + this[4595] * this[4010] * v14 + a4[2];
}
