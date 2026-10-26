int __thiscall sub_6A7E52(_DWORD *this)
{
  unsigned int i; // esi
  _DWORD *v2; // eax
  int v3; // edx
  int v4; // edx

  for ( i = 0; i < this[2]; ++i )
  {
    v2 = *(_DWORD **)(this[5] + 4 * i);
    v3 = v2[14];
    if ( v3 != -1 )
    {
      v4 = 4 * v3;
      v2[3] = *(_DWORD *)(*(_DWORD *)(this[5] + v4) + 12);
      v2[4] = *(_DWORD *)(*(_DWORD *)(this[5] + v4) + 16);
    }
  }
  return 0;
}
