int __thiscall sub_4A5960(_DWORD *this)
{
  this[67] = dbl_903EC8 == 1.0;
  if ( *(_DWORD *)dword_B72314 == 5 )
    (*(void (__stdcall **)(_DWORD))(*this + 40))(0);
  else
    (*(void (__stdcall **)(int))(*this + 40))(1);
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, this[67]);
  return 0;
}
