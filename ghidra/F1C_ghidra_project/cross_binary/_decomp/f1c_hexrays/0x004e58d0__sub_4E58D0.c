// f1c  0x004e58d0  size=516
void __thiscall sub_4E58D0(float *this)
{
  double v1; // st7
  double v2; // st7
  double v3; // st6
  double v5; // st7
  unsigned __int8 v6; // c0
  unsigned __int8 v7; // c2
  double v8; // st7
  double v10; // st6
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c2
  double v13; // st6
  double v15; // st5
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c2
  double v18; // st5
  double v19; // st4
  double v20; // st6
  double v21; // rt1
  double v22; // st4
  float v23; // [esp+0h] [ebp-24h]
  float v24; // [esp+0h] [ebp-24h]
  float v25; // [esp+4h] [ebp-20h]
  float v26; // [esp+8h] [ebp-1Ch]
  float v27; // [esp+Ch] [ebp-18h]
  float v28; // [esp+10h] [ebp-14h]
  float v29; // [esp+14h] [ebp-10h]
  float v30; // [esp+20h] [ebp-4h]

  v1 = this[3397] * -9.81;
  v27 = v1 * this[3375] + this[3378] * 0.0 + this[3372] * 0.0;
  v28 = v1 * this[3376] + this[3379] * 0.0 + this[3373] * 0.0;
  v29 = v1 * this[3377] + this[3380] * 0.0 + this[3374] * 0.0;
  v30 = this[3380] * this[3736] + this[3377] * this[3735] + this[3374] * this[3734];
  v23 = this[3390] - (this[3378] * this[3736] + this[3375] * this[3735] + this[3734] * this[3372]);
  v2 = this[3391] - (this[3379] * this[3736] + this[3376] * this[3735] + this[3373] * this[3734]);
  v3 = this[3392] - v30;
  v24 = v23 * v23;
  v25 = v2 * v2;
  v26 = v3 * v3;
  v5 = v24 * this[3737];
  if ( v6 | v7 )
    v8 = v5 + v27;
  else
    v8 = v27 - v5;
  v10 = v25 * this[3738];
  if ( v11 | v12 )
    v13 = v10 + v28;
  else
    v13 = v28 - v10;
  v15 = v26 * this[3739];
  if ( v16 | v17 )
  {
    v18 = v15 + v29;
    v19 = v13;
    v20 = v26 * this[3740];
    v21 = v19 - v20;
    v22 = v20;
    v13 = v21;
    this[3414] = v22 * this[3741] + this[3414];
  }
  else
  {
    v18 = v29 - v15;
  }
  this[3411] = v8 + this[3411];
  this[3412] = v13 + this[3412];
  this[3413] = v18 + this[3413];
}
