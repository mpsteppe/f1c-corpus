int __thiscall sub_573B80(float *this, float *a2, float *a3)
{
  int result; // eax
  float v6; // [esp+0h] [ebp-18h]
  float v7; // [esp+4h] [ebp-14h]
  int v8; // [esp+8h] [ebp-10h]

  this[4024] = this[4024] + *a3;
  this[4025] = a3[1] + this[4025];
  this[4026] = a3[2] + this[4026];
  v6 = a3[2] * a2[1] - a2[2] * a3[1];
  v7 = a2[2] * *a3 - a3[2] * *a2;
  *(float *)&v8 = a3[1] * *a2 - *a3 * a2[1];
  result = v8;
  this[4027] = v6 + this[4027];
  this[4028] = v7 + this[4028];
  this[4029] = *(float *)&v8 + this[4029];
  return result;
}
