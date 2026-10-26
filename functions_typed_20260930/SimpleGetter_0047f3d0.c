LPVOID *__thiscall SimpleGetter(LPVOID *this, char a2)
{
  Destructor(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

