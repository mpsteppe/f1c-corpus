int __fastcall sub_5BA160(int a1, int a2, int a3)
{
  int v3; // ecx
  int v4; // eax
  int v6; // [esp+0h] [ebp-8h] BYREF

  v3 = *(_DWORD *)(a1 + 24);
  v6 = a2;
  v4 = ((int (__fastcall *)(int, int *))sub_5BE0C0)(v3, &v6);
  if ( v4 )
    return *(_DWORD *)(v4 + 4);
  else
    return a3;
}
