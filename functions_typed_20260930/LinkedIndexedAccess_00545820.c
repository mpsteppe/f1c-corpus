int __thiscall sub_545820(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax

  v2 = a2;
  if ( a2 < 0 || a2 >= this[75] )
    return 0;
  result = this[76];
  if ( a2 > 0 )
  {
    do
    {
      --v2;
      result = *(_DWORD *)(result + 108);
    }
    while ( v2 );
  }
  return result;
}

