// f1c  0x0050cdff  size=109
int __stdcall sub_50CDFF(int a1, int a2)
{
  double v2; // st7
  int result; // eax
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7

  v2 = *(float *)(a2 + 4);
  result = a1;
  *(float *)(a1 + 4) = *(float *)(a2 + 16);
  *(float *)(a1 + 16) = v2;
  v4 = *(float *)(a2 + 8);
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(a2 + 32);
  *(float *)(a1 + 32) = v4;
  v5 = *(float *)(a2 + 12);
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(a2 + 48);
  *(float *)(a1 + 48) = v5;
  v6 = *(float *)(a2 + 24);
  *(_DWORD *)(a1 + 24) = *(_DWORD *)(a2 + 36);
  *(float *)(a1 + 36) = v6;
  v7 = *(float *)(a2 + 28);
  *(_DWORD *)(a1 + 28) = *(_DWORD *)(a2 + 52);
  *(float *)(a1 + 52) = v7;
  v8 = *(float *)(a2 + 44);
  *(_DWORD *)(a1 + 44) = *(_DWORD *)(a2 + 56);
  *(float *)(a1 + 56) = v8;
  if ( a1 != a2 )
  {
    *(_DWORD *)a1 = *(_DWORD *)a2;
    *(_DWORD *)(a1 + 20) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(a1 + 40) = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(a1 + 60) = *(_DWORD *)(a2 + 60);
  }
  return result;
}
