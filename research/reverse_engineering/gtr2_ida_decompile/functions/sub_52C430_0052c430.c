char __thiscall sub_52C430(int *this, char a2, char a3)
{
  float *v4; // ecx
  float *v5; // esi
  double v7; // st7
  char *v8; // eax
  char *v9; // eax
  float v10; // [esp+18h] [ebp-78h]
  float v11; // [esp+1Ch] [ebp-74h]
  float v12; // [esp+20h] [ebp-70h]
  float v13; // [esp+24h] [ebp-6Ch]
  float v14; // [esp+28h] [ebp-68h]
  float v15; // [esp+2Ch] [ebp-64h]
  float v16; // [esp+30h] [ebp-60h]
  float v17; // [esp+34h] [ebp-5Ch]
  float v18; // [esp+38h] [ebp-58h]
  float v19[6]; // [esp+3Ch] [ebp-54h] BYREF
  _BYTE v20[12]; // [esp+54h] [ebp-3Ch] BYREF
  _BYTE v21[8]; // [esp+60h] [ebp-30h] BYREF
  float v22; // [esp+68h] [ebp-28h]
  float v23; // [esp+74h] [ebp-1Ch]
  float v24; // [esp+80h] [ebp-10h]
  _BYTE v25[12]; // [esp+84h] [ebp-Ch] BYREF

  v4 = (float *)*this;
  v5 = v4 + 4;
  v12 = v4[4003] * v4[4003] + v4[4004] * v4[4004] + v4[4005] * v4[4005];
  if ( !a2 && v12 > 1.0 )
    return 0;
  sub_54FD90(v4);
  sub_614A90(v20, v21);
  v13 = -v22;
  v14 = -v23;
  v15 = -v24;
  sub_577780(v19, v25);
  v16 = v19[0] - v19[3];
  v17 = v19[1] - v19[4];
  v18 = v19[2] - v19[5];
  v11 = v18 * v15 + v17 * v14 + v13 * v16;
  v10 = -v5[3992] * v15 + -v5[3989] * v14 + -v5[3986] * v13;
  if ( a2 )
  {
    if ( v12 > 1.0 || v18 * v18 + v17 * v17 + v16 * v16 > 5.0625 || v11 > 1.5 || v10 < 0.75 )
    {
      if ( dword_B704D4 && *((_DWORD *)v5 + 3701) != 1 )
      {
        if ( v18 * v18 + v17 * v17 + v16 * v16 <= 225.0 )
          sub_52BC40();
        else
          sub_52C000(this, "False Start");
        return 0;
      }
      return 0;
    }
  }
  else
  {
    v7 = v18 * v18 + v17 * v17 + v16 * v16;
    if ( v7 > 3.0625 || v11 > 1.25 || v10 < 0.85000002 )
    {
      if ( a3 && v7 < 400.0 )
      {
        v9 = sub_41D840(&byte_91CC38, "Not Lined Up Properly");
        sub_4730C0((int **)&dword_B6CB98, v9, 2, (int)&byte_1020304, 1084227584);
        return 0;
      }
      return 0;
    }
  }
  if ( a3 )
  {
    v8 = sub_41D840(&byte_91CC38, "Not Lined Up Properly");
    sub_472920((const char **)&dword_B6CB98, v8, 0);
  }
  return 1;
}
