// f1c  0x004c9280  size=43
char __thiscall sub_4C9280(_DWORD *this, int a2)
{
  int v2; // eax
  bool v3; // zf
  char result; // al

  if ( a2 != this[7] )
    return 0;
  v2 = sub_4C9260(this);
  if ( !v2 )
    return 0;
  v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 28))(v2) == 2;
  result = 1;
  if ( v3 )
    return 0;
  return result;
}
