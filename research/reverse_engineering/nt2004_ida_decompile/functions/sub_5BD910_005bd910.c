int __fastcall sub_5BD910(int a1, int a2)
{
  int v4; // [esp+4h] [ebp-4h] BYREF

  v4 = a2;
  sub_5BE1C0(*(_DWORD *)(a1 + 4), &v4);
  return (*(int (__fastcall **)(int, _DWORD, int, _DWORD))(a1 + 1152))(a1, 0, v4, *(_DWORD *)(a1 + 1156));
}
