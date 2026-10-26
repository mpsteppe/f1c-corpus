int __thiscall sub_52DC90(int this)
{
  int result; // eax
  int v3; // eax
  unsigned int v4; // [esp+4h] [ebp-4h] BYREF

  if ( !*(_BYTE *)(this + 11580) )
    goto LABEL_5;
  if ( (*(int (__thiscall **)(_DWORD, unsigned int *, int, _DWORD))(**(_DWORD **)(this + 11572) + 8))(
         *(_DWORD *)(this + 11572),
         &v4,
         4,
         0) != 4 )
  {
    FileOpWithGlobalBuffer(aWaitingForCdAc);
    return -1;
  }
  result = CMpegBase_ProcessHeader(this, _byteswap_ulong(v4));
  if ( result != -1 )
  {
LABEL_5:
    v3 = *(_DWORD *)(this + 9368);
    if ( v3 < 4 )
    {
      FileOpWithGlobalBuffer(
        "CMpegFilePlayer::DecodeHeader : returned a corrupted mpeg header : header = %08X cFrameSize %d\n",
        v4,
        *(_DWORD *)(this + 9368));
LABEL_7:
      *(_DWORD *)(this + 9384) = 0;
      *(_BYTE *)(this + 11580) = 1;
      return 0;
    }
    if ( (*(int (__thiscall **)(_DWORD, _DWORD, int, _DWORD))(**(_DWORD **)(this + 11572) + 8))(
           *(_DWORD *)(this + 11572),
           *(_DWORD *)(this + 9380),
           v3,
           0) == *(_DWORD *)(this + 9368) )
      goto LABEL_7;
    *(_BYTE *)(this + 11580) = 0;
    return -1;
  }
  return result;
}

