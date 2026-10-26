int __fastcall sub_562FE0(int a1, int a2)
{
  int v3; // [esp-Ch] [ebp-Ch]

  v3 = *(_DWORD *)(a1 + 124);
  *(_DWORD *)a1 = a2;
  return (*(int (__cdecl **)(int, int, int, _DWORD, _DWORD))(a1 + 120))(a1, 1, v3, 0, 0);
}

