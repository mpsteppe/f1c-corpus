bool __thiscall sub_4B9FB0(_DWORD *this)
{
  int v1; // eax
  bool result; // al

  result = 1;
  if ( *this == 2 )
  {
    v1 = sub_4B9E30(this + 2);
    if ( v1 < 6 || v1 > 8 )
      return 0;
  }
  return result;
}
