struct hostent *sub_5BDC60()
{
  char name[253]; // [esp+4h] [ebp-100h] BYREF
  __int16 v2; // [esp+101h] [ebp-3h]
  char v3; // [esp+103h] [ebp-1h]

  name[0] = byte_629120;
  memset(&name[1], 0, 0xFCu);
  v2 = 0;
  v3 = 0;
  gethostname(name, 256);
  return gethostbyname(name);
}
