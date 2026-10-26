void __thiscall ListSelectionClamp(_BYTE *this, int a2, int a3)
{
  int v4; // ebx
  int v5; // esi
  int v6; // ecx

  v4 = *(_DWORD *)&this[64 * a2 + 3012];
  v5 = (int)&this[64 * a2 + 2992];
  if ( a3 > 0 )
  {
    v6 = *(_DWORD *)&this[64 * a2 + 3008];
    if ( a3 < v6 )
      *(_DWORD *)(v5 + 20) = a3;
    else
      *(_DWORD *)(v5 + 20) = v6 - 1;
  }
  else
  {
    *(_DWORD *)&this[64 * a2 + 3012] = 0;
  }
  TrackConfig((int)this, 4, a2);
  if ( *(_DWORD *)(v5 + 20) != v4 )
  {
    this[6564] = 1;
    *this = 1;
  }
}
