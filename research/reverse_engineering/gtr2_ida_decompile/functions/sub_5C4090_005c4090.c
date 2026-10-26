void __thiscall sub_5C4090(_DWORD *this, int a2, float a3)
{
  int v3; // ecx
  int v4; // esi

  v3 = this[9];
  if ( v3 )
  {
    v4 = v3;
    if ( *(_DWORD *)(v3 + 8) == a2 )
    {
LABEL_5:
      sub_5C2530(*(_DWORD *)(v4 + 8), 0.0, a3);
      if ( a3 > 0.0 )
        *(_BYTE *)(*(_DWORD *)(v4 + 8) + 81) = 1;
    }
    else
    {
      while ( 1 )
      {
        v4 = *(_DWORD *)(v4 + 16);
        if ( !v4 )
          break;
        if ( *(_DWORD *)(v4 + 8) == a2 )
          goto LABEL_5;
      }
    }
  }
}
