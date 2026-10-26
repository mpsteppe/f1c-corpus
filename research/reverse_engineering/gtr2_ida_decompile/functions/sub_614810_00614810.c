bool __thiscall sub_614810(int this, char *a2, int a3, int a4, char a5)
{
  int v6; // eax
  int v7; // edi
  bool result; // al
  void *v9; // eax
  bool v10; // bl
  char FileName[1024]; // [esp+10h] [ebp-400h] BYREF

  v6 = 0;
  *(_DWORD *)(this + 84) = 0;
  while ( a2[v6] == Str2[v6] )
  {
    if ( ++v6 >= 2 )
    {
      v7 = 5;
      goto LABEL_6;
    }
  }
  v7 = a3;
LABEL_6:
  if ( !a5 || (result = sub_613B90(a2)) )
  {
    *(_DWORD *)(this + 20) = v7;
    *(_DWORD *)(this + 16) = a4;
    sub_617930(1024);
    if ( *(_DWORD *)(this + 20) == 5 )
    {
      v9 = sub_614590((int **)&unk_FB4138, FileName, 1);
      *(_DWORD *)(this + 4) = v9;
    }
    else
    {
      if ( *(_DWORD *)(this + 16) )
        v9 = fopen(FileName, "at+");
      else
        v9 = fopen(FileName, "ab+");
      *(_DWORD *)(this + 4) = v9;
    }
    v10 = v9 != 0;
    if ( v9 )
    {
      *(_BYTE *)(this + 28) = 0;
      sub_615860(FileName);
    }
    return v10;
  }
  return result;
}
