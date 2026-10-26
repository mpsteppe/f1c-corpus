signed int __thiscall sub_5E8D90(_DWORD *this, int a2, const char *a3)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  signed int result; // eax

  v3 = a2;
  if ( a2 == 99 )
    v3 = this[63];
  v4 = v3 - 1;
  if ( !v4 )
    return sub_5D8EF0((int)(this + 68), a3, strlen(a3));
  v5 = v4 - 1;
  if ( !v5 )
    return sub_5D8EF0((int)(this + 135), a3, strlen(a3));
  result = v5 - 1;
  if ( !result )
    return sub_5D8EF0((int)(this + 202), a3, strlen(a3));
  return result;
}
