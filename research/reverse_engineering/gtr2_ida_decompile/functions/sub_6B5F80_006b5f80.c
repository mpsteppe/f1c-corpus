int __stdcall sub_6B5F80(int a1)
{
  int result; // eax

  result = (**(int (__stdcall ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 280);
  *(_DWORD *)(result + 276) = 0;
  return result;
}
