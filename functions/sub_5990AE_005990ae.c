int __thiscall sub_5990AE(int this)
{
  unsigned int v2; // eax
  int result; // eax
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // esi
  _BYTE v11[4]; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v12[4]; // [esp+10h] [ebp-Ch] BYREF
  int v13; // [esp+14h] [ebp-8h]
  unsigned __int8 v14; // [esp+1Bh] [ebp-1h] BYREF
  char vars0; // [esp+1Ch] [ebp+0h] BYREF

  v2 = **(_DWORD **)(this + 28);
  if ( v2 && v2 < v2 + **(_DWORD **)(this + 44) )
    return *(unsigned __int8 *)MSVCStreambufGninc(this);
  if ( !*(_DWORD *)(this + 80) )
    return -1;
  if ( *(_DWORD *)(this + 56) )
  {
    *(_DWORD *)(this + 60) = *(_DWORD *)(this + 64);
    BufferTruncationShrink(0, -1);
    while ( 1 )
    {
      v4 = StreamGetcWithUnderflowHandler(*(_DWORD **)(this + 80));
      if ( v4 == -1 )
        break;
      BufferAppendWithMemset(1, v4);
      v5 = *(_DWORD *)(this + 68);
      *(_DWORD *)(this + 64) = *(_DWORD *)(this + 60);
      BufferBoundaryMarkerCheckSet(v5);
      v6 = *(_DWORD *)(this + 68);
      v13 = *(_DWORD *)(v5 + 4);
      BufferBoundaryMarkerCheckSet(v6);
      v7 = (*(int (__thiscall **)(_DWORD, int, _DWORD, int, _BYTE *, unsigned __int8 *, char *, _BYTE *))(**(_DWORD **)(this + 56) + 16))(
             *(_DWORD *)(this + 56),
             this + 64,
             *(_DWORD *)(v6 + 4),
             v13 != 0 ? v13 + *(_DWORD *)(v5 + 8) : 0,
             v11,
             &v14,
             &vars0,
             v12);
      if ( !v7 )
        return v14;
      v8 = v7 - 1;
      if ( v8 )
      {
        if ( v8 != 2 )
          return -1;
        v9 = *(_DWORD *)(this + 68);
        if ( *(_DWORD *)(v9 + 8) )
        {
          v10 = *(_DWORD *)(this + 68);
          BufferBoundaryMarkerCheckSet(v9);
          MemoryCopy_cc00((unsigned int)&v14, *(_BYTE **)(v10 + 4), 1u);
          return v14;
        }
      }
    }
    return -1;
  }
  result = StreamGetcWithUnderflowHandler(*(_DWORD **)(this + 80));
  if ( result == -1 )
    return -1;
  return (unsigned __int8)result;
}
