int __thiscall sub_4074A0(int *this)
{
  double v2; // st6
  int v3; // eax
  int v4; // edi
  int v6; // [esp+8h] [ebp-5Ch]
  float v7; // [esp+14h] [ebp-50h] BYREF
  float v8; // [esp+18h] [ebp-4Ch]
  float v9; // [esp+1Ch] [ebp-48h] BYREF
  float v10; // [esp+20h] [ebp-44h] BYREF
  float v11; // [esp+24h] [ebp-40h]
  float v12; // [esp+28h] [ebp-3Ch]
  _DWORD v13[3]; // [esp+2Ch] [ebp-38h] BYREF
  float v14[2]; // [esp+38h] [ebp-2Ch] BYREF
  float v15; // [esp+40h] [ebp-24h]
  float v16[8]; // [esp+44h] [ebp-20h] BYREF
  float retaddr; // [esp+64h] [ebp+0h]

  sub_4095D0(&v9, v6);
  sub_407440(this, (int)&v7);
  v13[0] = 0;
  *(float *)&v13[1] = sub_409310(this);
  v13[2] = 0;
  sub_614A90(v13, v16);
  v2 = v16[5] * v9 + v16[3] * v7 + v16[4] * v8;
  v15 = retaddr * v9 + v16[6] * v7 + v16[7] * v8;
  v7 = v10 + v16[2] * v9 + v16[1] * v8 + v16[0] * v7;
  v14[0] = v7;
  v8 = v2 + v11;
  v14[1] = v8;
  v9 = v12 + v15;
  v15 = v9;
  v3 = sub_409510(&v7, v14, 1);
  v4 = *this;
  v11 = *(float *)(v3 + 4);
  sub_409310(this);
  return (*(int (__thiscall **)(int *, float *))(v4 + 16))(this, &v10);
}
