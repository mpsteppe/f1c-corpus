int __thiscall sub_5773F0(float *this, int a2)
{
  int result; // eax

  result = a2;
  *(float *)(a2 + 8) = this[699];
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)a2 = 0;
  *(float *)(a2 + 4) = (this[4104] - this[4136] + this[4041] - this[4073]) * 0.5;
  return result;
}
