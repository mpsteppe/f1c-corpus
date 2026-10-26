// f1c  0x004b2bf0  size=43
double __thiscall sub_4B2BF0(int this)
{
  switch ( *(_DWORD *)(this + 15) & 3 )
  {
    case 1:
      return 0.80000001;
    case 2:
      return 0.89999998;
    case 3:
      return 1.0;
  }
  return 0.69999999;
}
