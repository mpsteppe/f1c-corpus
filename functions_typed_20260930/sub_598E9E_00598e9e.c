int __thiscall sub_598E9E(int this, int a2)
{
  unsigned int v4; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int v10; // edi
  int v11; // ebx
  int v12; // [esp+Ch] [ebp-10h] BYREF
  char *v13; // [esp+10h] [ebp-Ch] BYREF
  int v14; // [esp+14h] [ebp-8h]
  char v15; // [esp+1Bh] [ebp-1h] BYREF
  char vars0; // [esp+1Ch] [ebp+0h] BYREF

  if ( a2 == -1 )
    return 0;
  v4 = **(_DWORD **)(this + 32);
  if ( v4 && v4 < v4 + **(_DWORD **)(this + 48) )
  {
    *(_BYTE *)sub_599485(this) = a2;
    return a2;
  }
  if ( !*(_DWORD *)(this + 80) )
    return -1;
  if ( !*(_DWORD *)(this + 56) )
  {
    if ( BufferedCharacterWriteWithOverflowHandling((char)a2, *(_DWORD **)(this + 80)) != -1 )
      return a2;
    return -1;
  }
  v15 = a2;
  BufferTruncationShrink(0, -1);
  BufferAppendWithMemset(8, 0);
  v5 = *(_DWORD *)(this + 68);
  BufferBoundaryMarkerCheckSet(v5);
  v6 = *(_DWORD *)(this + 68);
  v14 = *(_DWORD *)(v5 + 4);
  BufferBoundaryMarkerCheckSet(v6);
  v7 = (*(int (__thiscall **)(_DWORD, int, char *, char *, char **, _DWORD, int, int *))(**(_DWORD **)(this + 56) + 20))(
         *(_DWORD *)(this + 56),
         this + 64,
         &v15,
         &vars0,
         &v13,
         *(_DWORD *)(v6 + 4),
         v14 != 0 ? v14 + *(_DWORD *)(v5 + 8) : 0,
         &v12);
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      if ( v8 == 2 && BufferedCharacterWriteWithOverflowHandling(v15, *(_DWORD **)(this + 80)) != -1 )
        return a2;
      return -1;
    }
    if ( v13 == &v15 )
      return -1;
  }
  v9 = *(_DWORD *)(this + 68);
  BufferBoundaryMarkerCheckSet(v9);
  v10 = v12 - *(_DWORD *)(v9 + 4);
  v11 = *(_DWORD *)(this + 68);
  BufferBoundaryMarkerCheckSet(v11);
  if ( FileReadWrapperWithLock(*(_DWORD *)(v11 + 4), 1, v10, *(_DWORD *)(this + 80)) == v10 )
    return a2;
  return -1;
}

