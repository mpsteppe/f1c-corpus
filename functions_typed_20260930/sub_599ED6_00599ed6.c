__int16 __thiscall sub_599ED6(int this, int a2)
{
  __int16 result; // ax
  unsigned int v4; // eax
  bool v5; // zf
  _DWORD *v6; // ecx
  _DWORD *v7; // edi
  _DWORD *v8; // ebx
  int v9; // eax
  int v10; // eax
  _DWORD *v11; // ebx
  int v12; // edi
  _DWORD *v13; // ebx
  int v14; // [esp+Ch] [ebp-10h] BYREF
  int *v15; // [esp+10h] [ebp-Ch] BYREF
  int v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+18h] [ebp-4h] BYREF

  if ( (_WORD)a2 == 0xFFFF )
    return 0;
  v4 = **(_DWORD **)(this + 32);
  if ( v4 && v4 < v4 + 2 * **(_DWORD **)(this + 48) )
  {
    *(_WORD *)StreamBufferPointerAdjust(this) = a2;
    return a2;
  }
  if ( !*(_DWORD *)(this + 80) )
    return -1;
  if ( !*(_DWORD *)(this + 56) )
  {
    v5 = (unsigned __int16)ThreeStepStreamQuery(a2, *(_DWORD *)(this + 80)) == 0xFFFF;
    result = a2;
    goto LABEL_14;
  }
  v6 = *(_DWORD **)(this + 68);
  v17 = a2;
  BufferTruncationShrink(v6, 0, 0xFFFFFFFF);
  BufferAppendWithMemset(*(_DWORD **)(this + 68), 8, 0);
  v7 = *(_DWORD **)(this + 68);
  BufferBoundaryMarkerCheckSet(v7);
  v8 = *(_DWORD **)(this + 68);
  v16 = v7[1];
  BufferBoundaryMarkerCheckSet(v8);
  v9 = (*(int (__thiscall **)(_DWORD, int, int *, char *, int **, _DWORD, int, int *))(**(_DWORD **)(this + 56) + 20))(
         *(_DWORD *)(this + 56),
         this + 64,
         &v17,
         (char *)&v17 + 2,
         &v15,
         v8[1],
         v16 != 0 ? v16 + v7[2] : 0,
         &v14);
  if ( !v9 )
    goto LABEL_17;
  v10 = v9 - 1;
  if ( !v10 )
  {
    if ( v15 == &v17 )
      return -1;
LABEL_17:
    v11 = *(_DWORD **)(this + 68);
    BufferBoundaryMarkerCheckSet(v11);
    v12 = v14 - v11[1];
    v13 = *(_DWORD **)(this + 68);
    BufferBoundaryMarkerCheckSet(v13);
    v5 = FileReadWrapperWithLock(v13[1], 1, v12, *(_DWORD *)(this + 80)) == v12;
    result = a2;
    if ( v5 )
      return result;
    return -1;
  }
  if ( v10 != 2 )
    return -1;
  v5 = (unsigned __int16)ThreeStepStreamQuery(v17, *(_DWORD *)(this + 80)) == 0xFFFF;
  result = a2;
LABEL_14:
  if ( !v5 )
    return result;
  return -1;
}

