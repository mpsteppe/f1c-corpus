char __thiscall sub_4F7010(int this, char a2)
{
  int v3; // eax
  int i; // esi
  int v5; // ecx
  int j; // esi
  int v7; // ecx

  if ( *(_BYTE *)(this + 176) )
  {
    v3 = *(_DWORD *)(this + 1684);
    if ( v3 )
    {
      for ( i = 0; i < 180; i += 4 )
      {
        v5 = *(_DWORD *)(i + *(_DWORD *)(this + 1684));
        if ( v5 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(v5);
      }
      LOBYTE(v3) = a2;
      *(_BYTE *)(this + 176) = a2;
    }
    else
    {
      *(_BYTE *)(this + 176) = a2;
    }
  }
  else
  {
    v3 = *(_DWORD *)(this + 1752);
    if ( v3 )
    {
      for ( j = 0; j < 180; j += 4 )
      {
        v7 = *(_DWORD *)(j + *(_DWORD *)(this + 1752));
        if ( v7 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(v7);
      }
      LOBYTE(v3) = a2;
      *(_BYTE *)(this + 176) = a2;
    }
    else
    {
      *(_BYTE *)(this + 176) = a2;
    }
  }
  return v3;
}
