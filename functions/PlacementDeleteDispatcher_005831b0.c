_DWORD *__thiscall sub_5831B0(_DWORD *this, char a2)
{
  if ( (a2 & 2) != 0 )
  {
    NTimeCallbackLoopWithSEH(this, 308, *(this - 1), SingleVTablePointerSet);
    if ( (a2 & 1) != 0 )
      FreeWrapper_7bcf(this - 1);
    return this - 1;
  }
  else
  {
    SingleVTablePointerSet(this);
    if ( (a2 & 1) != 0 )
      FreeWrapper_7bcf(this);
    return this;
  }
}
