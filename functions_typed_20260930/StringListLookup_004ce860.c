int __thiscall sub_4CE860(int *this, const char *a2)
{
  int v3; // esi
  int i; // edi
  CHAR SrcStr[64]; // [esp+Ch] [ebp-40h] BYREF

  strcpy(SrcStr, a2);
  sub_589901(SrcStr);
  v3 = 0;
  if ( this[2] <= 0 )
    return -1;
  for ( i = 0; !StringTableLookup((const char **)(i + this[3]), (int)SrcStr); i += 108 )
  {
    if ( ++v3 >= this[2] )
      return -1;
  }
  return v3;
}

