bool __thiscall sub_617750(int this)
{
  bool result; // al
  char v2; // [esp+Bh] [ebp-5h]

  result = 0;
  if ( strlen((const char *)this) >= 4 )
  {
    v2 = *(_BYTE *)(this + 3);
    if ( *(_BYTE *)this == 43 && *(_BYTE *)(this + 1) == 126 && isxdigit(*(char *)(this + 2)) && isxdigit(v2) )
      return 1;
  }
  return result;
}
