int __stdcall sub_49F377(int a1, int a2)
{
  _DWORD v3[3]; // [esp+2Ch] [ebp-8Ch] BYREF
  _BYTE v4[64]; // [esp+38h] [ebp-80h] BYREF
  _BYTE v5[64]; // [esp+78h] [ebp-40h] BYREF

  dword_FB2EB4 = a1;
  flt_910FD8 = 0.5 / (double)*(int *)(a1 + 100) + 0.5;
  flt_910FDC = 0.5 / (double)*(int *)(a1 + 104) + 0.5;
  sub_5AA514(v4, a1 + 632, &unk_910FA8);
  qmemcpy(v5, v4, sizeof(v5));
  (*(void (__stdcall **)(int, int, _BYTE *, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, 16, v5, 4);
  (*(void (__stdcall **)(int, int, int, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, 20, dword_FB2EB4 + 348, 4);
  v3[0] = 0;
  v3[1] = 0;
  v3[2] = -1082130432;
  sub_5D77B0(v3, &unk_FB2F68, dword_FB2EB4 + 564);
  return (*(int (__stdcall **)(int, int, void *, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, 11, &unk_FB2F68, 1);
}
