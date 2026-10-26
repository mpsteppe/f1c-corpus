char sub_4BC636()
{
  char result; // al

  result = sub_4735A0();
  if ( !result
    && dword_BE1204 != 2
    && (*(_DWORD *)dword_B640C8 != 6 || (result = byte_B6F118) == 0)
    && dword_B6E4D0 != 1 )
  {
    sub_4304C0();
    if ( byte_B6413C )
      return sub_540130(&unk_BE1D30);
    else
      return sub_540140(&unk_BE1D30);
  }
  return result;
}
