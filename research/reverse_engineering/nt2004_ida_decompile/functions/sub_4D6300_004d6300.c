int __thiscall sub_4D6300(_DWORD *this, float a2)
{
  float *v3; // ecx
  int result; // eax

  sub_4D7380(0);
  if ( (unsigned __int8)sub_4D63B0(this) )
  {
    v3 = (float *)this[330];
    this[333] = 0;
    this[332] = 0;
    sub_4D3D70(v3);
  }
  else
  {
    sub_4D6360(this);
  }
  result = this[332] << 7;
  *(float *)(result + this[330] + 60) = a2;
  return result;
}
