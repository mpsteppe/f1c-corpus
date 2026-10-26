int __usercall sub_60A7C0@<eax>(int a1@<ecx>, __int32 a2@<ebp>)
{
  int v4; // [esp+0h] [ebp-4h]

  sub_5F6E20(a2, v4);
  *(_DWORD *)(a1 + 204) = 0;
  *(_DWORD *)(a1 + 208) = 0;
  *(_DWORD *)(a1 + 212) = 0;
  *(_DWORD *)(a1 + 216) = 0;
  *(_DWORD *)(a1 + 220) = 0;
  *(_DWORD *)(a1 + 228) = 0;
  *(_WORD *)(a1 + 236) = 1;
  *(_DWORD *)(a1 + 240) = 1;
  *(_DWORD *)(a1 + 244) = 4;
  return a1;
}
