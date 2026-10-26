LPVOID *__thiscall Destructor_7f10(LPVOID *this, char a2)
{
  VTableSetCleanup(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
