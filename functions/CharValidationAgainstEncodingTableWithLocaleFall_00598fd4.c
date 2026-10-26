int __thiscall sub_598FD4(int this, int a2)
{
  unsigned int v3; // eax
  int v4; // ebx
  int v6; // edi
  int v7; // ebx

  v3 = **(_DWORD **)(this + 28);
  if ( v3 && **(_DWORD **)(this + 12) < v3 )
  {
    v4 = a2;
    if ( a2 == -1 || *(unsigned __int8 *)(v3 - 1) == a2 )
    {
      RefCountIncDec(this);
      return a2 != -1 ? a2 : 0;
    }
  }
  else
  {
    v4 = a2;
  }
  if ( *(_DWORD *)(this + 80) && v4 != -1 )
  {
    if ( *(_DWORD *)(this + 56) )
    {
      v6 = *(_DWORD *)(this + 68);
      v7 = *(_DWORD *)(v6 + 8);
      if ( v7 )
      {
        BufferBoundaryMarkerCheckSet(*(_DWORD *)(this + 68));
        if ( (unsigned __int8)CharByCharBackwardScanWithValidation(*(_DWORD *)(v6 + 4), *(_DWORD *)(this + 80), v7) )
        {
          BufferTruncationShrink(0, -1);
          *(_DWORD *)(this + 64) = *(_DWORD *)(this + 60);
          return a2;
        }
      }
    }
    else if ( FileIOWrapperWithLock((unsigned __int8)v4, *(_DWORD *)(this + 80)) != -1 )
    {
      return v4;
    }
  }
  return -1;
}
