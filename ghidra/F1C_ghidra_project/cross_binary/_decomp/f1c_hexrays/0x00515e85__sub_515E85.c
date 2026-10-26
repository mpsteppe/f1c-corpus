// f1c  0x00515e85  size=55
int __cdecl sub_515E85(int a1)
{
  int v1; // eax
  int result; // eax

  v1 = *(_DWORD *)(a1 + 396);
  *(_BYTE *)(v1 + 16) = 0;
  *(_BYTE *)(v1 + 17) = 0;
  *(_DWORD *)v1 = sub_515DF2;
  *(_BYTE *)(v1 + 20) = 1;
  (*(void (__cdecl **)(int))(*(_DWORD *)a1 + 16))(a1);
  result = (**(int (__cdecl ***)(int))(a1 + 400))(a1);
  *(_DWORD *)(a1 + 140) = 0;
  return result;
}
