// f1c  0x005685b0  size=98
bool __thiscall sub_5685B0(int this)
{
  bool result; // al
  char v3; // [esp+Bh] [ebp-5h]

  result = 0;
  if ( strlen((const char *)this) >= 4 )
  {
    v3 = *(_BYTE *)(this + 3);
    if ( *(_BYTE *)this == 43 && *(_BYTE *)(this + 1) == 126 && sub_589BC6(*(char *)(this + 2)) && sub_589BC6(v3) )
      return 1;
  }
  return result;
}
