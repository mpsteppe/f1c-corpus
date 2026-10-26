// f1c  0x00598c88  size=57
int __fastcall sub_598C88(int a1)
{
  int v2; // eax
  int v3; // esi
  _BYTE v5[4]; // [esp+8h] [ebp-4h] BYREF

  sub_59A54D(v5);
  v2 = *(_DWORD *)(a1 + 4);
  if ( v2 && v2 != -1 )
    *(_DWORD *)(a1 + 4) = v2 - 1;
  v3 = *(_DWORD *)(a1 + 4) == 0 ? a1 : 0;
  sub_59A5E9(v5);
  return v3;
}
