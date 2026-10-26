void __thiscall sub_510C10(float *this)
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
  double v23; // st7
  float v24; // [esp+0h] [ebp-24h]
  float v25; // [esp+0h] [ebp-24h]
  float v26; // [esp+4h] [ebp-20h]
  float v27; // [esp+4h] [ebp-20h]
  float v28; // [esp+8h] [ebp-1Ch]
  float v29; // [esp+8h] [ebp-1Ch]
  float v30; // [esp+Ch] [ebp-18h]
  float v31; // [esp+10h] [ebp-14h]
  float v32; // [esp+14h] [ebp-10h]
  float v33; // [esp+20h] [ebp-4h]

  v1 = this[4396] * -9.81;
  v30 = v1 * this[4374] + this[4377] * 0.0 + this[4371] * 0.0;
  v31 = v1 * this[4375] + this[4378] * 0.0 + this[4372] * 0.0;
  v32 = v1 * this[4376] + this[4379] * 0.0 + this[4373] * 0.0;
  v33 = this[4373] * this[4733] + this[4379] * this[4735] + this[4376] * this[4734];
  v24 = this[4389] - (this[4377] * this[4735] + this[4374] * this[4734] + this[4733] * this[4371]);
  v2 = this[4390] - (this[4372] * this[4733] + this[4378] * this[4735] + this[4375] * this[4734]);
  v3 = this[4391] - v33;
  v25 = v24 * v24;
  v26 = v2 * v2;
  v28 = v3 * v3;
  v5 = v25 * this[4736];
  if ( v6 | v7 )
    v8 = v5 + v30;
  else
    v8 = v30 - v5;
  v10 = v26 * this[4737];
  if ( v11 | v12 )
    v13 = v10 + v31;
  else
    v13 = v31 - v10;
  v15 = v28 * this[4738];
  if ( v16 | v17 )
  {
    v18 = v15 + v32;
    v19 = v13;
    v20 = v28 * this[4739];
    v21 = v19 - v20;
    v22 = v20;
    v13 = v21;
    this[4413] = v22 * this[4740] + this[4413];
  }
  else
  {
    v18 = v32 - v15;
  }
  this[4410] = v8 + this[4410];
  this[4411] = v13 + this[4411];
  this[4412] = v18 + this[4412];
  if ( this[5187] != 0.0 )
  {
    v23 = this[4419] * this[5187] * -64.0;
    v27 = this[4390] * v23;
    v29 = this[4391] * v23;
    this[4410] = this[4389] * v23 + this[4410];
    this[4411] = v27 + this[4411];
    this[4412] = v29 + this[4412];
  }
}
