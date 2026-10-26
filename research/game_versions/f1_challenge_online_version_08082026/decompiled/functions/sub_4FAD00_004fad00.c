int sub_4FAD00()
{
  int result; // eax

  if ( sub_4D7A50(dword_8AD25C, 2, (int)aDDevF119992002_26, 1457) )
    sub_4D7AA0((int)dword_8AD25C, (int)aEnteredVidmanE_0);
  sub_494900();
  sub_55C040(dword_8AFE64);
  sub_4A1830();
  sub_4A14E0();
  sub_4A1830();
  result = dword_8AFE64;
  if ( dword_8AFE64 )
  {
    result = sub_53D4C0(&dword_8AFE64);
    dword_8AFE64 = 0;
  }
  return result;
}
