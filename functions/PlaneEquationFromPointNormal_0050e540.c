int __stdcall sub_50E540(int a1, float *a2, int a3)
{
  int result; // eax

  result = a1;
  *(float *)a1 = *(float *)a3;
  *(_DWORD *)(a1 + 4) = *(_DWORD *)(a3 + 4);
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(a3 + 8);
  *(float *)(a1 + 12) = -(a2[1] * *(float *)(a3 + 4) + a2[2] * *(float *)(a3 + 8) + *a2 * *(float *)a3);
  return result;
}
