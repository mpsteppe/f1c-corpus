int __thiscall sub_50F940(int this)
{
  int result; // eax
  CHAR *v3; // eax
  int v4; // eax
  bool v5; // cc
  int v6; // eax
  double v7; // st7
  _DWORD v8[59]; // [esp+8h] [ebp-39F8h] BYREF
  int v9; // [esp+F4h] [ebp-390Ch]
  double v10; // [esp+F8h] [ebp-3908h]
  char String2[32]; // [esp+1C7Ch] [ebp-1D84h] BYREF
  char v12[32]; // [esp+1C9Ch] [ebp-1D64h] BYREF
  char v13[36]; // [esp+1CBCh] [ebp-1D44h] BYREF
  char v14[104]; // [esp+1CE0h] [ebp-1D20h] BYREF
  int v15; // [esp+1D48h] [ebp-1CB8h]
  _DWORD v16[236]; // [esp+3650h] [ebp-3B0h] BYREF

  sub_50FB70(this);
  *(_DWORD *)(this + 17456) = !sub_4EED40(*(_DWORD **)this);
  result = *(_DWORD *)(this + 16500);
  if ( result )
  {
    if ( result <= 0 || result > 3 )
      return result;
  }
  else
  {
    sub_4412D0((int)&dbl_75E930, *(_DWORD *)this);
  }
  sub_430BC0(v14);
  sub_5208C0(v8);
  v3 = *(CHAR **)(1232 * *(_DWORD *)(*(_DWORD *)this + 25252) + dword_7D6A5C + 8);
  if ( !v3 )
    v3 = &byte_629120;
  sub_521740((char)v3, (int)v14, 0);
  sub_521740(*(_DWORD *)this + 32, (int)v14, 1);
  sub_50B080((_DWORD *)(this + 1808), v12, v13);
  sub_50B020((_DWORD *)(this + 1808), String2);
  v4 = v9;
  v5 = v9 < 1;
  *(_DWORD *)(this + 17460) = v9;
  if ( v5 )
  {
    *(_DWORD *)(this + 17460) = 1;
  }
  else if ( v4 > 64 )
  {
    *(_DWORD *)(this + 17460) = 64;
  }
  v6 = *(_DWORD *)(this + 17460);
  *(float *)(this + 17464) = v10 * v10;
  v7 = 1.0 / (double)(40 * v6);
  *(float *)(this + 17468) = v7;
  *(float *)(this + 17472) = 1.0 / (double)(8 * (5 * v6 + 5));
  *(float *)(this + 17476) = v7;
  *(float *)(this + 17480) = dbl_7DA9D0;
  sub_511500(v14, v8);
  sub_513830(0);
  if ( v8[11] )
    sub_5BE8AE();
  if ( v8[9] )
    sub_5BE8AE();
  if ( v8[7] )
    sub_5BE8AE();
  if ( v8[5] )
    sub_5BE8AE();
  if ( v8[3] )
    sub_5BE8AE();
  if ( v8[0] )
    sub_5BE8AE();
  sub_430670(v16);
  result = v15;
  if ( v15 )
    return sub_5BE8AE();
  return result;
}
