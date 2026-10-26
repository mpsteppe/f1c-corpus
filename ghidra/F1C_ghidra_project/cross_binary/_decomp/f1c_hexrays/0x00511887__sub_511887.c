// f1c  0x00511887  size=21
int (__cdecl *__cdecl sub_511887(int a1, int a2))(int, int)
{
  int (__cdecl *result)(int, int); // eax

  result = *(int (__cdecl **)(int, int))(a1 + 68);
  if ( result )
    return (int (__cdecl *)(int, int))result(a1, a2);
  return result;
}
