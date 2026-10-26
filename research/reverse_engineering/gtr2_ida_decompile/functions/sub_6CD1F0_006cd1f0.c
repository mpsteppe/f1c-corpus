int __thiscall sub_6CD1F0(_DWORD *this, int a2, int a3)
{
  int v4; // esi
  _DWORD *v5; // eax
  int v6; // edi
  int result; // eax

  v4 = a2;
  while ( 1 )
  {
    while ( 1 )
    {
      v5 = *(_DWORD **)(*(_DWORD *)(this[1] + 20) + 4 * a3);
      if ( v5[14] == -1 )
        break;
      a3 = v5[14];
    }
    v5[12] = -1;
    v6 = v5[1];
    v5[29] = v4;
    if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this[1] + 16) + 4 * v6) + 4) & 0x10) == 0 )
    {
      if ( this[4] )
      {
        *(_DWORD *)(this[4] + 4 * (*(_DWORD *)(this[2] + 4 * v4) + *(_DWORD *)(this[3] + 4 * v4))) = a3;
        v4 = a2;
      }
      ++*(_DWORD *)(this[2] + 4 * v4);
    }
    result = v5[2];
    if ( result == -1 )
      break;
    a3 = result;
  }
  return result;
}
