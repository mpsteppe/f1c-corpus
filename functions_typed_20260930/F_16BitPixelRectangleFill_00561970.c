int __cdecl sub_561970(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _WORD *v8; // edi
  int result; // eax
  int v12; // [esp+24h] [ebp+18h]

  v8 = (_WORD *)(a6 + a6 + a8);
  v12 = 2 * a5;
  result = a7;
  do
  {
    *v8++ = a7;
    if ( a1 < 0 )
    {
      a1 += a3;
    }
    else
    {
      a1 += a4;
      v8 = (_WORD *)((char *)v8 + v12);
    }
    --a2;
  }
  while ( a2 );
  return result;
}

