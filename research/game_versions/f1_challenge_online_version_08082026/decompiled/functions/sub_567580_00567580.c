void __thiscall sub_567580(float *this, float *a2, float *a3, float a4)
{
  double v7; // st7
  __int16 v8; // fps
  double v9; // st7
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  long double v13; // st6
  float v14; // [esp+8h] [ebp-10h]
  float v15; // [esp+Ch] [ebp-Ch]
  float v16; // [esp+10h] [ebp-8h]
  float v17; // [esp+14h] [ebp-4h]
  int v18; // [esp+1Ch] [ebp+4h]
  int v19; // [esp+20h] [ebp+8h]

  v7 = a3[3] * a2[3] + a3[2] * a2[2] + *a2 * *a3 + a3[1] * a2[1];
  *(float *)&v19 = v7;
  if ( v7 >= 0.0 )
  {
    v14 = *a3;
    v15 = a3[1];
    v16 = a3[2];
    v17 = a3[3];
  }
  else
  {
    *(float *)&v19 = -*(float *)&v19;
    v14 = -*a3;
    v15 = -a3[1];
    v16 = -a3[2];
    v17 = -a3[3];
  }
  *(float *)&v18 = 1.0 - a4;
  v9 = 1.0 - *(float *)&v19;
  v10 = v9 < 0.02;
  v11 = 0;
  v12 = v9 == 0.02;
  if ( (v8 & 0x4100) == 0 )
  {
    sub_5894A0();
    v13 = 1.0 / sin(*(float *)&v19);
    *(float *)&v18 = sin(*(float *)&v19 * *(float *)&v18) * v13;
    a4 = sin(*(float *)&v19 * a4) * v13;
  }
  *this = *(float *)&v18 * *a2 + v14 * a4;
  this[1] = *(float *)&v18 * a2[1] + v15 * a4;
  this[2] = v16 * a4 + *(float *)&v18 * a2[2];
  this[3] = v17 * a4 + *(float *)&v18 * a2[3];
}
