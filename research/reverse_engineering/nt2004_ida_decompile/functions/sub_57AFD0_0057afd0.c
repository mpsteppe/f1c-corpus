bool __thiscall sub_57AFD0(int this)
{
  bool result; // al
  char v3; // [esp+Bh] [ebp-5h]

  result = 0;
  if ( strlen((const char *)this) >= 4 )
  {
    v3 = *(_BYTE *)(this + 3);
    if ( *(_BYTE *)this == 43 && *(_BYTE *)(this + 1) == 126 && isxdigit(*(char *)(this + 2)) && isxdigit(v3) )
      return 1;
  }
  return result;
}
