// f1c  0x004cdc70  size=262
int __stdcall sub_4CDC70(int a1, int a2, float *a3, int a4)
{
  int v4; // ebp
  int v6; // edi
  char v7[128]; // [esp+10h] [ebp-80h] BYREF

  v4 = sub_565520(a2, v7, 0);
  if ( !v4 )
    return v4;
  if ( v7[0] >= 48 && v7[0] <= 57 || v7[0] == 46 )
  {
    *a3 = sub_58850F(v7);
    return v4;
  }
  v6 = a4;
  if ( a4 )
  {
    while ( strcmp(v7, (const char *)v6) )
    {
      v6 = *(_DWORD *)(v6 + 36);
      if ( !v6 )
        goto LABEL_10;
    }
    *a3 = *(float *)(v6 + 32);
    return v4;
  }
  else
  {
LABEL_10:
    if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_25, 2231) )
      sub_4D7AA0(&unk_8AD25C, aCouldNotFindTr);
    return 0;
  }
}
