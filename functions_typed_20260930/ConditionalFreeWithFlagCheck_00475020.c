void *__thiscall ConditionalFreeWithFlagCheck(void *this, char a2)
{
  VTableSetterWithSubCall();
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

