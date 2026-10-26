int __thiscall sub_4BA0E0(_DWORD *this, _DWORD *a2)
{
  sub_41B080(a2);
  if ( (unsigned __int8)sub_4EED40(a2) && sub_42DBA0() && !*(_DWORD *)dword_76693C )
  {
    if ( a2[5221] == 1 )
    {
      *(_BYTE *)this = 1;
      this[1] = 0;
    }
    else
    {
      sub_40C410(&dword_6291CC, aTrackside, 0);
      sub_51BC20(1, 0);
    }
    sub_4BA1A0(1, 10.0);
  }
  if ( sub_42DBA0() && *(_DWORD *)(dword_75AACC + 20892) == 1 && dword_7D7988 != 3 )
    sub_501F60(3, 0);
  return 0;
}
