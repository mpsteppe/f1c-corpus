int __thiscall sub_5BE270(_DWORD *this, int a2)
{
  int v3; // ebp
  int v4; // edi
  int v5; // esi

  v3 = this[3];
  v4 = 0;
  if ( v3 <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = *(_DWORD *)(this[5] + 4 * v4);
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 4))(v5) == a2 )
      break;
    if ( ++v4 >= v3 )
      return 0;
  }
  return v5;
}
