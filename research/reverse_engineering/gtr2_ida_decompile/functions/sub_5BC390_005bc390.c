char __thiscall sub_5BC390(_DWORD *this, int a2)
{
  int v3; // ebx
  int v4; // esi
  int v5; // ecx

  v3 = this[111];
  v4 = 0;
  if ( v3 <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = *(_DWORD *)(this[113] + 4 * v4);
    if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v5 + 16))(v5, a2) )
      break;
    if ( ++v4 >= v3 )
      return 0;
  }
  return 1;
}
