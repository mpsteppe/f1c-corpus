float *__thiscall sub_4E5470(float *this)
{
  float *v2; // edi
  float *v3; // ebx
  float *v4; // eax
  int v5; // ecx
  double v6; // st7
  double v7; // st6
  double v8; // st5
  float *v9; // edx
  long double v10; // st7
  long double v11; // st6
  float *v12; // ebp
  double v13; // st7
  float *v14; // ecx
  int v15; // edx
  double v16; // st7
  float *v17; // edi
  int v18; // ebp
  double v19; // st7
  double v20; // rtt
  double v21; // st7
  float *v22; // eax
  double v23; // st6
  int v24; // ecx
  double v25; // st5
  float *result; // eax
  int v27; // ecx
  double v28; // st7
  double v29; // st6
  double v30; // st5
  double v31; // st7
  double v32; // st5
  double v33; // st7
  float v34; // [esp+10h] [ebp-1Ch]
  int v35; // [esp+10h] [ebp-1Ch]
  float v36; // [esp+14h] [ebp-18h]
  float v37; // [esp+18h] [ebp-14h]
  float v38; // [esp+1Ch] [ebp-10h]
  float v39; // [esp+20h] [ebp-Ch]
  float v40; // [esp+20h] [ebp-Ch]
  float v41; // [esp+24h] [ebp-8h]
  float v42; // [esp+24h] [ebp-8h]
  float v43; // [esp+28h] [ebp-4h]

  v2 = this + 3381;
  v3 = this + 3372;
  v4 = this + 3426;
  v5 = 4;
  do
  {
    v6 = v4[1];
    v7 = v4[22];
    v8 = v4[3];
    *(v4 - 2) = v7 * v3[1] + v8 * v3[2] + v6 * *v3;
    *(v4 - 1) = v6 * v3[3] + v8 * v3[5] + v7 * v3[4];
    *v4 = v6 * v3[6] + v7 * v3[7] + v8 * v3[8];
    *(v4 - 2) = *v2 + *(v4 - 2);
    *(v4 - 1) = *(v4 - 1) + v2[1];
    *v4 = v2[2] + *v4;
    v39 = v8 * this[3394] - v7 * this[3395];
    v41 = v6 * this[3395] - v8 * this[3393];
    v36 = v39 + this[3390];
    v37 = v41 + this[3391];
    v38 = v7 * this[3393] - v6 * this[3394] + this[3392];
    v9 = v4 + 4;
    v4[4] = v36;
    v4[5] = v37;
    v4 += 62;
    --v5;
    v9[2] = v38;
  }
  while ( v5 );
  v10 = this[3672] * this[3421];
  this[3434] = v10;
  v11 = cos(v10);
  this[3471] = v11;
  v34 = sin(v10);
  this[3472] = v34;
  this[3496] = v10;
  this[3534] = v34;
  this[3533] = v11;
  sub_53AC70(2, 0);
  v12 = this + 3424;
  v35 = 4;
  do
  {
    sub_4E3AA0(v12, v3, v2);
    v12 += 62;
    --v35;
  }
  while ( v35 );
  sub_53AC70(1, 0);
  if ( this[3376] > 0.69999999 )
  {
    v13 = (this[3437] - this[3499] + this[3561] - this[3623]) * this[3677];
    this[3441] = v13 + this[3441];
    this[3503] = this[3503] - v13;
    this[3565] = v13 + this[3565];
    this[3627] = this[3627] - v13;
  }
  v14 = this + 3441;
  v15 = 4;
  do
  {
    if ( v14[12] < 0.0 )
    {
      if ( v14[12] <= -0.050000001 )
        goto LABEL_13;
      v16 = (v14[12] + 0.050000001) * 20.0 * *(v14 - 2);
    }
    else
    {
      v16 = *(v14 - 2);
    }
    *v14 = v16 * v14[15] + *v14;
LABEL_13:
    if ( *v14 < 0.0 )
      *v14 = *v14 * 0.5;
    v14 += 62;
    --v15;
  }
  while ( v15 );
  v17 = this + 3480;
  v18 = 4;
  do
  {
    sub_4E3D00(v17 - 56, v3);
    v19 = this[3411] + *(v17 - 2);
    v17 += 62;
    --v18;
    this[3411] = v19;
    this[3412] = this[3412] + *(v17 - 63);
    this[3413] = this[3413] + *(v17 - 62);
    v43 = *(v17 - 67) * *(v17 - 63) - *(v17 - 64) * *(v17 - 66);
    v20 = *(v17 - 64) * *(v17 - 65) - *(v17 - 62) * *(v17 - 67);
    this[3414] = *(v17 - 62) * *(v17 - 66) - *(v17 - 63) * *(v17 - 65) + this[3414];
    this[3415] = v20 + this[3415];
    this[3416] = v43 + this[3416];
  }
  while ( v18 );
  v21 = this[3412];
  v22 = this + 3458;
  v23 = this[3414];
  v24 = 4;
  v25 = this[3416];
  do
  {
    v22 += 62;
    --v24;
    *(v22 - 64) = v25 * *(v22 - 61) + v21 * *(v22 - 63) + v23 * *(v22 - 62);
  }
  while ( v24 );
  result = this + 3429;
  v27 = 4;
  do
  {
    v28 = result[12];
    result += 62;
    --v27;
    v29 = v28 * *(result - 53);
    v30 = v28;
    v31 = v28 * *(result - 52);
    v32 = v30 * *(result - 51);
    this[3411] = v29 + this[3411];
    this[3412] = v31 + this[3412];
    this[3413] = v32 + this[3413];
    v40 = v32 * *(result - 63) - v31 * *(result - 62);
    v42 = v29 * *(result - 62) - v32 * *(result - 64);
    v33 = v31 * *(result - 64) - v29 * *(result - 63);
    this[3414] = v40 + this[3414];
    this[3415] = v42 + this[3415];
    this[3416] = v33 + this[3416];
  }
  while ( v27 );
  return result;
}
