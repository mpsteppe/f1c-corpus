char __thiscall sub_461190(int this, char a2)
{
  const char *v3; // ebp
  char result; // al
  char **v5; // eax
  char **v6; // edi
  int v7; // eax
  char *v8; // eax
  char *v9; // edi
  char v10[64]; // [esp+Ch] [ebp-C0h] BYREF
  _BYTE v11[128]; // [esp+4Ch] [ebp-80h] BYREF

  if ( a2 )
  {
    v3 = aOpened;
    *(_DWORD *)(this + 44) = 1084227584;
  }
  else
  {
    v3 = aClosed;
    *(_DWORD *)(this + 44) = -1082130432;
    *(_BYTE *)(this + 41) = 0;
  }
  result = dword_7D0398;
  if ( dword_7D0398 )
  {
    v5 = (char **)OperatorNewNhMallocWrapper(8);
    if ( v5 )
    {
      *v5 = 0;
      v5[1] = (char *)-1;
      v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    TrackNameReader(v10, 63);
    StringFormatWithBufferOverflowCheck(v11, "*** The server %s %s", v3, v10);
    StringCopyWithBufferRealloc(v11);
    if ( v6 )
    {
      v7 = OperatorNewNhMallocWrapper(12);
      if ( v7 )
      {
        *(_DWORD *)v7 = v6;
        *(_DWORD *)(v7 + 4) = 0;
        *(_BYTE *)(v7 + 8) = 0;
      }
      else
      {
        v7 = 0;
      }
      if ( *(_DWORD *)(this + 112496) )
      {
        *(_DWORD *)(*(_DWORD *)(this + 112500) + 4) = v7;
      }
      else
      {
        *(_DWORD *)(this + 112496) = v7;
        *(_DWORD *)(this + 112504) = v7;
      }
      *(_DWORD *)(this + 112500) = v7;
      ++*(_DWORD *)(this + 112508);
    }
    v8 = *v6;
    if ( !*v6 )
      v8 = byte_5EA438;
    result = TextLineWrappingAndRendering(&dword_7CD204, (int)v8, 3, 16909060);
    if ( dword_7C569C != 5 )
    {
      result = StringSplitLoop(1, aDDevF119992002_1, 4935);
      if ( result )
      {
        v9 = *v6;
        if ( !v9 )
          v9 = byte_5EA438;
        return DebugLogWrite(&dword_8AD25C, v9);
      }
    }
  }
  return result;
}

