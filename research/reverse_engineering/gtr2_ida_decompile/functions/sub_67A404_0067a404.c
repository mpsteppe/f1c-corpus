int __stdcall sub_67A404(int a1)
{
  int result; // eax
  int v3; // edx
  int v4; // esi
  _BYTE v5[64]; // [esp+Ch] [ebp-40h] BYREF

  sub_6B8B6D(a1 + 100);
  sub_6B72A2(a1, *(void **)(a1 + 156));
  sub_6B72A2(a1, *(void **)(a1 + 220));
  sub_6B72A2(a1, *(void **)(a1 + 216));
  sub_6B72A2(a1, *(void **)(a1 + 224));
  sub_6B72A2(a1, *(void **)(a1 + 228));
  sub_6B72A2(a1, *(void **)(a1 + 232));
  sub_6B72A2(a1, *(void **)(a1 + 236));
  sub_6B72A2(a1, *(void **)(a1 + 388));
  sub_6B72A2(a1, *(void **)(a1 + 392));
  sub_6B72A2(a1, *(void **)(a1 + 396));
  sub_6B72A2(a1, *(void **)(a1 + 400));
  sub_6B72A2(a1, *(void **)(a1 + 404));
  result = *(_DWORD *)(a1 + 72);
  v3 = *(_DWORD *)(a1 + 64);
  qmemcpy(v5, (const void *)a1, sizeof(v5));
  v4 = *(_DWORD *)(a1 + 68);
  memset((void *)a1, 0, 0x19Cu);
  *(_DWORD *)(a1 + 68) = v4;
  qmemcpy((void *)a1, v5, 0x40u);
  *(_DWORD *)(a1 + 64) = v3;
  *(_DWORD *)(a1 + 72) = result;
  return result;
}
