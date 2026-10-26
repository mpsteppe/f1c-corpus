int __cdecl sub_553F09(int a1)
{
  int v1; // eax

  v1 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 28);
  *(_DWORD *)(a1 + 380) = v1;
  *(_BYTE *)(v1 + 8) = 0;
  *(_DWORD *)v1 = sub_553DBB;
  *(_DWORD *)(v1 + 4) = sub_553EE8;
  return sub_553C0E(a1);
}
