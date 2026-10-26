char __thiscall sub_54D410(int this, int a2)
{
  int v2; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // esi
  int v9; // esi

  LOBYTE(v2) = a2;
  *(_DWORD *)(this + 8) = a2;
  switch ( a2 )
  {
    case 0:
      if ( *(_DWORD *)(this + 32) )
        sub_5DB5A0();
      v5 = *(_DWORD *)(this + 48);
      if ( v5 )
        *(_BYTE *)(v5 + 4) = 0;
      v6 = *(_DWORD *)(this + 36);
      if ( v6 )
        sub_5DB590(v6);
      v7 = *(_DWORD *)(this + 40);
      if ( v7 )
        sub_5DB590(v7);
      LOBYTE(v2) = *(_BYTE *)(this + 4);
      if ( !(_BYTE)v2 )
      {
        v8 = *(_DWORD *)(this + 208);
        if ( v8 )
          *(_BYTE *)(v8 + 4) = 1;
      }
      break;
    case 1:
      v4 = *(_DWORD *)(this + 32);
      if ( v4 )
        sub_5DB590(v4);
      LOBYTE(v2) = *(_BYTE *)(this + 4);
      if ( !(_BYTE)v2 )
      {
        v2 = *(_DWORD *)(this + 48);
        if ( v2 )
          *(_BYTE *)(v2 + 4) = 1;
      }
      goto LABEL_22;
    case 2:
    case 3:
      if ( *(_DWORD *)(this + 32) )
        sub_5DB5A0();
      v2 = *(_DWORD *)(this + 48);
      if ( v2 )
        *(_BYTE *)(v2 + 4) = 0;
LABEL_22:
      if ( *(_DWORD *)(this + 36) )
        LOBYTE(v2) = sub_5DB5A0();
      if ( *(_DWORD *)(this + 40) )
        LOBYTE(v2) = sub_5DB5A0();
      v9 = *(_DWORD *)(this + 208);
      if ( v9 )
        *(_BYTE *)(v9 + 4) = 0;
      break;
    default:
      return v2;
  }
  return v2;
}
