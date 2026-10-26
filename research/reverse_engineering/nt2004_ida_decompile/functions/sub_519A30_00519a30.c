float *__thiscall sub_519A30(float *this, float *a2, float *a3, float *a4, float *a5, float *a6)
{
  double v7; // st7
  double v8; // st6
  double v9; // st5
  float *v10; // eax
  float v11; // ecx
  float v12; // edx
  float *result; // eax
  double v14; // st7
  double v15; // st7
  double v16; // st6
  double v17; // st5
  float v18; // [esp+8h] [ebp-3Ch] BYREF
  float v19; // [esp+Ch] [ebp-38h]
  float v20; // [esp+10h] [ebp-34h]
  float v21; // [esp+14h] [ebp-30h] BYREF
  float v22; // [esp+18h] [ebp-2Ch]
  float v23; // [esp+1Ch] [ebp-28h]
  float v24; // [esp+20h] [ebp-24h]
  float v25; // [esp+24h] [ebp-20h]
  float v26; // [esp+28h] [ebp-1Ch]
  float v27; // [esp+2Ch] [ebp-18h] BYREF
  float v28; // [esp+30h] [ebp-14h]
  float v29; // [esp+34h] [ebp-10h]
  float v30[3]; // [esp+38h] [ebp-Ch] BYREF

  v7 = *a2 - this[4380];
  v8 = a2[1] - this[4381];
  v9 = a2[2] - this[4382];
  v18 = v9 * this[4377] + v8 * this[4374] + v7 * this[4371];
  v19 = v9 * this[4378] + v8 * this[4375] + v7 * this[4372];
  v20 = v9 * this[4379] + v8 * this[4376] + v7 * this[4373];
  v21 = this[4377] * a3[2] + this[4374] * a3[1] + *a3 * this[4371];
  v22 = this[4378] * a3[2] + this[4375] * a3[1] + this[4372] * *a3;
  v23 = this[4379] * a3[2] + this[4376] * a3[1] + this[4373] * *a3;
  v24 = v20 * this[4393] - v19 * this[4394];
  v27 = v24;
  v25 = v18 * this[4394] - v20 * this[4392];
  v28 = v25;
  v26 = v19 * this[4392] - v18 * this[4393];
  v29 = v26;
  v10 = sub_4F5370(this + 4389, &v27, v30);
  v11 = *v10;
  v12 = v10[1];
  v26 = v10[2];
  v25 = v12;
  v24 = v11;
  *a4 = v26 * v23 + v12 * v22 + v21 * v11;
  *a5 = sub_519990(this, &v18, &v21);
  result = a6;
  if ( a6 )
  {
    v14 = *a4;
    v28 = v22 * v14;
    v29 = v23 * v14;
    v15 = v24 - v21 * v14;
    v16 = v25 - v28;
    v17 = v26 - v29;
    *a6 = v17 * this[4373] + v16 * this[4372] + v15 * this[4371];
    a6[1] = v17 * this[4376] + v16 * this[4375] + v15 * this[4374];
    a6[2] = v17 * this[4379] + v16 * this[4378] + v15 * this[4377];
  }
  return result;
}
