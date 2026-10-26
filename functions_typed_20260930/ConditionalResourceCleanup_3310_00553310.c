void __thiscall sub_553310(void *this)
{
  if ( (*(_DWORD *)this & 1) != 0 || (*(_DWORD *)this & 2) != 0 )
  {
    if ( *((_DWORD *)this + 6) )
      FreeWrapper_7bcf(*((LPVOID *)this + 6));
    *((_DWORD *)this + 6) = 0;
  }
  if ( *((_DWORD *)this + 5) )
  {
    ObjectResetWithVirtualRelease(dword_8B78A0, *((_DWORD *)this + 5));
    if ( *((_DWORD *)this + 5) )
      FreeWrapper_7bcf(*((LPVOID *)this + 5));
    *((_DWORD *)this + 5) = 0;
  }
  EmptyStub_0170();
}

