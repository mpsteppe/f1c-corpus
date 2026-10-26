int __thiscall sub_45C060(int this, float a2)
{
  int result; // eax
  double v3; // st7
  double v4; // st5
  long double v5; // st7
  long double v6; // st6
  long double v7; // st5
  int v8; // [esp+0h] [ebp-ACh]
  int v9; // [esp+4h] [ebp-A8h]
  int v10; // [esp+8h] [ebp-A4h]
  float v11; // [esp+Ch] [ebp-A0h]
  float v12; // [esp+10h] [ebp-9Ch]
  float v13; // [esp+14h] [ebp-98h]
  double v14[3]; // [esp+1Ch] [ebp-90h] BYREF
  double v15; // [esp+34h] [ebp-78h]
  double v16; // [esp+3Ch] [ebp-70h]
  double v17; // [esp+44h] [ebp-68h]
  double v18[9]; // [esp+4Ch] [ebp-60h] BYREF
  _BYTE v19[24]; // [esp+94h] [ebp-18h] BYREF

  result = *(_DWORD *)(this + 212);
  if ( result )
  {
    v3 = a2 - *(float *)(this + 36);
    v4 = v3 * *(double *)(this + 316);
    v14[1] = v3 * *(double *)(this + 324);
    v14[2] = v3 * *(double *)(this + 332);
    v15 = v4 + *(double *)(this + 220);
    v16 = v14[1] + *(double *)(this + 228);
    v17 = v14[2] + *(double *)(this + 236);
    v14[0] = v3 * *(double *)(this + 340);
    v14[1] = v3 * *(double *)(this + 348);
    v14[2] = v3 * *(double *)(this + 356);
    qmemcpy(v19, v14, sizeof(v19));
    qmemcpy(v18, (const void *)(this + 244), sizeof(v18));
    sub_57EDB0(v19);
    v5 = -asin(v18[5]);
    if ( fabs(v18[5]) == 1.0 )
    {
      v6 = atan2(-v18[6], v18[0]);
      v7 = 0.0;
    }
    else
    {
      v6 = atan2(v18[2], v18[8]);
      v7 = atan2(v18[3], v18[4]);
    }
    v13 = v7;
    v12 = v6;
    v11 = v5;
    *(float *)&v10 = v17;
    *(float *)&v9 = v16;
    *(float *)&v8 = v15;
    return sub_59E170(v8, v9, v10, v11, v12, v13);
  }
  return result;
}
