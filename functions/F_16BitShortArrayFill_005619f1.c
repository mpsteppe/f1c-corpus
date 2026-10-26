int __cdecl sub_5619F1(int a1, int a2, int a3, int a4)
{
  _WORD *v4; // edi
  int result; // eax

  v4 = (_WORD *)(a1 + a1 + a4);
  result = a3;
  while ( a2 )
  {
    *v4++ = a3;
    --a2;
  }
  return result;
}
