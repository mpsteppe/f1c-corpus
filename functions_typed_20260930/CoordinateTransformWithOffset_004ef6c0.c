int __thiscall sub_4EF6C0(float *this, float *a2, int a3, float *a4)
{
  double v5; // st7
  double v6; // st6
  double v7; // st7
  double v8; // st6
  double v9; // st5
  double v10; // st4
  int result; // eax
  double v12; // st5
  float v13; // [esp+4h] [ebp-3Ch] BYREF
  float v14; // [esp+8h] [ebp-38h]
  float v15; // [esp+Ch] [ebp-34h]
  float v16; // [esp+18h] [ebp-28h]
  float v17[9]; // [esp+1Ch] [ebp-24h] BYREF

  EulerToRotationMatrix(a3, v17);
  RideHeightDelta(this, (int)&v13);
  v5 = v17[2] * v15 + v17[1] * v14 + v17[0] * v13;
  v6 = v17[5] * v15 + v17[4] * v14 + v17[3] * v13;
  v15 = v17[8] * v15 + v17[7] * v14 + v17[6] * v13;
  v13 = v5 + this[3381];
  v7 = v6 + this[3382];
  v8 = v15 + this[3383];
  v9 = this[3381] + *a2;
  v10 = this[3382] + a2[1];
  v16 = this[3383] + a2[2];
  v13 = v9 - v13;
  *a4 = v13;
  v14 = v10 - v7;
  result = LODWORD(v14);
  v12 = v16;
  a4[1] = v14;
  v15 = v12 - v8;
  a4[2] = v15;
  return result;
}

