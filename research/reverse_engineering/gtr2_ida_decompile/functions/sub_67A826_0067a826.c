int (__cdecl *__stdcall sub_67A826(int a1))(int)
{
  int (__cdecl *result)(int); // eax

  result = *(int (__cdecl **)(int))(a1 + 288);
  if ( result )
    return (int (__cdecl *)(int))result(a1);
  return result;
}
