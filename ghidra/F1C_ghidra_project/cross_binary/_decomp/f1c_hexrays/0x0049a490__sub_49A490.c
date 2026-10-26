// f1c  0x0049a490  size=130
int __thiscall sub_49A490(_DWORD *this, const char *a2, int a3)
{
  CHAR SrcStr[256]; // [esp+4h] [ebp-100h] BYREF

  SrcStr[0] = 0;
  strcpy(SrcStr, a2);
  sub_589901(SrcStr);
  if ( sub_49A360(this, SrcStr) )
    sub_49A2E0(a3);
  else
    sub_49A3B0(this, SrcStr, a3);
  return 0;
}
