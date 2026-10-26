int __thiscall sub_4F26D0(float *this, float *a2)
{
  double v3; // st7
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c2
  double v6; // st7
  double v7; // st7
  int result; // eax
  float v9; // edx
  float *v10; // edi
  long double v11; // st4
  float v12[16]; // [esp+0h] [ebp-40h] BYREF

  this[4] = *a2;
  this[5] = a2[1];
  this[6] = a2[2];
  v3 = this[4];
  if ( v4 | v5 )
    v6 = v3 - -0.30000001;
  else
    v6 = v3 - 0.30000001;
  this[4] = v6;
  v7 = a2[1] - 0.5;
  v12[12] = *a2;
  a2[1] = v7;
  result = *((_DWORD *)this + 3);
  v9 = a2[2];
  v10 = (float *)(**(_DWORD **)(result + 232) + 4);
  v12[2] = 0.0;
  v12[3] = 0.0;
  memset(&v12[6], 0, 16);
  v12[10] = 1.0;
  v12[11] = 0.0;
  v12[15] = 1.0;
  v12[14] = v9;
  v12[0] = cos(1.570796370506287);
  v11 = sin(1.570796370506287);
  v12[1] = v11;
  v12[4] = -v11;
  v12[5] = v12[0];
  v12[13] = v7;
  qmemcpy(v10, v12, 0x40u);
  return result;
}
