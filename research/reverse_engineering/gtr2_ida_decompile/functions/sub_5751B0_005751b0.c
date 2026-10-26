int __thiscall sub_5751B0(float *this)
{
  float *v2; // ebp
  float *v3; // ebx
  float *v4; // edi
  float v5; // edx
  float v6; // eax
  double v7; // st7
  long double v8; // st7
  long double v9; // st6
  char *v10; // edi
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  float *v16; // ebp
  int v17; // edi
  double v18; // st7
  float *v19; // edi
  double v20; // st6
  int v21; // ebx
  double v22; // st5
  double v23; // st7
  int result; // eax
  int v25; // [esp+10h] [ebp-1Ch]
  float v26; // [esp+10h] [ebp-1Ch]
  int v27; // [esp+10h] [ebp-1Ch]
  float v28; // [esp+14h] [ebp-18h] BYREF
  float v29; // [esp+18h] [ebp-14h]
  float v30; // [esp+1Ch] [ebp-10h]
  float v31[3]; // [esp+20h] [ebp-Ch] BYREF

  v2 = this + 3993;
  v3 = this + 3984;
  v4 = this + 4039;
  v25 = 4;
  do
  {
    v5 = v4[3];
    v6 = v4[1];
    v29 = v4[22];
    v7 = v29 * v3[1];
    v30 = v5;
    v28 = v6;
    *(v4 - 2) = v7 + v5 * v3[2] + v6 * *v3;
    *(v4 - 1) = v28 * v3[3] + v29 * v3[4] + v30 * v3[5];
    *v4 = v28 * v3[6] + v29 * v3[7] + v30 * v3[8];
    *(v4 - 2) = *v2 + *(v4 - 2);
    *(v4 - 1) = v2[1] + *(v4 - 1);
    *v4 = v2[2] + *v4;
    sub_573AD0(this, &v28, v4 + 4);
    v4 += 63;
    --v25;
  }
  while ( v25 );
  v8 = this[4289] * this[4034];
  this[4047] = v8;
  v26 = cos(v8);
  this[4085] = v26;
  this[4148] = v26;
  v9 = sin(v8);
  this[4086] = v9;
  this[4110] = v8;
  this[4149] = v9;
  sub_5D7710(2, 0);
  v10 = (char *)(this + 4037);
  v27 = 4;
  do
  {
    sub_573C60(v10, v3, v2);
    v10 += 252;
    --v27;
  }
  while ( v27 );
  sub_5D7710(1, 0);
  if ( this[3988] > 0.69999999 )
  {
    v11 = (this[4050] - this[4113] + this[4176] - this[4239]) * this[4294];
    this[4054] = v11 + this[4054];
    this[4117] = this[4117] - v11;
    this[4180] = v11 + this[4180];
    this[4243] = this[4243] - v11;
  }
  if ( this[4066] < 0.0 )
  {
    if ( this[4066] <= -0.050000001 )
      goto LABEL_12;
    v12 = (this[4066] + 0.050000001) * 20.0 * this[4069];
  }
  else
  {
    v12 = this[4069];
  }
  this[4054] = v12 * this[4052] + this[4054];
LABEL_12:
  if ( this[4054] < 0.0 )
    this[4054] = this[4054] * 0.5;
  if ( this[4129] < 0.0 )
  {
    if ( this[4129] <= -0.050000001 )
      goto LABEL_19;
    v13 = (this[4129] + 0.050000001) * 20.0 * this[4132];
  }
  else
  {
    v13 = this[4132];
  }
  this[4117] = v13 * this[4115] + this[4117];
LABEL_19:
  if ( this[4117] < 0.0 )
    this[4117] = this[4117] * 0.5;
  if ( this[4192] < 0.0 )
  {
    if ( this[4192] <= -0.050000001 )
      goto LABEL_26;
    v14 = (this[4192] + 0.050000001) * 20.0 * this[4195];
  }
  else
  {
    v14 = this[4195];
  }
  this[4180] = v14 * this[4178] + this[4180];
LABEL_26:
  if ( this[4180] < 0.0 )
    this[4180] = this[4180] * 0.5;
  if ( this[4255] < 0.0 )
  {
    if ( this[4255] <= -0.050000001 )
      goto LABEL_33;
    v15 = (this[4255] + 0.050000001) * 20.0 * this[4258];
  }
  else
  {
    v15 = this[4258];
  }
  this[4243] = v15 * this[4241] + this[4243];
LABEL_33:
  if ( this[4243] < 0.0 )
    this[4243] = this[4243] * 0.5;
  v16 = this + 4092;
  v17 = 4;
  do
  {
    sub_573E90(v16 - 55, v3);
    sub_573B80(this, v16 - 3, v16);
    v16 += 63;
    --v17;
  }
  while ( v17 );
  v18 = this[4025];
  v19 = this + 4053;
  v20 = this[4027];
  v21 = 4;
  v22 = this[4029];
  this[4069] = v22 * this[4072] + v20 * this[4071] + v18 * this[4070];
  this[4132] = v22 * this[4135] + v20 * this[4134] + v18 * this[4133];
  this[4195] = v22 * this[4198] + v20 * this[4197] + v18 * this[4196];
  this[4258] = v22 * this[4261] + v20 * this[4260] + v18 * this[4259];
  do
  {
    v23 = v19[1];
    v28 = v23 * *(v19 - 2);
    v31[0] = v28;
    v29 = v23 * *(v19 - 1);
    v31[1] = v29;
    v30 = v23 * *v19;
    v31[2] = v30;
    result = sub_573B80(this, v19 - 13, v31);
    v19 += 63;
    --v21;
  }
  while ( v21 );
  return result;
}
