unsigned int __thiscall SetCallToBox(F1CVehicle *this, unsigned int a2)
{
  unsigned int result; // eax

  result = a2;
  if ( a2 <= 1 )
    this->CallToBox = a2;
  return result;
}

