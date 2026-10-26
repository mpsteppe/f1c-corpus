void __stdcall sub_5D86C0(int a1, int a2, _DWORD *a3, int a4)
{
  float *v4; // edi
  double v5; // st7
  double v6; // st7
  double v7; // st7
  float v8; // [esp+8h] [ebp-28h] BYREF
  float v9; // [esp+Ch] [ebp-24h] BYREF
  float v10; // [esp+10h] [ebp-20h] BYREF
  float v11; // [esp+14h] [ebp-1Ch] BYREF
  float v12; // [esp+18h] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-14h]
  float v14; // [esp+20h] [ebp-10h] BYREF
  float v15; // [esp+24h] [ebp-Ch] BYREF
  float v16; // [esp+28h] [ebp-8h] BYREF
  float v17; // [esp+2Ch] [ebp-4h] BYREF
  float v18; // [esp+38h] [ebp+8h]

  if ( a2 )
  {
    v13 = sub_600770(1);
    v18 = sub_600770(2);
    sub_6006C0(1, &v15, &v16, &v17);
  }
  else
  {
    v15 = 1.0;
    v16 = 1.0;
    v17 = 1.0;
    v13 = 1.0;
    v18 = 1.0;
  }
  if ( a3 )
  {
    sub_5E86C0(1, &v8, &v10, &v12);
    v4 = (float *)a4;
    sub_5E8E20(2, a4 + 12);
    if ( (*a3 & 0x200000) != 0 )
    {
      v8 = v8 * v18;
      v10 = v10 * v18;
      v12 = v12 * v18;
    }
    sub_5E86C0(4, &v9, &v11, &v14);
    if ( (*a3 & 0x40000000) != 0 )
    {
      v9 = v9 * v18;
      v11 = v11 * v18;
      v14 = v14 * v18;
    }
  }
  else
  {
    v4 = (float *)a4;
    v8 = 1.0;
    v10 = 1.0;
    v12 = 1.0;
    v9 = 0.0;
    v11 = 0.0;
    v14 = 0.0;
    *(_DWORD *)(a4 + 12) = 1065353216;
  }
  if ( a1 )
    sub_5DCE20(&v15, &v16, &v17);
  v5 = v8 * v15 * v13 + v9;
  if ( v5 > 1.0 )
    v5 = 1.0;
  *v4 = v5;
  v6 = v10 * v16 * v13 + v11;
  if ( v6 > 1.0 )
    v6 = 1.0;
  v4[1] = v6;
  v7 = v12 * v17 * v13 + v14;
  if ( v7 <= 1.0 )
    v4[2] = v7;
  else
    v4[2] = 1.0;
}
