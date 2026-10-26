float *__thiscall sub_5C6530(_DWORD *this, float *a2, int a3, double a4)
{
  int v4; // eax
  float v5; // edx
  float v6; // ecx
  float v7; // edx
  float v8; // ecx
  float v9; // edx
  float *v10; // esi
  float *v11; // eax
  double v12; // st7
  double v13; // st6
  double v14; // st5
  float *result; // eax
  float v16[3]; // [esp+Ch] [ebp-30h] BYREF
  float v17[3]; // [esp+18h] [ebp-24h] BYREF
  float v18[3]; // [esp+24h] [ebp-18h] BYREF
  float v19[3]; // [esp+30h] [ebp-Ch] BYREF

  v4 = *(_DWORD *)(this[1] + 8) + 16 * a3;
  v5 = *(float *)(v4 + 20);
  v16[0] = *(float *)(v4 + 16);
  v6 = *(float *)(v4 + 24);
  v16[1] = v5;
  v7 = *(float *)v4;
  v16[2] = v6;
  v8 = *(float *)(v4 + 4);
  v17[0] = v7;
  v9 = *(float *)(v4 + 8);
  v17[1] = v8;
  v17[2] = v9;
  v10 = sub_5BC0A0(v18, v16, a4);
  v11 = sub_5BC0A0(v19, v17, 1.0 - a4);
  v12 = v10[2] + v11[2];
  v13 = v10[1] + v11[1];
  v14 = *v10 + *v11;
  result = a2;
  *a2 = v14;
  a2[1] = v13;
  a2[2] = v12;
  return result;
}
