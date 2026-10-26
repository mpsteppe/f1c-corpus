_WORD *__stdcall sub_5D70D0(int a1, _WORD *a2, int a3, __int16 a4)
{
  int v4; // edx
  _WORD *result; // eax

  v4 = a3;
  result = a2;
  if ( a3 > 0 )
  {
    do
    {
      *(_WORD *)((char *)result + a1 - (_DWORD)a2) = a4 + *result;
      ++result;
      --v4;
    }
    while ( v4 );
  }
  return result;
}
