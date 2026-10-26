int __thiscall sub_45AE00(int this, float a2)
{
  int result; // eax
  double v3; // st7
  double v4; // st5
  double v5; // st7
  double v6; // st7
  long double v7; // st6
  long double v8; // st5
  int v9; // [esp+0h] [ebp-ACh]
  int v10; // [esp+4h] [ebp-A8h]
  int v11; // [esp+8h] [ebp-A4h]
  float v12; // [esp+Ch] [ebp-A0h]
  float v13; // [esp+10h] [ebp-9Ch]
  float v14; // [esp+14h] [ebp-98h]
  double v15[3]; // [esp+1Ch] [ebp-90h] BYREF
  double v16; // [esp+34h] [ebp-78h]
  double v17; // [esp+3Ch] [ebp-70h]
  double v18; // [esp+44h] [ebp-68h]
  double v19[9]; // [esp+4Ch] [ebp-60h] BYREF
  _BYTE v20[24]; // [esp+94h] [ebp-18h] BYREF

  result = *(_DWORD *)(this + 208);
  if ( result )
  {
    v3 = a2 - *(float *)(this + 36);
    v4 = v3 * *(double *)(this + 312);
    v15[1] = v3 * *(double *)(this + 320);
    v15[2] = v3 * *(double *)(this + 328);
    v16 = v4 + *(double *)(this + 216);
    v17 = v15[1] + *(double *)(this + 224);
    v18 = v15[2] + *(double *)(this + 232);
    v15[0] = v3 * *(double *)(this + 336);
    v15[1] = v3 * *(double *)(this + 344);
    v15[2] = v3 * *(double *)(this + 352);
    qmemcpy(v20, v15, sizeof(v20));
    qmemcpy(v19, (const void *)(this + 240), sizeof(v19));
    sub_56C020(v20);
    v5 = v19[5];
    FloatConvertWrapper();
    v6 = -v5;
    if ( fabs(v19[5]) == 1.0 )
    {
      v7 = atan2(-v19[6], v19[0]);
      v8 = 0.0;
    }
    else
    {
      v7 = atan2(v19[2], v19[8]);
      v8 = atan2(v19[3], v19[4]);
    }
    v14 = v8;
    v13 = v7;
    v12 = v6;
    *(float *)&v11 = v18;
    *(float *)&v10 = v17;
    *(float *)&v9 = v16;
    return sub_54B4D0(v9, v10, v11, v12, v13, v14);
  }
  return result;
}
