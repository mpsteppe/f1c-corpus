int __thiscall sub_49EE4D(void *this, const char *ArgList, char a3)
{
  bool v3; // zf
  DWORD FileAttributesA; // eax
  int v6; // eax
  char v7; // cl
  void **v8; // ebp
  int *v9; // eax
  int v10; // eax
  _DWORD *v11; // eax
  int *v12; // eax
  char *v13; // edx
  char *v14; // eax
  char v15; // cl
  int v16; // [esp+0h] [ebp-204h]
  char String[2]; // [esp+4h] [ebp-200h] BYREF
  _BYTE v18[252]; // [esp+6h] [ebp-1FEh] BYREF
  __int16 v19; // [esp+102h] [ebp-102h]
  char Buffer[2]; // [esp+104h] [ebp-100h] BYREF
  _BYTE v21[252]; // [esp+106h] [ebp-FEh] BYREF
  __int16 v22; // [esp+202h] [ebp-2h]

  v3 = *ArgList == 0;
  v16 = (int)this;
  if ( v3 )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid search path %s specified", (char)ArgList);
    return -1;
  }
  else
  {
    strcpy(String, " ");
    memset(v18, 0, sizeof(v18));
    v19 = 0;
    strcpy(Buffer, " ");
    memset(v21, 0, sizeof(v21));
    v22 = 0;
    strcpy(String, ArgList);
    _strupr(String);
    if ( byte_FB28E4 )
    {
      sprintf(Buffer, "%s\\%s", &byte_FB28E4, ArgList);
      _strupr(Buffer);
    }
    if ( (!strcmp(ArgList, ".") || !strcmp(ArgList, ".\\")) && byte_FB28E4 )
    {
      sprintf(String, "%s\\%s", &byte_FB28E4, ArgList);
      _strupr(String);
    }
    if ( String[strlen(String) - 1] == 92 )
    {
      String[strlen(String) - 1] = 0;
      Buffer[strlen(Buffer) - 1] = 0;
    }
    FileAttributesA = GetFileAttributesA(String);
    if ( FileAttributesA == -1 )
    {
      if ( GetFileAttributesA(Buffer) == -1 )
      {
        sub_5D8C80(v16, (char *)0xFFFFFFFF, "Search path %s does not exist", (char)ArgList);
        return -1;
      }
      v6 = 0;
      do
      {
        v7 = Buffer[v6];
        String[v6++] = v7;
      }
      while ( v7 );
    }
    else if ( (FileAttributesA & 0x10) == 0 )
    {
      sub_5D8C80(v16, (char *)0xFFFFFFFF, "Search path %s is not a directory", (char)ArgList);
      return -1;
    }
    v8 = &dword_FB27C4;
    if ( !a3 )
      v8 = &dword_FB286C;
    v9 = (int *)*v8;
    v3 = *v8 == 0;
    v8[2] = *v8;
    if ( v3 || (v10 = *v9) == 0 )
    {
LABEL_27:
      v13 = (char *)operator new(0x104u);
      if ( v13 )
      {
        *(_DWORD *)v13 = 0;
        memset(v13 + 4, 0, 0x100u);
      }
      else
      {
        v13 = 0;
      }
      v14 = String;
      do
      {
        v15 = *v14;
        v14[v13 - String + 4] = *v14;
        ++v14;
      }
      while ( v15 );
      *(_DWORD *)v13 |= a3 != 0 ? 0x4000 : 0;
      sub_5FDFB0(v13, 1);
      return 0;
    }
    else
    {
      while ( strcmp(String, (const char *)(v10 + 4)) )
      {
        v11 = v8[2];
        if ( v11 )
        {
          v12 = (int *)v11[1];
          v8[2] = v12;
          if ( v12 )
          {
            v10 = *v12;
            if ( v10 )
              continue;
          }
        }
        goto LABEL_27;
      }
      sub_5D8C80(v16, (char *)0xFFFFFFFD, "Search path %s already exists", (char)ArgList);
      return -3;
    }
  }
}
