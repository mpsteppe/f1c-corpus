char __thiscall sub_4F0D80(_DWORD *this)
{
  int v1; // ecx
  bool v2; // zf
  char result; // al

  v1 = this[this[7] + 8];
  if ( !v1 )
    return 0;
  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 28))(v1) == 2;
  result = 1;
  if ( v2 )
    return 0;
  return result;
}
