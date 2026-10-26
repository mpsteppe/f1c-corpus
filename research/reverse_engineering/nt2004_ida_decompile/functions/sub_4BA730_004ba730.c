char __stdcall sub_4BA730(char *Source, int a2, char a3)
{
  char Destination[256]; // [esp+0h] [ebp-100h] BYREF

  if ( !dword_7655CC || dword_75CBA8 != 2 && dword_75CBA8 != 6 && !byte_76617C )
    return 0;
  Destination[0] = 0;
  strncpy(Destination, Source, 0xFFu);
  Destination[255] = 0;
  if ( a3 )
    sub_4AEA10((_BYTE *)dword_7655CC, Destination, 0);
  if ( *(float *)&a2 > 0.0 )
    sub_4AEE60((_DWORD *)dword_7655CC, (int)Destination, a2);
  return 1;
}
