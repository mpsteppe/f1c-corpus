int __cdecl sub_515ECD(int a1)
{
  int result; // eax

  result = (**(int (__cdecl ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 24);
  *(_DWORD *)(a1 + 396) = result;
  *(_BYTE *)(result + 16) = 0;
  *(_BYTE *)(result + 17) = 0;
  *(_DWORD *)result = sub_515DF2;
  *(_DWORD *)(result + 4) = sub_515E85;
  *(_DWORD *)(result + 8) = sub_515DB8;
  *(_DWORD *)(result + 12) = sub_515EBC;
  *(_BYTE *)(result + 20) = 1;
  return result;
}
