char __fastcall sub_414280(int a1)
{
  _BYTE *v1; // edx
  char result; // al

  v1 = *(_BYTE **)(a1 + 4);
  result = 0;
  if ( v1 )
  {
    LOBYTE(a1) = *(_BYTE *)(a1 + 2);
    if ( (_BYTE)a1 )
    {
      a1 = (unsigned __int8)a1;
      do
      {
        if ( *v1 == 1 )
          ++result;
        ++v1;
        --a1;
      }
      while ( a1 );
    }
  }
  return result;
}
