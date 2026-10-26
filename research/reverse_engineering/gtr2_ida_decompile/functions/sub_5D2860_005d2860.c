float *__thiscall sub_5D2860(float *this, float *a2, float *a3)
{
  double v3; // st7
  float v4; // eax
  double v5; // st7
  float v6; // edx
  double v7; // st7
  float *v8; // eax
  float *v9; // eax
  double v10; // st7
  double v11; // st6
  double v12; // st5
  float *result; // eax
  float v14[4]; // [esp+0h] [ebp-30h] BYREF
  float v15[4]; // [esp+10h] [ebp-20h] BYREF
  float v16[4]; // [esp+20h] [ebp-10h] BYREF

  v3 = -*this;
  v15[0] = *a3;
  v14[0] = v3;
  v4 = a3[2];
  v5 = -this[1];
  v15[1] = a3[1];
  v14[1] = v5;
  v6 = this[3];
  v7 = this[2];
  v15[2] = v4;
  v14[3] = v6;
  v14[2] = -v7;
  v15[3] = 0.0;
  v8 = sub_5D1CD0(v16, this, v15);
  v9 = sub_5D1CD0(v15, v8, v14);
  v10 = *v9;
  v11 = v9[1];
  v12 = v9[2];
  result = a2;
  *a2 = v10;
  a2[1] = v11;
  a2[2] = v12;
  return result;
}
