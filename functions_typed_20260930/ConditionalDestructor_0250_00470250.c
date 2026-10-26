LPVOID *__thiscall ConditionalDestructor_0250(LPVOID *this, char a2)
{
  VTableSetterSubCall_b4e0(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

