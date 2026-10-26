char __thiscall sub_4ECE00(_DWORD *this, int a2)
{
  int v3; // ecx
  _DWORD *v4; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  _DWORD *v8; // eax

  v3 = this[24];
  if ( v3 )
  {
    v4 = *(_DWORD **)(v3 + 84);
    *(_DWORD *)(v3 + 92) = v4;
    if ( v4 )
    {
      if ( *v4 )
      {
        do
        {
          sub_578600(a2);
          v5 = this[24];
          v6 = *(_DWORD *)(v5 + 92);
          v7 = v5 + 84;
          if ( v6 )
            *(_DWORD *)(v7 + 8) = *(_DWORD *)(v6 + 4);
          v8 = *(_DWORD **)(v7 + 8);
        }
        while ( v8 && *v8 );
      }
    }
  }
  return 0;
}
