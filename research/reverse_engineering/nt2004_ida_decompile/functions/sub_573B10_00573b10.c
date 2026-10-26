void __thiscall sub_573B10(void *this)
{
  if ( *((_BYTE *)this + 36) && CloseHandle(*((HANDLE *)this + 7)) )
    *((_DWORD *)this + 7) = 0;
  if ( *((_BYTE *)this + 20) )
  {
    if ( CloseHandle(*((HANDLE *)this + 3)) )
      *((_DWORD *)this + 3) = 0;
  }
}
