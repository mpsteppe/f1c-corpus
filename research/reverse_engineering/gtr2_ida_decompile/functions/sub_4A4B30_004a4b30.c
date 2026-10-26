_DWORD *__thiscall sub_4A4B30(int *this)
{
  if ( dword_B640C0 == 5 && *((_BYTE *)this + 284) )
    (*(void (__thiscall **)(int *, int))(*this + 36))(this, 1);
  else
    (*(void (__thiscall **)(int *, _DWORD))(*this + 36))(this, 0);
  if ( this[72] == 445 )
  {
    this[69] = 36 * *(_DWORD *)dword_B72314 + 11994324;
    if ( *(_DWORD *)dword_B72314 == 4 )
      (*(void (__thiscall **)(int *, int))(*this + 36))(this, 1);
  }
  (*(void (__thiscall **)(int *))(*this + 152))(this);
  return sub_490B30(this);
}
