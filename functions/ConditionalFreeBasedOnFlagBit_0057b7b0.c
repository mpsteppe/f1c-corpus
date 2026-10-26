_DWORD *__thiscall ConditionalFreeBasedOnFlagBit(_DWORD *this, char a2)
{
  VTablePointerInit(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
