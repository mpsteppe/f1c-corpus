int __thiscall sub_5BE470(float *this)
{
  float v2; // eax
  double v3; // st7
  float v4; // ecx
  double v5; // st6
  double v6; // st6
  double v7; // st5
  double v8; // st4
  float v9; // edx
  int result; // eax
  double v11; // st7
  float v12; // [esp+8h] [ebp-4Ch]
  float v13; // [esp+Ch] [ebp-48h]
  float v14; // [esp+10h] [ebp-44h]
  float v15[16]; // [esp+14h] [ebp-40h] BYREF

  v2 = this[3];
  v3 = this[4] * this[9];
  v4 = this[7];
  v5 = this[8];
  v15[3] = v2;
  v6 = v5 * this[6];
  v7 = this[10] * this[5];
  v14 = this[8] * this[5];
  v13 = this[10] * this[4];
  v8 = this[9] * this[6];
  v12 = 1.0 / (v7 * *this + v3 * this[2] + v6 * this[1] - v14 * this[2] - v13 * this[1] - v8 * *this);
  v15[0] = (v7 - v8) * v12;
  v15[1] = (this[2] * this[9] - this[10] * this[1]) * v12;
  v15[2] = (this[1] * this[6] - this[2] * this[5]) * v12;
  v15[4] = (v6 - v13) * v12;
  v15[5] = (this[10] * *this - this[8] * this[2]) * v12;
  v15[6] = (this[2] * this[4] - *this * this[6]) * v12;
  v9 = this[11];
  result = *((_DWORD *)this + 15);
  v15[7] = v4;
  v15[8] = (v3 - v14) * v12;
  v15[11] = v9;
  v11 = this[8];
  LODWORD(v15[15]) = result;
  v15[9] = (v11 * this[1] - *this * this[9]) * v12;
  v15[10] = (*this * this[5] - this[1] * this[4]) * v12;
  v15[12] = -(v15[0] * this[12] + v15[8] * this[14] + v15[4] * this[13]);
  v15[13] = -(v15[1] * this[12] + v15[9] * this[14] + v15[5] * this[13]);
  v15[14] = -(v15[2] * this[12] + v15[10] * this[14] + v15[6] * this[13]);
  qmemcpy(this, v15, 0x40u);
  return result;
}
