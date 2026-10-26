int __thiscall sub_47B3D0(_DWORD *this)
{
  if ( *(_DWORD *)dword_7689CC == this[67] )
    return (*(int (__thiscall **)(_DWORD *, int))(*this + 40))(this, 1);
  else
    return (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 40))(this, 0);
}
