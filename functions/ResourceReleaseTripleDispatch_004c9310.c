int __thiscall sub_4C9310(_DWORD *this)
{
  int v2; // ecx
  int result; // eax
  int v4; // ecx
  int v5; // ecx

  v2 = this[8];
  if ( v2 )
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(v2);
  v4 = this[9];
  if ( v4 )
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 8))(v4);
  v5 = this[10];
  if ( v5 )
    return (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 8))(v5);
  return result;
}
