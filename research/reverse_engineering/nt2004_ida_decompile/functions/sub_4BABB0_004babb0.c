int sub_4BABB0()
{
  const char *v0; // eax
  char Buffer[253]; // [esp+0h] [ebp-100h] BYREF
  __int16 v3; // [esp+FDh] [ebp-3h]
  char v4; // [esp+FFh] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v3 = 0;
  v4 = 0;
  v0 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v0 = &byte_629120;
  sprintf(Buffer, "%s%s", v0, aIngameMas);
  sub_506C20((int)aFtch20blk, -1, (int)aPopupquit0000T, 0.5, 0.5, 0.0, 0.60000002, 0.2, 8, (int)Buffer);
  return sub_506C20((int)aFtch20blk, -1, (int)aPopuprestartTg, 0.5, 0.5, 0.0, 0.60000002, 0.2, 8, (int)Buffer);
}
