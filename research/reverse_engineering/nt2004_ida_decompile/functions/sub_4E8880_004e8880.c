int __thiscall sub_4E8880(void *this)
{
  int v2; // ebx
  const char *v3; // ecx
  const char *v4; // eax
  const char *i; // eax
  FILE *v6; // esi
  char *v7; // eax
  int v8; // edx
  char FileName[256]; // [esp+10h] [ebp-6600h] BYREF
  char Buffer[256]; // [esp+110h] [ebp-6500h] BYREF
  int v12[6400]; // [esp+210h] [ebp-6400h] BYREF

  v2 = 0;
  memset(v12, 0, sizeof(v12));
  v3 = (const char *)dword_62A0B0;
  byte_7D6A60 = 0;
  byte_7D6AB0 = 0;
  byte_7D6B00 = 0;
  dword_7D6B50 = 0;
  dword_7D6B54 = 0;
  dword_7D6B58 = 0;
  if ( !dword_62A0B0 )
    v3 = &byte_629120;
  v4 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v4 = &byte_629120;
  sprintf(Buffer, "%s%s", v4, v3);
  sub_578A30(aScn, 1, Buffer, 1);
  sub_578A00(&unk_7D7A0C);
  for ( i = (const char *)sub_578D80(&unk_7D7A0C); i; i = (const char *)sub_578D80(&unk_7D7A0C) )
  {
    sprintf(FileName, "%s%s", Buffer, i);
    v6 = fopen(FileName, aR);
    if ( v6 )
    {
      sub_4E8670(this, (int)v6, 0, FileName, (int)v12);
      fclose(v6);
    }
    if ( !(unsigned __int8)sub_5789D0(&unk_7D7A0C) )
      break;
  }
  if ( dword_7D6B58 )
    sub_5BE8AE((LPVOID)dword_7D6B58);
  v7 = (char *)operator new(400 * dword_7D6B50);
  dword_7D6B58 = (int)v7;
  if ( v7 && dword_7D6B50 > 0 )
  {
    v8 = 0;
    while ( 1 )
    {
      qmemcpy(&v7[v8 * 4], &v12[v8], 0x190u);
      ++v2;
      v8 += 100;
      if ( v2 >= dword_7D6B50 )
        break;
      v7 = (char *)dword_7D6B58;
    }
  }
  sub_578960(&unk_7D7A0C);
  sub_4E92D0(this);
  return dword_7D6B50;
}
