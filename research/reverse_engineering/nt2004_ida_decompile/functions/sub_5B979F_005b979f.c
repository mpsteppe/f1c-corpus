int __cdecl sub_5B979F(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  _WORD *v9; // edi
  int result; // eax
  int v13; // [esp+24h] [ebp+18h]
  int v14; // [esp+30h] [ebp+24h]

  v9 = (_WORD *)(a6 + a6 + a9);
  v13 = 2 * a5;
  v14 = 2 * a8;
  result = a7;
  do
  {
    *v9 = a7;
    v9 = (_WORD *)((char *)v9 + v14);
    if ( a1 < 0 )
    {
      a1 += a3;
    }
    else
    {
      a1 += a4;
      v9 = (_WORD *)((char *)v9 + v13);
    }
    --a2;
  }
  while ( a2 );
  return result;
}
