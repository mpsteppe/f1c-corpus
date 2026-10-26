char __thiscall sub_4CD800(_DWORD *this, char a2)
{
  int v2; // eax

  v2 = this[33];
  switch ( v2 )
  {
    case 0:
      LOBYTE(v2) = a2;
      if ( a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, 2);
      break;
    case 1:
      LOBYTE(v2) = a2;
      if ( a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, 3);
      break;
    case 2:
      LOBYTE(v2) = a2;
      if ( !a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
      break;
    case 3:
      LOBYTE(v2) = a2;
      if ( !a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
      break;
    case 4:
      LOBYTE(v2) = *((_BYTE *)this + 100);
      if ( !(_BYTE)v2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, a2 != 0 ? 2 : 0);
      break;
    default:
      return v2;
  }
  return v2;
}
