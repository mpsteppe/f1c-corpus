int __thiscall sub_5EE200(_DWORD *this, char *Str)
{
  char v2; // si
  char *v4; // eax
  char *v5; // edx
  char v6; // cl
  int v7; // ebx
  int v8; // ebp
  int v9; // esi
  int v11; // eax
  FILE *v12; // ecx
  char String1[256]; // [esp+10h] [ebp-100h] BYREF

  v2 = (char)Str;
  strcpy(String1, Str);
  if ( strrchr(Str, 92) )
  {
    v4 = strrchr(Str, 92) + 1;
    v5 = (char *)(String1 - v4);
    do
    {
      v6 = *v4;
      v4[(_DWORD)v5] = *v4;
      ++v4;
    }
    while ( v6 );
  }
  _strupr(String1);
  v7 = 0;
  if ( (int)this[69] <= 0 )
  {
LABEL_9:
    sub_5D8C80((int)this, (char *)0xFFFFFFFE, "Could not locate %s in MAS file %s", v2);
    return -2;
  }
  else
  {
    v8 = 0;
    while ( 1 )
    {
      v9 = v8 + this[73];
      if ( !_stricmp(String1, (const char *)(v9 + 16)) )
        break;
      ++v7;
      v8 += 256;
      if ( v7 >= this[69] )
      {
        v2 = (char)Str;
        goto LABEL_9;
      }
    }
    v11 = this[70];
    v12 = (FILE *)this[4];
    this[72] = v7;
    fseek(v12, *(_DWORD *)(v9 + 4) + v11, 0);
    return 0;
  }
}
