int __cdecl sub_5115C4(_DWORD *a1)
{
  _DWORD *v1; // eax
  int result; // eax

  a1[49] = 0;
  a1[31] = 0;
  a1[94] = 0;
  v1 = a1 + 100;
  *(_BYTE *)(*v1 + 80) = 0;
  *(_BYTE *)(*v1 + 81) = 0;
  result = a1[100];
  *(_DWORD *)(result + 88) = 0;
  return result;
}
