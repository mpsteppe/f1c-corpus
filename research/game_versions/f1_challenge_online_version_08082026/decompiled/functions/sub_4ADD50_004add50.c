BOOL sub_4ADD50()
{
  const char *v0; // eax
  CHAR *v1; // edi
  int v2; // eax
  int v3; // ecx
  int v4; // edx
  CHAR NewFileName[253]; // [esp+8h] [ebp-200h] BYREF
  __int16 v7; // [esp+105h] [ebp-103h]
  char v8; // [esp+107h] [ebp-101h]
  CHAR ExistingFileName[253]; // [esp+108h] [ebp-100h] BYREF
  __int16 v10; // [esp+205h] [ebp-3h]
  char v11; // [esp+207h] [ebp-1h]

  NewFileName[0] = byte_5EA438[0];
  memset(&NewFileName[1], 0, 0xFCu);
  v7 = 0;
  v8 = 0;
  ExistingFileName[0] = byte_5EA438[0];
  memset(&ExistingFileName[1], 0, 0xFCu);
  v10 = 0;
  v11 = 0;
  v0 = (const char *)dword_5EC440;
  if ( !dword_5EC440 )
    v0 = byte_5EA438;
  sub_58815F(ExistingFileName, "%s%s", v0, (const char *)&dword_5C5E60);
  sub_4B0220(NewFileName, 238);
  v1 = &NewFileName[strlen(NewFileName) + 1];
  v2 = dword_5C5E64;
  v3 = dword_5C5E68;
  *(_DWORD *)--v1 = dword_5C5E60;
  v4 = dword_5C5E6C;
  *((_DWORD *)v1 + 1) = v2;
  LOWORD(v2) = word_5C5E70;
  *((_DWORD *)v1 + 2) = v3;
  *((_DWORD *)v1 + 3) = v4;
  *((_WORD *)v1 + 8) = v2;
  return CopyFileA(ExistingFileName, NewFileName, 0);
}
