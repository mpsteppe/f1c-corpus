_DWORD *__thiscall sub_5E8320(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  v2 = a2;
  if ( a2 == 99 )
    v2 = this[63];
  v3 = v2 - 1;
  if ( !v3 )
    return this + 68;
  v4 = v3 - 1;
  if ( !v4 )
    return this + 135;
  if ( v4 == 1 )
    return this + 202;
  return 0;
}
