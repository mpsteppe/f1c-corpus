_DWORD *__thiscall sub_583150(_DWORD *this, char a2)
{
  if ( (a2 & 2) != 0 )
  {
    NTimeCallbackLoopWithSEH(this, 40, *(this - 1), sub_57AEF0);
    if ( (a2 & 1) != 0 )
      FreeWrapper_7bcf(this - 1);
    return this - 1;
  }
  else
  {
    sub_57AEF0(this);
    if ( (a2 & 1) != 0 )
      FreeWrapper_7bcf(this);
    return this;
  }
}

