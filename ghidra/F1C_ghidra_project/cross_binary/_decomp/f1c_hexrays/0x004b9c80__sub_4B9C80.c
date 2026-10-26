// f1c  0x004b9c80  size=48
double __thiscall sub_4B9C80(_DWORD *this)
{
  _DWORD *v1; // ecx
  float v3; // [esp+0h] [ebp-8h] BYREF
  float v4; // [esp+4h] [ebp-4h] BYREF

  v1 = (_DWORD *)*this;
  v4 = 0.0;
  v3 = 0.0;
  sub_4B87A0(v1, &v4, &v3);
  return v3 - v4;
}
