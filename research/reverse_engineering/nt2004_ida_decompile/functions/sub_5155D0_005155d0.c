double __thiscall sub_5155D0(float *this, float *a2)
{
  double v3; // st7
  double v4; // st7
  double v5; // st6
  int v6; // edi
  float *v7; // ebx
  double v8; // st5
  double result; // st7
  float v10; // [esp+4h] [ebp-2Ch]
  float v11; // [esp+4h] [ebp-2Ch]
  float v12; // [esp+8h] [ebp-28h]
  float v13; // [esp+8h] [ebp-28h]
  float v14; // [esp+Ch] [ebp-24h]
  float v15; // [esp+Ch] [ebp-24h]
  float v16[3]; // [esp+10h] [ebp-20h] BYREF
  float v17; // [esp+1Ch] [ebp-14h]
  float v18; // [esp+20h] [ebp-10h]
  float v19; // [esp+24h] [ebp-Ch]

  v14 = this[4801];
  v10 = this[4799];
  v12 = this[4800];
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
  v4 = v3 - this[4380];
  v5 = v12 - this[4381];
  v6 = 0;
  v7 = this + 4758;
  v8 = v14 - this[4382];
  v11 = v8 * this[4377] + v5 * this[4374] + v4 * this[4371];
  v13 = v8 * this[4378] + v5 * this[4375] + v4 * this[4372];
  v15 = v8 * this[4379] + v5 * this[4376] + v4 * this[4373];
  v16[0] = v11 - this[470] + this[4802];
  v16[1] = v13 - this[471] + this[4803];
  v16[2] = v15 - this[472] + this[4804];
  do
  {
    v17 = *(v7 - 1) - this[470];
    v18 = *v7 - this[471];
    v19 = v7[1] - this[472];
    if ( v6 != 8 )
    {
      v17 = v17 + this[4802];
      v18 = v18 + this[4803];
      v19 = v19 + this[4804];
    }
    sub_5A11B0(v16, v6++);
    v7 += 3;
  }
  while ( v6 < 13 );
  result = sqrt(v15 * v15 + v13 * v13 + v11 * v11);
  if ( this[4805] > result )
    return this[4805];
  return result;
}
