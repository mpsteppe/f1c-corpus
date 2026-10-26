char __thiscall ConditionalStateMachineDispatch(_DWORD *this, char a2)
{
  int v2; // eax
  _BYTE *v3; // ecx
  _DWORD *v4; // ecx
  bool v5; // zf
  int *v6; // ecx
  int v7; // eax

  v2 = ShortComputation_6720(this);
  switch ( v2 )
  {
    case 0:
      LOBYTE(v2) = a2;
      if ( a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v3 + 64))(v3, 2);
      break;
    case 1:
      LOBYTE(v2) = a2;
      if ( a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v3 + 64))(v3, 3);
      break;
    case 2:
      LOBYTE(v2) = a2;
      if ( !a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)v3 + 64))(v3, 0);
      break;
    case 3:
      LOBYTE(v2) = a2;
      if ( !a2 )
        LOBYTE(v2) = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v3 + 64))(v3, 1);
      break;
    case 4:
      LOBYTE(v2) = ByteFieldGetterAt100(v3);
      if ( !(_BYTE)v2 )
      {
        v5 = !ShortComputation_7720(v4);
        v7 = *v6;
        if ( v5 )
          LOBYTE(v2) = (*(int (__stdcall **)(int))(v7 + 64))(a2 != 0 ? 2 : 0);
        else
          LOBYTE(v2) = (*(int (__stdcall **)(int))(v7 + 64))(2 * (a2 != 0) + 1);
      }
      break;
    default:
      return v2;
  }
  return v2;
}

