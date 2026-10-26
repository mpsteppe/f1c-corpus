char __thiscall sub_49D9C0(_DWORD *this, char a2)
{
  int v2; // eax
  _BYTE *v3; // ecx
  _DWORD *v4; // ecx
  bool v5; // zf
  int *v6; // ecx
  int v7; // eax
  BOOL v8; // edx

  v2 = sub_49D1E0(this);
  switch ( v2 )
  {
    case 0:
      LOBYTE(v2) = a2;
      if ( a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v3 + 44))(v3, 1);
      break;
    case 1:
      LOBYTE(v2) = a2;
      if ( !a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)v3 + 44))(v3, 0);
      break;
    case 2:
      LOBYTE(v2) = a2;
      if ( a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v3 + 44))(v3, 3);
      break;
    case 3:
      LOBYTE(v2) = a2;
      if ( !a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v3 + 44))(v3, 2);
      break;
    case 4:
      LOBYTE(v2) = sub_49D1D0(v3);
      if ( !(_BYTE)v2 )
      {
        v5 = !sub_49D9A0(v4);
        v7 = *v6;
        v8 = a2 != 0;
        if ( v5 )
          LOBYTE(v2) = (*(int (__stdcall **)(BOOL))(v7 + 44))(v8);
        else
          LOBYTE(v2) = (*(int (__stdcall **)(int))(v7 + 44))(v8 + 2);
      }
      break;
    default:
      return v2;
  }
  return v2;
}
