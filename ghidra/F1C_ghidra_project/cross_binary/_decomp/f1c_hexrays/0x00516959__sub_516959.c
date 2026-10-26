// f1c  0x00516959  size=27
int __cdecl sub_516959(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 4);
  if ( result )
    result = (*(int (__cdecl **)(int))(result + 40))(a1);
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  return result;
}
