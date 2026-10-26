char __thiscall sub_487260(_DWORD *this, char a2)
{
  int v2; // eax
  _BYTE *v3; // ecx
  bool v4; // zf
  int *v5; // ecx
  int v6; // eax
  BOOL v7; // edx

  v2 = ShortComputation_6720(this);
  switch ( v2 )
  {
    case 0:
      LOBYTE(v2) = a2;
      if ( a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v3 + 64))(v3, 1);
      break;
    case 1:
      LOBYTE(v2) = a2;
      if ( !a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)v3 + 64))(v3, 0);
      break;
    case 2:
      LOBYTE(v2) = a2;
      if ( a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v3 + 64))(v3, 3);
      break;
    case 3:
      LOBYTE(v2) = a2;
      if ( !a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v3 + 64))(v3, 2);
      break;
    case 4:
      LOBYTE(v2) = ByteFieldGetterAt100(v3);
      if ( !(_BYTE)v2 )
      {
        v4 = (unsigned __int8)RangeCheck() == 0;
        v6 = *v5;
        v7 = a2 != 0;
        if ( v4 )
          LOBYTE(v2) = (*(int (__stdcall **)(BOOL))(v6 + 64))(v7);
        else
          LOBYTE(v2) = (*(int (__stdcall **)(int))(v6 + 64))(v7 + 2);
      }
      break;
    default:
      return v2;
  }
  return v2;
}

