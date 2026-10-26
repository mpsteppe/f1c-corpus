int __thiscall sub_4A4830(void *this)
{
  if ( !sub_588410(this, aHardCompound) )
    return 2;
  if ( !sub_588410(this, aSoftCompound) )
    return 3;
  if ( !sub_588410(this, aIntermediateCo) )
    return 4;
  if ( sub_588410(this, aWetCompound) )
    return sub_588410(this, aMonsoonCompoun) != 0 ? 1 : 6;
  return 5;
}

