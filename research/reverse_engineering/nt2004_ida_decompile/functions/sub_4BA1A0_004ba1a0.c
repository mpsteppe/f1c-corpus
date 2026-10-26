int __stdcall sub_4BA1A0(char a1, float a2)
{
  if ( sub_405BE0(&dword_629124) )
  {
    dword_75CBA8 = 6;
    sub_405C10(&dword_629124);
    return 0;
  }
  if ( *(_DWORD *)dword_76693C && (*(_DWORD *)(dword_75AACC + 20892) != 3 || !sub_463490(dword_764D70)) )
    return 0;
  if ( !a1 )
  {
    byte_75E9C0 = 0;
    sub_4BA5B0(a2);
    return 0;
  }
  if ( !byte_76617C )
    sub_40C410(&dword_6291CC, aTrackside, 3);
  sub_51BC20(1, 0);
  sub_4BA5B0(a2);
  return 0;
}
