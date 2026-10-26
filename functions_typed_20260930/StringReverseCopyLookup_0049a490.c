int __thiscall sub_49A490(_DWORD *this, const char *a2, int a3)
{
  CHAR SrcStr[256]; // [esp+4h] [ebp-100h] BYREF

  SrcStr[0] = 0;
  strcpy(SrcStr, a2);
  sub_589901(SrcStr);
  if ( HashTableSearch(this, SrcStr) )
    FunctionCallWrapper_a2e0(a3);
  else
    ResourceLookupOrCreate(this, SrcStr, a3);
  return 0;
}

