int __stdcall sub_50D507(int a1, int a2, int a3, int a4)
{
  int result; // eax

  result = a1;
  *(float *)(a1 + 44) = 0.0;
  *(_DWORD *)(a1 + 48) = a2;
  *(float *)(a1 + 36) = 0.0;
  *(_DWORD *)(a1 + 52) = a3;
  *(float *)(a1 + 32) = 0.0;
  *(_DWORD *)(a1 + 56) = a4;
  *(float *)(a1 + 28) = 0.0;
  *(float *)(a1 + 24) = 0.0;
  *(float *)(a1 + 16) = 0.0;
  *(float *)(a1 + 12) = 0.0;
  *(float *)(a1 + 8) = 0.0;
  *(float *)(a1 + 4) = 0.0;
  *(float *)(a1 + 60) = 1.0;
  *(float *)(a1 + 40) = 1.0;
  *(float *)(a1 + 20) = 1.0;
  *(float *)a1 = 1.0;
  return result;
}
