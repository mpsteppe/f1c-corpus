void *__thiscall SubCallConditionalFree(void *this, char a2)
{
  VTableSetInitCall();
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
