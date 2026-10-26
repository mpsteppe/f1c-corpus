_BYTE *__thiscall ScreenMenuNavigationController(_DWORD *this)
{
  _BYTE *result; // eax
  char *v3; // eax

  result = (_BYTE *)this[58];
  if ( result )
  {
    if ( dword_7D0410 == 3 || dword_7D0410 == 5 )
    {
      if ( *result )
      {
        this[56] = 0;
        v3 = UIListIndexedAccessor(this, 1);
      }
      else
      {
        this[56] = 1;
        v3 = UIListIndexedAccessor(this, 0);
      }
    }
    else
    {
      this[56] = 2;
      v3 = UIListIndexedAccessor(this, 2);
    }
    StringCopyWithBufferRealloc((int)(this + 59), v3);
    return (_BYTE *)(*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 64))(this, this[56]);
  }
  return result;
}

