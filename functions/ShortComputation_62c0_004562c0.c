LPVOID *__thiscall ShortComputation_62c0(LPVOID *this, char a2)
{
  *this = &off_59EFCC;
  if ( this[1] )
    FreeWrapper_7bcf(this[1]);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
