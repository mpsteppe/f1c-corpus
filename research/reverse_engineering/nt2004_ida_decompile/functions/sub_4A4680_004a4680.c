bool __thiscall sub_4A4680(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  int v4; // eax
  bool result; // al

  v3 = this[3];
  result = 0;
  if ( a2 >= v3 && a2 <= v3 + this[1] )
  {
    v4 = this[4];
    if ( a3 >= v4 && a3 <= v4 + this[2] )
      return 1;
  }
  return result;
}
