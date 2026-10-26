// positive sp value has been detected, the output may be wrong!
bool __userpurge sub_6146BA@<al>(char a1@<al>, int a2@<ecx>, char *a3, int FileName, int a5, int a6, char a7)
{
  bool result; // al
  int v9; // eax
  int v10; // edi
  void *v11; // eax
  bool v12; // bl
  char v13[1024]; // [esp-3F4h] [ebp-400h] BYREF

  *(_DWORD *)(a2 + 84) = 0;
  if ( !a1 || (result = sub_613B90(a3)) )
  {
    v9 = 0;
    while ( a3[v9] == Str2[v9] )
    {
      if ( ++v9 >= 2 )
      {
        v10 = 5;
        goto LABEL_8;
      }
    }
    v10 = FileName;
LABEL_8:
    *(_DWORD *)(a2 + 20) = v10;
    if ( a7 )
      *(_DWORD *)(a2 + 80) = v10;
    *(_DWORD *)(a2 + 16) = a5;
    sub_617930(1024);
    if ( v10 )
    {
      if ( v10 == 5 )
        v11 = sub_614590((int **)&unk_FB4138, v13, 0);
      else
        v11 = (void *)sub_62AD30(v13);
      *(_DWORD *)(a2 + 4) = v11;
    }
    else
    {
      if ( *(_DWORD *)(a2 + 16) )
        v11 = fopen(v13, "wt+");
      else
        v11 = fopen(v13, "wb+");
      *(_DWORD *)(a2 + 4) = v11;
    }
    v12 = v11 != 0;
    if ( v11 )
    {
      *(_BYTE *)(a2 + 28) = 0;
      sub_615860(v13);
      sub_614300(a2);
    }
    return v12;
  }
  return result;
}
