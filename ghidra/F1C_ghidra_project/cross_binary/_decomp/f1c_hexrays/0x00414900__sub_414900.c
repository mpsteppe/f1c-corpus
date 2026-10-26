// f1c  0x00414900  size=149
int __fastcall sub_414900(int a1, int a2)
{
  char v3; // dl
  CHAR *v4; // edi
  CHAR FileName[256]; // [esp+8h] [ebp-100h] BYREF

  if ( !a1 )
    return 1;
  sub_587DD0(FileName, a1, 250);
  v3 = byte_5BE86C;
  FileName[250] = 0;
  v4 = &FileName[strlen(FileName)];
  *(_DWORD *)v4 = dword_5BE868;
  v4[4] = v3;
  if ( sub_58BA36(FileName, 128) == -1 )
    return 1;
  sub_566650(FileName);
  *(_DWORD *)(a2 + 8) = -1;
  *(_DWORD *)(a2 + 12) = -1;
  *(_BYTE *)(a2 + 16) = 0;
  return 0;
}
