int sub_4CA8D0()
{
  char *v0; // edi
  int v1; // eax
  char v2; // cl
  char Path[253]; // [esp+4h] [ebp-100h] BYREF
  __int16 v5; // [esp+101h] [ebp-3h]
  char v6; // [esp+103h] [ebp-1h]

  Path[0] = byte_629120;
  memset(&Path[1], 0, 0xFCu);
  v5 = 0;
  v6 = 0;
  sub_4CD5B0(Path, 255);
  v0 = &Path[strlen(Path) + 1];
  v1 = dword_5FE15C;
  v2 = byte_5FE160;
  *(_DWORD *)--v0 = dword_5FE158;
  *((_DWORD *)v0 + 1) = v1;
  v0[8] = v2;
  return _mkdir(Path);
}
