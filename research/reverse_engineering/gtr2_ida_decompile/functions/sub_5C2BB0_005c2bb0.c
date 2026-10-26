int __thiscall sub_5C2BB0(_DWORD *this, int a2, int a3)
{
  int v4; // ebx
  int v5; // ebp
  int v6; // esi
  int v7; // ecx

  v4 = this[16];
  v5 = 0;
  v6 = 0;
  if ( v4 <= 0 )
    return -1;
  while ( 1 )
  {
    v7 = *(_DWORD *)(this[18] + 4 * v6);
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 4))(v7) == a2 )
      break;
LABEL_5:
    if ( ++v6 >= v4 )
      return -1;
  }
  if ( a3 != v5 )
  {
    ++v5;
    goto LABEL_5;
  }
  return v6;
}
