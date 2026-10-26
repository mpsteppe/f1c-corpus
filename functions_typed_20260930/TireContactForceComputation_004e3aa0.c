void __thiscall sub_4E3AA0(float *this, float *a2, float *a3)
{
  int v4; // eax
  double *v5; // eax
  long double v7; // st7
  double v8; // st6
  double v9; // st5
  long double v10; // st6
  long double v11; // st6
  double v12; // st6
  double v13; // st5
  double v14; // st6
  double v15; // st5
  float v16; // [esp+4h] [ebp-50h]
  float v17; // [esp+8h] [ebp-4Ch] BYREF
  float v18; // [esp+Ch] [ebp-48h]
  float v19; // [esp+10h] [ebp-44h]
  float v20; // [esp+1Ch] [ebp-38h]
  double v21[3]; // [esp+20h] [ebp-34h] BYREF
  int v22; // [esp+38h] [ebp-1Ch]
  int v23; // [esp+3Ch] [ebp-18h]
  int v24; // [esp+40h] [ebp-14h]
  int v25; // [esp+44h] [ebp-10h]
  double v26; // [esp+48h] [ebp-Ch]
  int v27; // [esp+50h] [ebp-4h]
  float v28; // [esp+58h] [ebp+4h]
  float v29; // [esp+58h] [ebp+4h]

  v4 = *((_DWORD *)this + 58);
  v21[0] = *this;
  v21[1] = this[1];
  v21[2] = this[2];
  v22 = 0x40000000;
  v23 = 1072902963;
  v24 = 0x40000000;
  v25 = 1201543096;
  v27 = v4;
  v5 = CollisionNormalFromFeature(dbl_7C9360, v21, &v17);
  *((_DWORD *)this + 58) = v5;
  if ( v5 )
  {
    v16 = (this[1] - v26 - this[57]) * v18;
  }
  else
  {
    v17 = 0.0;
    v18 = 1.0;
    v19 = 0.0;
    v16 = 9.9999999e36;
  }
  this[14] = v19 * a2[6] + v17 * *a2 + v18 * a2[3];
  this[15] = v18 * a2[4] + v17 * a2[1] + v19 * a2[7];
  this[16] = v19 * a2[8] + v18 * a2[5] + v17 * a2[2];
  v28 = this[36] - v16;
  this[29] = v28;
  if ( v28 >= 0.0 )
  {
    v7 = this[16] * this[8] + this[15] * this[7] + this[6] * this[14];
    if ( this[15] <= 0.98500001 )
    {
      v10 = fabs(v7);
      if ( v10 > this[31] )
      {
        v11 = (this[31] + this[31]) / (v10 + this[31]);
        v7 = v7 * v11;
        this[29] = v28 * v11;
      }
      this[13] = this[30] * this[29] * this[15];
      v12 = *this - v17 * v16;
      v13 = this[1] - v18 * v16;
      v20 = this[2] - v19 * v16;
      v17 = v12 - *a3;
      v14 = v13 - a3[1];
      v15 = v20 - a3[2];
      this[51] = v17 * *a2 + v14 * a2[3] + v15 * a2[6];
      this[52] = v17 * a2[1] + v15 * a2[7] + v14 * a2[4];
      v8 = v14 * a2[5] + v17 * a2[2] + v15 * a2[8];
    }
    else
    {
      v29 = v28 * this[30];
      this[13] = v29;
      v8 = this[5];
      v9 = v29 + this[24] - this[36];
      this[51] = this[3];
      this[52] = v9;
    }
    this[53] = v8;
    this[17] = this[59] * this[29] - v7 * this[60];
  }
  else
  {
    this[17] = 0.0;
    this[13] = 0.0;
  }
}

