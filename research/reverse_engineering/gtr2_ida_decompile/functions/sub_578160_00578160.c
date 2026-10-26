float *__thiscall sub_578160(int this, float a2)
{
  float *result; // eax
  double v4; // st7
  double v5; // st6
  double v6; // st6
  double v7; // st7
  float v8; // [esp+4h] [ebp-48h] BYREF
  float v9; // [esp+8h] [ebp-44h]
  float v10; // [esp+Ch] [ebp-40h]
  float v11; // [esp+10h] [ebp-3Ch] BYREF
  float v12; // [esp+14h] [ebp-38h]
  float v13; // [esp+18h] [ebp-34h]
  float v14[3]; // [esp+1Ch] [ebp-30h] BYREF
  float v15[9]; // [esp+28h] [ebp-24h] BYREF

  result = *(float **)(this + 14804);
  if ( (unsigned int)result <= 2 )
  {
    v4 = a2 - *(float *)(this + 15932);
    v8 = v4 * *(float *)(this + 15996);
    v11 = v8;
    v9 = v4 * *(float *)(this + 16000);
    v12 = v9;
    v10 = v4 * *(float *)(this + 16004);
    v13 = v10;
    v8 = v8 + *(float *)(this + 15972);
    v14[0] = v8;
    v9 = v9 + *(float *)(this + 15976);
    v14[1] = v9;
    v5 = v10 + *(float *)(this + 15980);
    qmemcpy(v15, (const void *)(this + 15936), sizeof(v15));
    v10 = v5;
    v11 = v4 * *(float *)(this + 16020);
    v6 = v4 * *(float *)(this + 16024);
    v8 = v11;
    v12 = v6;
    v14[2] = v10;
    v7 = v4 * *(float *)(this + 16028);
    v9 = v12;
    v13 = v7;
    v10 = v13;
    sub_614F40(&v8);
    sub_40D5D0(v15, (int)&v11);
    return sub_569300((_DWORD *)(this + 2688), v14, &v11, v15);
  }
  return result;
}
