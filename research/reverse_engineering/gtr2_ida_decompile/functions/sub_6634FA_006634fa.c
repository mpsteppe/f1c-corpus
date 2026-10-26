int __thiscall sub_6634FA(_DWORD *this, int a2, unsigned int a3)
{
  int v3; // edx
  int v4; // ecx
  unsigned int v5; // eax
  int v6; // eax

  v3 = 0;
  if ( !a3 )
    return 1;
  v4 = this[2];
  while ( 1 )
  {
    v5 = *(_DWORD *)(a2 + 4 * v3);
    v6 = v5 >= *(_DWORD *)(v4 + 8) ? 0 : *(_DWORD *)(*(_DWORD *)(v4 + 20) + 4 * v5);
    if ( !v6 || !*(_DWORD *)(v6 + 104) )
      break;
    if ( ++v3 >= a3 )
      return 1;
  }
  return 0;
}
