int __thiscall sub_406405(void *this, const char *ArgList, char a3)
{
  bool v3; // zf
  void **v4; // ebp
  int *v5; // eax
  int v6; // edi
  _DWORD *v7; // eax
  int *v8; // eax
  int v10; // [esp+0h] [ebp-104h]
  char String[256]; // [esp+4h] [ebp-100h] BYREF

  v3 = *ArgList == 0;
  v10 = (int)this;
  if ( v3 )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid search path %s specified", (char)ArgList);
    return -1;
  }
  else
  {
    strcpy(String, ArgList);
    _strupr(String);
    if ( String[strlen(String) - 1] == 92 )
      String[strlen(String) - 1] = 0;
    v4 = &dword_FB27C4;
    if ( !a3 )
      v4 = &dword_FB286C;
    v5 = (int *)*v4;
    v3 = *v4 == 0;
    v4[2] = *v4;
    if ( v3 || (v6 = *v5) == 0 )
    {
LABEL_12:
      sub_5D8C80(v10, (char *)0xFFFFFFFF, "Search path %s not found", (char)ArgList);
      return -1;
    }
    else
    {
      while ( strcmp(String, (const char *)(v6 + 4)) )
      {
        v7 = v4[2];
        if ( v7 )
        {
          v8 = (int *)v7[1];
          v4[2] = v8;
          if ( v8 )
          {
            v6 = *v8;
            if ( *v8 )
              continue;
          }
        }
        goto LABEL_12;
      }
      sub_524660(v4, v6, 1);
      return 0;
    }
  }
}
