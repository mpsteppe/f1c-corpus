int __usercall sub_484960@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _BYTE *a4@<edi>)
{
  int v4; // ecx
  int v5; // eax
  const char *v6; // eax
  char Buffer[32]; // [esp+4h] [ebp-20h] BYREF

  --*(_DWORD *)(a1 + 72);
  *a4 += a1;
  v4 = a3 - 1;
  *a4 += v4;
  *a4 += a2;
  v4 -= 2;
  v5 = a1 - 3;
  dword_7689CC[v4] += BYTE1(v5);
  *(_DWORD *)(v4 + 872) = v5;
  *(_DWORD *)(v4 + 868) = &dword_76AD28;
  v6 = (const char *)sub_49D690(dword_76AD28);
  sprintf(Buffer, v6);
  sub_4A1AC0(Buffer);
  return 0;
}
