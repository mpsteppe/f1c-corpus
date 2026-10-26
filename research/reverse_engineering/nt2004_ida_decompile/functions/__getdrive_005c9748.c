int __cdecl _getdrive()
{
  int v0; // esi
  CHAR Buffer[260]; // [esp+4h] [ebp-104h] BYREF

  v0 = 0;
  if ( GetCurrentDirectoryA(0x104u, Buffer) && Buffer[1] == 58 )
    return toupper((unsigned __int8)Buffer[0]) - 64;
  return v0;
}
