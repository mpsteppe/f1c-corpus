int __stdcall sub_53CFE0(int *a1, const char *a2, int a3)
{
  signed int v3; // ecx
  int v4; // edi
  int v5; // eax
  void *v6; // esi
  CHAR SrcStr[256]; // [esp+10h] [ebp-100h] BYREF

  strcpy(SrcStr, a2);
  sub_589901(SrcStr);
  v3 = strlen(SrcStr) - 1;
  if ( v3 > 0 )
  {
    while ( SrcStr[v3] != 46 )
    {
      if ( --v3 <= 0 )
        goto LABEL_6;
    }
    SrcStr[v3] = 0;
  }
LABEL_6:
  v4 = dword_8B8E20;
  if ( dword_8B8E20 )
  {
    while ( strcmp((const char *)(v4 + 20), SrcStr) )
    {
      v4 = *(_DWORD *)(v4 + 2160);
      if ( !v4 )
        goto LABEL_9;
    }
    if ( a1 )
    {
      *a1 = v4;
      return 0;
    }
    return 0;
  }
LABEL_9:
  v5 = OperatorNewNhMallocWrapper(2164);
  if ( v5 )
    v6 = (void *)HashTable(v5);
  else
    v6 = 0;
  if ( !sub_552470(a2, a3) )
  {
    LinkedListAppend_d340(v6);
    if ( a1 )
      *a1 = (int)v6;
    return 0;
  }
  if ( v6 )
  {
    EmptyStub_7470(v6);
    FreeWrapper_7bcf(v6);
  }
  return -1;
}

