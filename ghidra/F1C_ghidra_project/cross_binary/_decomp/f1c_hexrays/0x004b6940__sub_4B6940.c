// f1c  0x004b6940  size=91
int __thiscall sub_4B6940(_DWORD *this, float a2)
{
  char *v3; // ecx
  int result; // eax

  sub_4B7860(0);
  if ( (unsigned __int8)sub_4B69F0(this) )
  {
    v3 = (char *)this[620];
    this[623] = 0;
    this[622] = 0;
    sub_4B4E10(v3);
  }
  else
  {
    sub_4B69A0(this);
  }
  result = 176 * this[622];
  *(float *)(result + this[620] + 108) = a2;
  return result;
}
