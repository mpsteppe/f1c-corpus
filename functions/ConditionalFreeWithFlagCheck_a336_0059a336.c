_DWORD *__thiscall sub_59A336(_DWORD *this, char a2)
{
  SetLocaleVTableDtor(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
