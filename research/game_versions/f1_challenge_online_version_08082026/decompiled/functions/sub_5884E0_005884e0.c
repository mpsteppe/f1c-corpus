int __cdecl sub_5884E0(int a1)
{
  int result; // eax

  result = sub_58E0C7();
  *(_DWORD *)(result + 20) = a1;
  return result;
}
