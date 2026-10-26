__int16 __thiscall sub_59A01E(int this, int a2)
{
  unsigned int v3; // eax
  int v4; // edi
  int v5; // eax
  bool v6; // zf
  int v7; // edi
  int v8; // ebx

  v3 = **(_DWORD **)(this + 28);
  if ( v3 && **(_DWORD **)(this + 12) < v3 )
  {
    v4 = a2;
    if ( (_WORD)a2 == 0xFFFF || *(_WORD *)(v3 - 2) == (_WORD)a2 )
    {
      PointerOffsetAdjuster(this);
      return (_WORD)a2 != 0xFFFF ? a2 : 0;
    }
  }
  else
  {
    v4 = a2;
  }
  if ( !*(_DWORD *)(this + 80) || (_WORD)v4 == 0xFFFF )
  {
LABEL_15:
    LOWORD(v5) = -1;
    return v5;
  }
  if ( *(_DWORD *)(this + 56) )
  {
    v7 = *(_DWORD *)(this + 68);
    v8 = *(_DWORD *)(v7 + 8);
    if ( v8 )
    {
      BufferBoundaryMarkerCheckSet(*(_DWORD **)(this + 68));
      if ( CharByCharBackwardScanWithValidation(*(_DWORD *)(v7 + 4), *(_DWORD **)(this + 80), v8) )
      {
        BufferTruncationShrink(*(_DWORD **)(this + 68), 0, 0xFFFFFFFF);
        *(_DWORD *)(this + 64) = *(_DWORD *)(this + 60);
        LOWORD(v5) = a2;
        return v5;
      }
    }
    goto LABEL_15;
  }
  v6 = (unsigned __int16)StreamReadWrapperWithLockUnlock(v4, *(_DWORD *)(this + 80)) == 0xFFFF;
  LOWORD(v5) = v4;
  if ( v6 )
    LOWORD(v5) = -1;
  return v5;
}

