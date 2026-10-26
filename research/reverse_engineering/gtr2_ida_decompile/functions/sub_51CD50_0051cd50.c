int __thiscall sub_51CD50(float *this)
{
  const char *v2; // eax
  int v3; // eax
  float *v4; // eax
  double v5; // st7
  float v7; // [esp+18h] [ebp-3Ch]
  float v8; // [esp+20h] [ebp-34h]
  float v9; // [esp+28h] [ebp-2Ch]
  float v10; // [esp+30h] [ebp-24h] BYREF
  float v11; // [esp+34h] [ebp-20h] BYREF
  float v12; // [esp+38h] [ebp-1Ch] BYREF
  float v13; // [esp+3Ch] [ebp-18h] BYREF
  float v14; // [esp+40h] [ebp-14h] BYREF
  float v15; // [esp+44h] [ebp-10h] BYREF
  _BYTE v16[4]; // [esp+48h] [ebp-Ch] BYREF
  _BYTE v17[4]; // [esp+4Ch] [ebp-8h] BYREF
  _BYTE v18[4]; // [esp+50h] [ebp-4h] BYREF

  sub_5E5510(&v12, &v11, &v10, &v15, &v14, &v13);
  if ( dword_91BF28 == dword_91BF40 || (v2 = sub_410A10(&dword_91BF20), !_stricmp(v2, "GRIDWALK_CAM")) )
  {
    v5 = sub_51CCE0(-v12, -v11, -v10);
    if ( -100000000.0 == v5 )
      v5 = this[1263];
    this[1263] = v5;
  }
  else
  {
    v3 = sub_410A80(&dword_91BF20);
    sub_5E4D90(v3, v16, v17, v18);
    v13 = -v13;
    v14 = -v14;
    v15 = -v15;
    v4 = (float *)sub_4031C0();
    if ( v4 )
      v5 = sub_51CCE0(v4[1], v4[2], v4[3]);
    else
      v5 = v15;
  }
  v9 = -v13;
  v8 = -v15;
  v7 = -v5 - v11 - v5;
  return sub_5E51D0(v12, v7, v10, v8, v14, v9);
}
