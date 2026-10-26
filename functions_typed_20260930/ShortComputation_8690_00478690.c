_DWORD *__thiscall ShortComputation_8690(_DWORD *this)
{
  if ( this[78] )
  {
    (*(void (__thiscall **)(_DWORD *, int))(*this + 60))(this, 1);
    return this + 70;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 60))(this, 0);
    return 0;
  }
}

