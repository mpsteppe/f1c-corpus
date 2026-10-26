int __thiscall sub_49E2E0(_DWORD *this)
{
  int v2; // eax

  v2 = sub_49D1E0(this) - 2;
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      (*(void (__stdcall **)(int))(*this + 44))(1);
      this[66] = 0;
      return 0;
    }
  }
  else
  {
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
  }
  this[66] = 0;
  return 0;
}
