char __thiscall sub_40BCD0(_DWORD *this, int a2, char a3)
{
  int v4; // eax

  if ( !a2 )
    return 0;
  v4 = ShortComputation_b6c0(this, a2);
  if ( v4 < 0 )
    return 0;
  ShortComputation_b6f0(this, v4);
  if ( a3 )
    (*(void (__thiscall **)(_DWORD *))(*this + 16))(this);
  return 1;
}

