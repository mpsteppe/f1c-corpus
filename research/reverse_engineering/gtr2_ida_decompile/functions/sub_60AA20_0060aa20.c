int __usercall sub_60AA20@<eax>(int a1@<ecx>, __int32 a2@<ebp>)
{
  int v4; // [esp+0h] [ebp-4h]

  sub_5F6E20(a2, v4);
  *(_DWORD *)(a1 + 240) = 0;
  *(_BYTE *)(a1 + 236) = 1;
  return a1;
}
