char __thiscall sub_5BC3E0(_DWORD *this)
{
  int v2; // ebx
  int v3; // esi
  int v4; // ecx

  v2 = this[111];
  v3 = 0;
  if ( v2 <= 0 )
    return 0;
  while ( 1 )
  {
    v4 = *(_DWORD *)(this[113] + 4 * v3);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 24))(v4) )
      break;
    if ( ++v3 >= v2 )
      return 0;
  }
  return 1;
}
