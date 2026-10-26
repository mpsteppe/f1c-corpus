// f1c  0x00564270  size=61
int __fastcall sub_564270(int a1, int a2)
{
  int v3; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // [esp+4h] [ebp-4h] BYREF

  v7 = a2;
  v3 = sub_5647D0(*(_DWORD *)(a1 + 16), &v7);
  if ( v3 )
    return *(_DWORD *)v3;
  v5 = sub_564690(v7);
  v6 = *(_DWORD *)(a1 + 16);
  v7 = v5;
  sub_564780(v6, &v7);
  return v7;
}
