int __thiscall sub_4CFD80(float *this)
{
  float *v2; // ecx
  float v3; // eax
  int v4; // edx
  float v6[4]; // [esp+4h] [ebp-1Ch] BYREF
  _DWORD v7[3]; // [esp+14h] [ebp-Ch] BYREF

  v2 = this + 7;
  v6[0] = *v2;
  v3 = v2[2];
  v6[1] = v2[1];
  v6[2] = v3;
  *(float *)v7 = this[10];
  v4 = *((_DWORD *)this + 12);
  *(float *)&v7[1] = this[11];
  v7[2] = v4;
  sub_4CF5A0(v2, v6);
  sub_579450(v7, v6);
  return sub_4CF720((_DWORD *)this + 9, v6);
}
