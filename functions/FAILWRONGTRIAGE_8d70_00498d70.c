_DWORD *__thiscall FAILWRONGTRIAGE_8d70(_DWORD *this, char a2)
{
  DualListDestruction(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
