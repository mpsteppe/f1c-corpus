LPVOID *__thiscall sub_404F70(LPVOID *this, char a2)
{
  if ( *this )
    FreeWrapper_7bcf(*this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
