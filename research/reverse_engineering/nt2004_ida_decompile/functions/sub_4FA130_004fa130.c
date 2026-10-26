void sub_4FA130()
{
  if ( (dword_75CBAC & 1) != 0
    && dword_75CBB0 == 7
    && (dword_75CBB4 == 3 || dword_75CBB4 > 4 && dword_75CBB4 <= 8)
    && !sub_4633A0(dword_764D70)
    && dword_7D5DA4 != 2
    && !dword_766180
    && !byte_76617C )
  {
    if ( dword_763BB0 )
      sub_4BA660();
  }
}
