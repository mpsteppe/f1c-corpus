int __thiscall sub_461020(int this)
{
  int v2; // edi
  LPVOID *v3; // eax
  LPVOID *v4; // edi
  char *v5; // eax
  int result; // eax
  int v7; // eax
  float v8; // [esp+0h] [ebp-1C0h]
  _DWORD v9[108]; // [esp+10h] [ebp-1B0h] BYREF

  v8 = dbl_8AFEA0;
  ProgressBarEventEncode(4, 37, 0, 255, LODWORD(v8), 1);
  v2 = COMVTableCallVia0x60(*(_DWORD *)(this + 16312));
  *(_BYTE *)(v2 + 4) = 1;
  NetworkSendDispatch(v9, ((v9[0] >> 8) & 0x3FF) + 8, v2, 1, 1, -1, 0);
  VirtualMethodDispatch(*(_DWORD *)(this + 16312), v2);
  *(_BYTE *)(this + 41) = 0;
  v3 = (LPVOID *)OperatorNewNhMallocWrapper(8);
  if ( v3 )
  {
    *v3 = 0;
    v3[1] = (LPVOID)-1;
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  StringCopyWithBufferRealloc(aClosingTrack);
  if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 4876) )
  {
    v5 = (char *)*v4;
    if ( !*v4 )
      v5 = byte_5EA438;
    DebugLogWrite(&dword_8AD25C, v5);
  }
  result = dword_7D0398;
  if ( dword_7D0398 )
  {
    if ( v4 )
    {
      v7 = OperatorNewNhMallocWrapper(12);
      if ( v7 )
      {
        *(_DWORD *)v7 = v4;
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
      result = *(_DWORD *)(this + 112508) + 1;
      *(_DWORD *)(this + 112508) = result;
    }
  }
  else if ( v4 )
  {
    if ( *v4 )
      FreeWrapper_7bcf(*v4);
    return FreeWrapper_7bcf(v4);
  }
  return result;
}

