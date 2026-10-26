double __thiscall sub_4D9AF0(int *this)
{
  int v2; // esi
  double v3; // st6
  double v4; // st7
  double v5; // st7
  float v7; // [esp+8h] [ebp-Ch] BYREF
  float v8; // [esp+Ch] [ebp-8h]
  float v9; // [esp+10h] [ebp-4h] BYREF

  v2 = *this;
  v7 = 0.0;
  v9 = 0.0;
  sub_4D8430((_DWORD *)v2, &v7, &v9);
  if ( *(_BYTE *)(v2 + 2149) )
  {
    v3 = dbl_7DA9D0 - *(float *)(v2 + 2152);
    v8 = v3;
    if ( v3 < v7 )
      v8 = v7;
    v4 = dbl_7DA9D0 - v8;
  }
  else
  {
    v4 = v9 - v7;
    v8 = v7;
  }
  v9 = v4;
  if ( v4 <= 0.0 )
    return 0.0;
  v5 = sub_4D9E20(this);
  return (v5 - v8) / v9;
}
