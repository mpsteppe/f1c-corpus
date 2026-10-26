int __stdcall sub_6B5F20(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 4);
  if ( result )
    result = (*(int (__stdcall **)(int))(result + 40))(a1);
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  return result;
}
