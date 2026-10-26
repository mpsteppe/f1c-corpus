_DWORD *__thiscall sub_525CA0(int this)
{
  int i; // edi
  _DWORD *result; // eax
  int j; // edi

  if ( *(_DWORD *)(this + 1728) )
  {
    for ( i = 0; i < 180; i += 4 )
      sub_525B30((_DWORD *)(i + *(_DWORD *)(this + 1728)));
    sub_5BE8AE();
    sub_524520((_DWORD *)(this + 1664));
  }
  result = *(_DWORD **)(this + 1796);
  if ( result )
  {
    for ( j = 0; j < 180; j += 4 )
      sub_525B30((_DWORD *)(j + *(_DWORD *)(this + 1796)));
    sub_5BE8AE();
    result = sub_524520((_DWORD *)(this + 1732));
  }
  *(_BYTE *)(this + 4) = 0;
  return result;
}
