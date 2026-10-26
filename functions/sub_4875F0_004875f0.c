int __thiscall sub_4875F0(_DWORD *this)
{
  int v2; // eax

  v2 = ShortComputation_6720(this) - 2;
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      (*(void (__stdcall **)(int))(*this + 64))(1);
      this[55] = 0;
      return 0;
    }
  }
  else
  {
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 64))(this, 0);
  }
  this[55] = 0;
  return 0;
}
