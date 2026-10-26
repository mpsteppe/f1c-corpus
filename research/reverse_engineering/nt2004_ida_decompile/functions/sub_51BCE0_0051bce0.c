int __thiscall sub_51BCE0(float *this, int a2)
{
  int result; // eax

  result = a2;
  *(float *)(a2 + 8) = this[478];
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)a2 = 0;
  *(float *)(a2 + 4) = (this[4489] - this[4521] + this[4427] - this[4459]) * 0.5;
  return result;
}
