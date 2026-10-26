int __thiscall sub_46CB50(_DWORD **this)
{
  int v2; // ebp
  _DWORD *v3; // ebx
  const char *v4; // eax
  int v5; // eax
  void *v6; // esi
  int v7; // eax
  char v8; // cl
  int v9; // eax
  int v10; // eax

  v2 = -1;
  v3 = (_DWORD *)(*(int (__thiscall **)(_DWORD *, int))(*this[16] + 28))(this[16], 3);
  if ( v3 )
  {
    if ( strlen(&byte_7CD818) && PlayerNameNeverUsedProfileNameUniquenessCheck(v3, &byte_7CD818) )
    {
      if ( byte_7D2E41 )
      {
        v4 = (const char *)dword_5EC440;
        if ( !dword_5EC440 )
          v4 = byte_5EA438;
        StringFormatWithBufferOverflowCheck(byte_7CD718, "%s%s", v4, aPlayernameneve);
        sub_499690(byte_7CD718);
        byte_7D2E41 = 0;
      }
      ReplaceSpecialCharsWithUnderscoreHyphen(&byte_7CD818);
      v5 = OperatorNewNhMallocWrapper(18868);
      if ( v5 )
        v6 = (void *)UIControlWindowInitialization(v5);
      else
        v6 = 0;
      if ( TextFileReader(&byte_7CD818) != -1 )
      {
        ShortComputation_92a0(v3, (int)&byte_7CD818, 1);
        v2 = 0;
      }
      if ( v6 )
      {
        StaticInitBulk(v6);
        FreeWrapper_7bcf(v6);
      }
      if ( (int)v3[276] > 0 )
        sub_4B0770(0);
      PlayerNameNeverUsedProfileFileCreateRead(&byte_7CE498);
      ShortComputation_0ad0(&unk_7CE24C);
    }
    else
    {
      if ( BinarySearchInStringTable(byte_5EC4C0, aProfileAlready, byte_5EC4CC) )
      {
        v7 = 0;
        do
        {
          v8 = aProfileAlready[v7];
          byte_5EC4CC[v7++] = v8;
        }
        while ( v8 );
      }
      (*(void (__thiscall **)(_DWORD *, char *))(*this[16] + 4))(this[16], byte_5EC4CC);
      LookupDispatch(aProfileExistsP, -1);
      v2 = -1;
    }
  }
  v9 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 3);
  if ( v9 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 160))(v9);
  v10 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 45);
  if ( v10 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 56))(v10, 1);
  return v2;
}
