int __thiscall sub_47ED80(int this)
{
  int v2; // eax
  int v3; // ebp
  char *v4; // eax
  CHAR *v5; // eax
  CHAR *v6; // eax
  char *v7; // esi
  bool v8; // zf
  CHAR *v9; // eax
  FILE *v10; // eax
  char *v11; // ecx
  const char *v12; // ecx
  const char *v13; // eax
  char *FileName; // [esp+8h] [ebp-190h]
  char *OldFilename; // [esp+10h] [ebp-188h]
  char String[128]; // [esp+18h] [ebp-180h] BYREF
  char v17[256]; // [esp+98h] [ebp-100h] BYREF

  if ( *(_BYTE *)(this + 268) )
  {
    byte_7655C4 = 0;
    return 0;
  }
  v2 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48), 14);
  v3 = v2;
  if ( !v2 )
    return 0;
  v4 = (char *)sub_49FB30(v2);
  if ( !v4 )
    return 0;
  sub_57B040(v4, 256);
  OldFilename = (char *)operator new(0x100u);
  *OldFilename = 0;
  v5 = ArgList;
  if ( !ArgList )
    v5 = &byte_629120;
  sub_578560(v5);
  sub_578560(v17);
  sub_578560(aVcr);
  sub_57AF80(&byte_765558);
  sub_57B040(&byte_765558, 128);
  FileName = (char *)operator new(0x80u);
  *FileName = 0;
  v6 = ArgList;
  if ( !ArgList )
    v6 = &byte_629120;
  sub_578560(v6);
  sub_578560(String);
  sub_578560(aVcr);
  v7 = _strupr(String);
  v8 = strcmp(_strupr(v17), v7) == 0;
  v9 = FileName;
  if ( v8 )
  {
LABEL_29:
    if ( v9 )
      sub_5BE8AE(v9);
    if ( OldFilename )
      sub_5BE8AE(OldFilename);
    return 0;
  }
  if ( !FileName )
    v9 = &byte_629120;
  v10 = fopen(v9, aRb);
  if ( !v10 )
  {
LABEL_22:
    v12 = FileName;
    if ( !FileName )
      v12 = &byte_629120;
    v13 = OldFilename;
    if ( !OldFilename )
      v13 = &byte_629120;
    if ( !rename(v13, v12) )
      sub_48DDC0(v3);
    v9 = FileName;
    goto LABEL_29;
  }
  fclose(v10);
  if ( byte_7655C4 )
  {
    v11 = FileName;
    if ( !FileName )
      v11 = &byte_629120;
    sub_57AF60(v11);
    goto LABEL_22;
  }
  byte_7655C4 = 1;
  sub_4AD720(aReplayOverwrit, 1);
  if ( FileName )
    sub_5BE8AE(FileName);
  if ( OldFilename )
    sub_5BE8AE(OldFilename);
  return -1;
}
