double __thiscall sub_4E9A40(float *this, float *a2)
{
  double v3; // st7
  double v4; // st7
  double v5; // st6
  int v6; // ebx
  float *v7; // edi
  double v8; // st5
  double result; // st7
  float v10; // [esp+4h] [ebp-2Ch]
  float v11; // [esp+4h] [ebp-2Ch]
  float v12; // [esp+8h] [ebp-28h]
  float v13; // [esp+8h] [ebp-28h]
  float v14; // [esp+Ch] [ebp-24h]
  float v15; // [esp+Ch] [ebp-24h]
  float v16[8]; // [esp+10h] [ebp-20h] BYREF

  v14 = this[3802];
  v10 = this[3800];
  v12 = this[3801];
  if ( a2 )
  {
    v3 = *a2 * 0.025 + v10;
    v12 = a2[1] * 0.025 + v12;
    v14 = a2[2] * 0.025 + v14;
  }
  else
  {
    v3 = v10;
  }
  v4 = v3 - this[3381];
  v5 = v12 - this[3382];
  v6 = 0;
  v7 = this + 3759;
  v8 = v14 - this[3383];
  v11 = v8 * this[3378] + v5 * this[3375] + v4 * this[3372];
  v13 = v8 * this[3379] + v5 * this[3376] + v4 * this[3373];
  v15 = v8 * this[3380] + v5 * this[3377] + v4 * this[3374];
  v16[0] = v11 - this[459];
  v16[1] = v13 - this[460];
  v16[2] = v15 - this[461];
  do
  {
    v16[3] = *(v7 - 1) - this[459];
    v16[4] = *v7 - this[460];
    v16[5] = v7[1] - this[461];
    sub_54FA00(v16, v6++);
    v7 += 3;
  }
  while ( v6 < 13 );
  result = sqrt(v15 * v15 + v13 * v13 + v11 * v11);
  if ( this[3803] > result )
    return this[3803];
  return result;
}
