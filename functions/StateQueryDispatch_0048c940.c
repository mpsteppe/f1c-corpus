int __thiscall StateQueryDispatch(_BYTE *this)
{
  _DWORD *v2; // ecx

  if ( ByteFieldGetterAt100(this) )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)this + 64))(5);
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 172))(this);
    return 0;
  }
  else
  {
    if ( ShortComputation_6720(v2) == 5 )
      (*(void (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 64))(this, 0);
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 172))(this);
    return 0;
  }
}
