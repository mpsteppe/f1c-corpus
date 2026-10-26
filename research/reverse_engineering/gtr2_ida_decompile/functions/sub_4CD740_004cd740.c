char __thiscall sub_4CD740(_DWORD *this, char a2)
{
  int v2; // eax
  bool v3; // zf
  int *v4; // ecx
  int v5; // eax
  BOOL v6; // edx

  v2 = this[33];
  switch ( v2 )
  {
    case 0:
      LOBYTE(v2) = a2;
      if ( a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
      break;
    case 1:
      LOBYTE(v2) = a2;
      if ( !a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
      break;
    case 2:
      LOBYTE(v2) = a2;
      if ( a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, 3);
      break;
    case 3:
      LOBYTE(v2) = a2;
      if ( !a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, 2);
      break;
    case 4:
      LOBYTE(v2) = *((_BYTE *)this + 100);
      if ( !(_BYTE)v2 )
      {
        v3 = (unsigned __int8)sub_4CD720() == 0;
        v5 = *v4;
        v6 = a2 != 0;
        if ( v3 )
          LOBYTE(v2) = (*(int (__stdcall **)(BOOL))(v5 + 44))(v6);
        else
          LOBYTE(v2) = (*(int (__stdcall **)(int))(v5 + 44))(v6 + 2);
      }
      break;
    default:
      return v2;
  }
  return v2;
}
