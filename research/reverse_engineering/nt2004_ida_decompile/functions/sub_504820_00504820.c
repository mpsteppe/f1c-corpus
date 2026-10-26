int __stdcall sub_504820(int a1, int a2)
{
  int v2; // ebx
  int v3; // ebp
  const char *v4; // eax
  int v6; // [esp+10h] [ebp-108h]
  int v7; // [esp+14h] [ebp-104h]
  char Buffer[253]; // [esp+18h] [ebp-100h] BYREF
  __int16 v9; // [esp+115h] [ebp-3h]
  char v10; // [esp+117h] [ebp-1h]

  v2 = (__int64)(sub_501870() * ((double)a1 + 256.0));
  v3 = (__int64)(sub_501880() * ((double)a2 + 256.0 + 10.0));
  v6 = (__int64)(sub_501870() * 256.0);
  v7 = (__int64)(sub_501880() * (256.0 * 0.2));
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v9 = 0;
  v10 = 0;
  v4 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v4 = &byte_629120;
  sprintf(Buffer, "%s%s", v4, aIngameMas);
  return sub_506BD0(aFttr32wht, -1, aMph01Tga, v2, v3, 1, v6, v7, 0, Buffer);
}
