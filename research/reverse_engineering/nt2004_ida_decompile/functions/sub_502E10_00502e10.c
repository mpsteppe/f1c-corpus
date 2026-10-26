int sub_502E10()
{
  const char *v0; // eax
  char Buffer[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v3; // [esp+105h] [ebp-3h]
  char v4; // [esp+107h] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v3 = 0;
  v4 = 0;
  v0 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v0 = &byte_629120;
  sprintf(Buffer, "%s%s", v0, aIngameMas);
  return sub_506880(-1, off_612BFC, 0.0, 0.0, 0.0, 0.63999999, 0.20999999, 0, (int)Buffer);
}
