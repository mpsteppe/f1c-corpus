BOOL __thiscall sub_4B7300(int this, int a2, char a3)
{
  _DWORD *v4; // edi
  void *v5; // ebp
  const char *v6; // edx
  const char *v7; // ecx
  const char *v8; // edx
  const char *v9; // ecx
  char *v10; // eax
  int *v12; // edi
  int v13; // ecx

  sub_4B7500(1);
  if ( a3 )
  {
    LinkedBufferTransfer((_DWORD *)this);
    sub_4B5E50((_DWORD *)this);
    v4 = *(_DWORD **)(this + 1728);
    while ( v4 )
    {
      v5 = v4;
      v4 = (_DWORD *)v4[1];
      NodeDataFree(v5);
      FreeWrapper_7bcf(v5);
    }
    *(_DWORD *)(this + 1728) = 0;
    *(_DWORD *)(this + 1732) = 0;
    *(_DWORD *)(this + 1736) = 0;
    *(_DWORD *)(this + 1740) = 0;
    StringCopyWithBufferRealloc(a2);
    v6 = (const char *)dword_7CE5D0;
    if ( !dword_7CE5D0 )
      v6 = byte_5EA438;
    v7 = &v6[strlen(v6)];
    if ( v7 > v6 )
    {
      while ( *v7 != 92 )
      {
        if ( --v7 <= v6 )
          goto LABEL_11;
      }
      ++v7;
    }
LABEL_11:
    StringCopyWithBufferRealloc(v7);
    v8 = (const char *)dword_7CE608;
    if ( !dword_7CE608 )
      v8 = byte_5EA438;
    v9 = &v8[strlen(v8)];
    if ( v9 > v8 )
    {
      while ( *v9 != 92 )
      {
        if ( --v9 <= v8 )
          goto LABEL_18;
      }
      ++v9;
    }
LABEL_18:
    StringCopyWithBufferRealloc(v9);
    FileSettingExistenceCheck(this);
    sub_4B9830(this + 1796);
    v10 = *(char **)(this + 1796);
    if ( !v10 )
      v10 = byte_5EA438;
    if ( (unsigned __int8)sub_566940(v10, 0, 0, 1) )
    {
      *(_DWORD *)(this + 1792) = 1;
    }
    else
    {
      StringCopyWithBufferRealloc(byte_5EA438);
      *(_DWORD *)(this + 1792) = 0;
    }
    *(_DWORD *)(this + 3876) = 0;
    *(_DWORD *)(this + 3880) = 0;
    *(_DWORD *)(this + 3884) = 0;
    *(_DWORD *)(this + 3368) = 0;
    *(_BYTE *)(this + 3960) = 0;
    *(_DWORD *)(this + 3868) = *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580);
    *(_DWORD *)(this + 3872) = dword_7C56A4;
    return *(_DWORD *)(this + 1764) != 0;
  }
  else
  {
    v12 = (int *)(this + 1764);
    AudioStreamOpen(a2, 0);
    if ( ModelSceneFileLoader(this, this + 1764) )
    {
      AngleClampWrap(*(float *)(this + 3888));
      v13 = *v12;
      *(_DWORD *)(this + 1792) = 2;
      return v13 != 0;
    }
    else
    {
      ConditionalFileHandleCloseWithFlagDispatch(this + 1764);
      return *v12 != 0;
    }
  }
}

