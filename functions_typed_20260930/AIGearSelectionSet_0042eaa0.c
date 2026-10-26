int __thiscall AIGearSelectionSet(_BYTE *this, int a2, int a3, int a4)
{
  int v5; // eax
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int result; // eax
  int v11; // [esp+14h] [ebp+4h]

  v5 = (a3 + 11 * a2) << 6;
  v7 = (int)&this[v5 + 176];
  v11 = *(_DWORD *)&this[v5 + 196];
  if ( a4 > 0 )
  {
    v8 = *(_DWORD *)&this[v5 + 192];
    if ( a4 < v8 )
      *(_DWORD *)(v7 + 20) = a4;
    else
      *(_DWORD *)(v7 + 20) = v8 - 1;
  }
  else
  {
    *(_DWORD *)&this[v5 + 196] = 0;
  }
  if ( this[6565] )
  {
    TrackConfig((int)this, a2, a3);
    if ( a2 )
    {
      v9 = 0;
      if ( a2 != 1 )
      {
        LOBYTE(v9) = a2 == 2;
        v9 += 2;
      }
    }
    else
    {
      v9 = 1;
    }
    EventTriggerOnStateChange(this, v7, (int)&this[704 * v9 + 176 + 64 * a3]);
  }
  TrackConfig((int)this, a2, a3);
  result = v11;
  if ( *(_DWORD *)(v7 + 20) != v11 )
  {
    this[6564] = 1;
    *this = 1;
  }
  return result;
}

