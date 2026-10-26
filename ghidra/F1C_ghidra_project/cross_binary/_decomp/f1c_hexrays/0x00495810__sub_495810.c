// f1c  0x00495810  size=123
int __stdcall sub_495810(CHAR *a1)
{
  CHAR *v1; // eax
  CHAR v3; // cl
  char v4; // al
  CHAR *v5; // edi
  CHAR SrcStr[80]; // [esp+0h] [ebp-50h] BYREF

  v1 = a1;
  if ( !a1 )
    return -1;
  do
  {
    v3 = *v1;
    v1[SrcStr - a1] = *v1;
    ++v1;
  }
  while ( v3 );
  sub_589901(SrcStr);
  if ( !sub_587C20(SrcStr, &dword_5CC79C) )
  {
    v4 = byte_5CC7A0;
    v5 = &SrcStr[strlen(SrcStr)];
    *(_DWORD *)v5 = dword_5CC79C;
    v5[4] = v4;
  }
  return sub_494DE0((int)SrcStr);
}
