int __thiscall sub_4F3470(int this, _DWORD *a2, _DWORD *a3)
{
  int v4; // eax
  int v5; // eax
  int result; // eax
  int v7; // [esp-4h] [ebp-50h]
  float v8; // [esp+8h] [ebp-44h] BYREF
  float v9; // [esp+Ch] [ebp-40h]
  float v10; // [esp+10h] [ebp-3Ch]
  double v11[6]; // [esp+14h] [ebp-38h] BYREF
  int v12; // [esp+44h] [ebp-8h]

  sub_5D7810(a2, &v8, *(_DWORD *)(*(_DWORD *)(this + 4) + 300) + 76);
  v4 = *(_DWORD *)(this + 184);
  v11[0] = v8;
  v11[1] = v9;
  v11[2] = v10;
  v12 = v4;
  v11[3] = 1000000.0;
  v11[4] = 9.999999933815813e36;
  v5 = sub_45D190(dbl_B68610, (int)v11);
  *(_DWORD *)(this + 184) = v5;
  if ( v5 )
  {
    v7 = *(_DWORD *)(this + 4) + 224;
    v9 = v11[5] + *(float *)(this + 188);
    return sub_5D7810(&v8, a3, v7);
  }
  else
  {
    *a3 = *a2;
    a3[1] = a2[1];
    result = a2[2];
    a3[2] = result;
  }
  return result;
}
