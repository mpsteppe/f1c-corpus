int __cdecl genfname(unsigned __int8 *String)
{
  char *v1; // esi
  unsigned int v2; // eax
  char *v4; // eax
  char Buffer[4]; // [esp+4h] [ebp-4h] BYREF

  v1 = (char *)(_mbsrchr(String, 0x2Eu) + 1);
  v2 = strtoul(v1, 0, 32) + 1;
  if ( v2 >= 0x7FFF )
    return -1;
  v4 = _ultoa(v2, Buffer, 32);
  strcpy(v1, v4);
  return 0;
}
