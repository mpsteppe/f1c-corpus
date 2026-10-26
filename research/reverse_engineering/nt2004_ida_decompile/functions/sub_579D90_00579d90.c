int __thiscall sub_579D90(float *this, float *a2, float *a3, float a4)
{
  double v7; // st7
  __int16 v8; // fps
  double v9; // st7
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  int result; // eax
  long double v14; // st7
  long double v15; // st6
  float v16; // [esp+8h] [ebp-10h]
  float v17; // [esp+Ch] [ebp-Ch]
  float v18; // [esp+10h] [ebp-8h]
  float v19; // [esp+14h] [ebp-4h]
  int v20; // [esp+1Ch] [ebp+4h]
  int v21; // [esp+20h] [ebp+8h]

  v7 = a3[3] * a2[3] + a3[2] * a2[2] + *a2 * *a3 + a3[1] * a2[1];
  *(float *)&v21 = v7;
  if ( v7 >= 0.0 )
  {
    v16 = *a3;
    v17 = a3[1];
    v18 = a3[2];
    v19 = a3[3];
  }
  else
  {
    *(float *)&v21 = -*(float *)&v21;
    v16 = -*a3;
    v17 = -a3[1];
    v18 = -a3[2];
    v19 = -a3[3];
  }
  *(float *)&v20 = 1.0 - a4;
  v9 = 1.0 - *(float *)&v21;
  v10 = v9 < 0.02;
  v11 = 0;
  v12 = v9 == 0.02;
  result = v8 & 0x4100;
  if ( (v8 & 0x4100) == 0 )
  {
    v14 = acos(*(float *)&v21);
    v15 = 1.0 / sin(v14);
    *(float *)&v20 = sin(v14 * *(float *)&v20) * v15;
    a4 = sin(v14 * a4) * v15;
  }
  *this = *(float *)&v20 * *a2 + v16 * a4;
  this[1] = *(float *)&v20 * a2[1] + v17 * a4;
  this[2] = v18 * a4 + *(float *)&v20 * a2[2];
  this[3] = v19 * a4 + *(float *)&v20 * a2[3];
  return result;
}
