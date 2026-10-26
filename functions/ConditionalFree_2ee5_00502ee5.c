LPVOID *__thiscall sub_502EE5(LPVOID *this, char a2)
{
  if ( (a2 & 2) != 0 )
  {
    NTimeCallbackLoopWithSEH(this, 12, *(this - 1), FreeWrapper);
    if ( (a2 & 1) != 0 )
      FreeWrapper_7bcf(this - 1);
    return this - 1;
  }
  else
  {
    FreeWrapper_7bcf(*this);
    if ( (a2 & 1) != 0 )
      FreeWrapper_7bcf(this);
    return this;
  }
}
