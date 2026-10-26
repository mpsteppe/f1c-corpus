int sub_48FBA0()
{
  int v0; // esi
  char ArgList[77]; // [esp+8h] [ebp-A0h] BYREF
  __int16 v3; // [esp+55h] [ebp-53h]
  char v4; // [esp+57h] [ebp-51h]
  char Buffer[80]; // [esp+58h] [ebp-50h] BYREF

  v0 = dword_75AAC4;
  if ( *(_DWORD *)(dword_75AAC4 + 16584) == -1 )
  {
    sub_49EC60(&byte_629120);
  }
  else
  {
    ArgList[0] = byte_629120;
    memset(&ArgList[1], 0, 0x4Cu);
    v3 = 0;
    Buffer[0] = 0;
    v4 = 0;
    sub_4EDE00(ArgList, 79);
    sub_405480(Buffer, 0x4Fu, "#%s - %s", ArgList, (const char *)(v0 + 24772));
    sub_49EC60(Buffer);
  }
  return 0;
}
