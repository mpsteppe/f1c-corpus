int __cdecl sub_561A15(int a1, int a2, int a3, int a4, int a5)
{
  _WORD *v5; // edi
  int result; // eax
  int v8; // [esp+20h] [ebp+14h]

  v5 = (_WORD *)(a1 + a1 + a5);
  v8 = 2 * a4;
  result = a3;
  do
  {
    *v5 = a3;
    v5 = (_WORD *)((char *)v5 + v8);
    --a2;
  }
  while ( a2 );
  return result;
}
