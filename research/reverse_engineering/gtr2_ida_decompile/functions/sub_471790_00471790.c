bool __thiscall sub_471790(int this)
{
  float *v2; // ecx
  double v3; // st7
  double v4; // st7
  float v6; // [esp+4h] [ebp-24h] BYREF
  float v7; // [esp+8h] [ebp-20h]
  float v8; // [esp+Ch] [ebp-1Ch]
  float v9; // [esp+10h] [ebp-18h]
  float v10; // [esp+14h] [ebp-14h]
  float v11; // [esp+18h] [ebp-10h]
  float v12; // [esp+1Ch] [ebp-Ch]
  float v13; // [esp+20h] [ebp-8h]
  float v14; // [esp+24h] [ebp-4h]

  v6 = *(double *)(this + 232);
  v7 = *(double *)(this + 240);
  v8 = *(double *)(this + 248);
  v2 = sub_402D40(&flt_91BCA0, &v6, 0);
  v9 = v6 - v2[1];
  v12 = v9;
  v10 = v7 - v2[2];
  v13 = v10;
  v11 = v8 - v2[3];
  v14 = v11;
  v3 = v11 * v2[11] + v10 * v2[10] + v9 * v2[9];
  if ( v3 >= 0.0 )
    v4 = v3 - v2[13];
  else
    v4 = -v3 - v2[12];
  return v4 < *(float *)(this + 212) + 1.0;
}
