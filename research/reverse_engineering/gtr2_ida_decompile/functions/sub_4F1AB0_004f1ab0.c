double __thiscall sub_4F1AB0(_DWORD *this)
{
  float v3; // edx
  float v4; // eax
  float v5; // [esp+10h] [ebp-18h] BYREF
  float v6; // [esp+14h] [ebp-14h]
  float v7; // [esp+18h] [ebp-10h]
  float v8[3]; // [esp+1Ch] [ebp-Ch] BYREF

  if ( !this[34] )
    return 99999.0;
  sub_577780(v8, &v5);
  v3 = *(float *)(this[34] + 236);
  v4 = *(float *)(this[34] + 240);
  v5 = v8[0] - *(float *)(this[34] + 232);
  v6 = v8[1] - v3;
  v7 = v8[2] - v4;
  return v7 * v7 + v6 * v6 + v5 * v5;
}
