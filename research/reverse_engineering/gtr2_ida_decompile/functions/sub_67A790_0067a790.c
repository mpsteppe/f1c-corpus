int (__cdecl *__stdcall sub_67A790(int a1, int *a2, int a3))(int, _DWORD, _DWORD)
{
  int i; // edi
  int (__cdecl *result)(int, _DWORD, _DWORD); // eax

  for ( i = a3; i; --i )
    result = sub_67A175(a1, *a2++);
  return result;
}
