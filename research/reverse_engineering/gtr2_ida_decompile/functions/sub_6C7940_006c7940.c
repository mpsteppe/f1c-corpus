int __thiscall sub_6C7940(_DWORD *this, int a2)
{
  int v3; // ecx
  int result; // eax

  v3 = this[64];
  this[87] = 0;
  result = sub_6C73E9((int)this, 0x80000, 917504, *(char **)(v3 + 8), 0x80000, 0, a2);
  if ( result >= 0 )
    return sub_6BFA68(this);
  return result;
}
