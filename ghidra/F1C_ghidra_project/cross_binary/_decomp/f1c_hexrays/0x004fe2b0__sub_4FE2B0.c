// f1c  0x004fe2b0  size=158
double __stdcall sub_4FE2B0(int a1)
{
  if ( !sub_588410(a1, &off_5D6FD4) )
    return 32.5;
  if ( !sub_588410(a1, aWarm) )
    return 26.25;
  if ( !sub_588410(a1, aMedium) )
    return 20.0;
  if ( !sub_588410(a1, aCool) )
    return 13.75;
  if ( sub_588410(a1, aCold) )
    return sub_58850F(a1);
  return 7.5;
}
