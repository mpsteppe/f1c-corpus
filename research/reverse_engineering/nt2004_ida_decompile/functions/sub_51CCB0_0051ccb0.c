float *__thiscall sub_51CCB0(int this, float a2)
{
  float *result; // eax
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st6
  double v8; // st6
  float v9; // edx
  float v10; // [esp+4h] [ebp-48h] BYREF
  float v11; // [esp+8h] [ebp-44h]
  float v12; // [esp+Ch] [ebp-40h]
  _DWORD v13[3]; // [esp+10h] [ebp-3Ch] BYREF
  float v14[2]; // [esp+1Ch] [ebp-30h] BYREF
  float v15; // [esp+24h] [ebp-28h]
  _BYTE v16[36]; // [esp+28h] [ebp-24h] BYREF

  result = *(float **)(this + 16500);
  if ( (unsigned int)result <= 2 )
  {
    v4 = a2 - *(float *)(this + 17480);
    v5 = v4 * *(float *)(this + 17544);
    v6 = v4 * *(float *)(this + 17548);
    v15 = v4 * *(float *)(this + 17552);
    v10 = v5 + *(float *)(this + 17520);
    v14[0] = v10;
    v11 = v6 + *(float *)(this + 17524);
    v14[1] = v11;
    v7 = v15 + *(float *)(this + 17528);
    qmemcpy(v16, (const void *)(this + 17484), sizeof(v16));
    v12 = v7;
    v10 = v4 * *(float *)(this + 17568);
    v8 = v4 * *(float *)(this + 17572);
    v9 = v12;
    *(float *)v13 = v10;
    v11 = v8;
    *(float *)&v13[1] = v11;
    v12 = v4 * *(float *)(this + 17576);
    v15 = v9;
    *(float *)&v13[2] = v12;
    sub_579930(v13, &v10);
    return sub_50CAA0((_DWORD *)(this + 1808), v14, &v10, v16);
  }
  return result;
}
