void sub_550360()
{
  if ( (dword_B640C4 & 1) != 0
    && *(_DWORD *)dword_B640C8 == 6
    && (dword_B64134 == 3 || dword_B64134 > 4 && dword_B64134 <= 8)
    && !sub_473550()
    && dword_BE1204 != 2
    && !dword_B6F11C
    && !byte_B6F118
    && dword_B6E4DC == 1 )
  {
    sub_4EA8F0();
    dword_B6E4DC = 7;
  }
}
