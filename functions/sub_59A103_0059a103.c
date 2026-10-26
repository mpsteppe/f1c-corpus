__int16 __thiscall sub_59A103(int this)
{
  unsigned int v2; // eax
  __int16 result; // ax
  _DWORD *v4; // ecx
  int v5; // eax
  _DWORD *v6; // edi
  _DWORD *v7; // ebx
  int v8; // eax
  int v9; // eax
  _DWORD *v10; // eax
  int v11; // esi
  _BYTE v12[4]; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v13[4]; // [esp+10h] [ebp-Ch] BYREF
  int v14; // [esp+14h] [ebp-8h]
  __int16 v15; // [esp+1Ah] [ebp-2h] BYREF
  char vars0; // [esp+1Ch] [ebp+0h] BYREF

  v2 = **(_DWORD **)(this + 28);
  if ( v2 && v2 < v2 + 2 * **(_DWORD **)(this + 44) )
    return *(_WORD *)StdGninc(this);
  if ( !*(_DWORD *)(this + 80) )
    return -1;
  if ( *(_DWORD *)(this + 56) )
  {
    v4 = *(_DWORD **)(this + 68);
    *(_DWORD *)(this + 60) = *(_DWORD *)(this + 64);
    BufferTruncationShrink(v4, 0, 0xFFFFFFFF);
    while ( 1 )
    {
      v5 = StreamGetcWithUnderflowHandler(*(_DWORD **)(this + 80));
      if ( v5 == -1 )
        break;
      BufferAppendWithMemset(*(_DWORD **)(this + 68), 1, v5);
      v6 = *(_DWORD **)(this + 68);
      *(_DWORD *)(this + 64) = *(_DWORD *)(this + 60);
      BufferBoundaryMarkerCheckSet(v6);
      v7 = *(_DWORD **)(this + 68);
      v14 = v6[1];
      BufferBoundaryMarkerCheckSet(v7);
      v8 = (*(int (__thiscall **)(_DWORD, int, _DWORD, int, _BYTE *, __int16 *, char *, _BYTE *))(**(_DWORD **)(this + 56)
                                                                                                + 16))(
             *(_DWORD *)(this + 56),
             this + 64,
             v7[1],
             v14 != 0 ? v14 + v6[2] : 0,
             v12,
             &v15,
             &vars0,
             v13);
      if ( !v8 )
        return v15;
      v9 = v8 - 1;
      if ( v9 )
      {
        if ( v9 != 2 )
          return -1;
        v10 = *(_DWORD **)(this + 68);
        if ( v10[2] >= 2u )
        {
          v11 = *(_DWORD *)(this + 68);
          BufferBoundaryMarkerCheckSet(v10);
          MemoryCopy_cc00((unsigned int)&v15, *(_BYTE **)(v11 + 4), 2u);
          return v15;
        }
      }
    }
    return -1;
  }
  result = IOFormatWrapper(*(_DWORD *)(this + 80));
  if ( result == -1 )
    return -1;
  return result;
}
