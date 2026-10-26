int __thiscall sub_4B2800(__int16 *this, int a2)
{
  int result; // eax

  result = a2;
  *(_DWORD *)(a2 + 4) = 0;
  *(float *)a2 = (double)this[20] * 0.001953125;
  *(float *)(a2 + 8) = (double)this[21] * 0.001953125;
  return result;
}
