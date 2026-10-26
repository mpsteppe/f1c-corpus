void __thiscall sub_4DE950(int *this)
{
  switch ( dword_7D7540 )
  {
    case 1:
    case 2:
    case 8:
      if ( (unsigned __int8)sub_4EED40(*this) )
        sub_45D100(&byte_764D68, (int)aWarningEntered, 3, 16909060, 0);
      break;
    case 3:
      if ( !(unsigned __int8)sub_4DE9D0(this) )
        sub_4DC690(this, aEnteredPitlane, 3, 0);
      break;
    default:
      return;
  }
}
