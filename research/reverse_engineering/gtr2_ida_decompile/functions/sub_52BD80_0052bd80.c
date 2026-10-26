int __thiscall sub_52BD80(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // ecx

  v3 = this[30];
  if ( v3 >= 4 )
  {
    this[2 * v3 + 30] += *(char *)(a2 + 8);
  }
  else
  {
    this[2 * v3 + 31] = 3;
    this[2 * this[30]++ + 32] = *(char *)(a2 + 8);
  }
  v4 = *this + 14824;
  if ( *(_DWORD *)(v4 + 104) != 2 )
  {
    *(_DWORD *)(v4 + 104) = 2;
    *(_DWORD *)(v4 + 108) = 1;
    *(_DWORD *)(v4 + 112) = 1;
  }
  if ( *(_DWORD *)(v4 + 108) )
    return sub_4FBE60((_DWORD *)v4, *(_DWORD **)(v4 + 16));
  else
    return sub_4FBE60((_DWORD *)v4, *(_DWORD **)(v4 + 12));
}
