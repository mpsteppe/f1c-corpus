int (__cdecl *__stdcall sub_679F26(int a1, int a2))(int, int)
{
  int (__cdecl *result)(int, int); // eax

  result = *(int (__cdecl **)(int, int))(a1 + 68);
  if ( result )
    return (int (__cdecl *)(int, int))result(a1, a2);
  return result;
}
