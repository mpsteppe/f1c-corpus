char __thiscall sub_5813E0(int this, _WORD *a2, char a3, char a4)
{
  int v4; // esi
  void *v6; // eax
  int v7; // ebx
  _DWORD *v8; // edi
  DWORD v9; // eax
  int *v10; // eax
  bool v11; // zf
  int v12; // eax
  LPVOID v13; // ecx
  int v14; // eax
  int *v15; // eax
  _DWORD *v16; // eax
  int v17; // eax
  void *v18; // eax
  int v20; // [esp+4h] [ebp-38h] BYREF
  u_long v21; // [esp+8h] [ebp-34h]
  LPVOID v22[7]; // [esp+14h] [ebp-28h] BYREF
  int v23; // [esp+38h] [ebp-4h]

  v4 = 0;
  ObjectInitWithVTableSetup(v22, -1, 255, 0);
  v23 = 0;
  BinaryPacketFieldParserWithOffsetMath((int)v22, a2);
  v6 = *(void **)(this + 2776);
  v7 = this + 2760;
  v8 = 0;
  if ( v6 )
  {
    v9 = WaitForSingleObject(v6, *(_DWORD *)(this + 2780));
    if ( !v9 || v9 == 128 )
      v4 = this + 2760;
  }
  v10 = *(int **)v4;
  v11 = *(_DWORD *)v4 == 0;
  *(_DWORD *)(v4 + 8) = *(_DWORD *)v4;
  if ( v11 )
    goto LABEL_14;
  v12 = *v10;
  if ( !v12 )
    goto LABEL_14;
  v13 = v22[5];
  do
  {
    if ( *(LPVOID *)(v12 + 20) == v13 )
      v8 = (_DWORD *)v12;
    v14 = *(_DWORD *)(v4 + 8);
    if ( !v14 )
      break;
    v15 = *(int **)(v14 + 4);
    *(_DWORD *)(v4 + 8) = v15;
    if ( !v15 )
      break;
    v12 = *v15;
  }
  while ( v12 );
  if ( v8 )
  {
    ObjectInitWithCopy(v8, (int)v22);
  }
  else
  {
LABEL_14:
    v16 = (_DWORD *)OperatorNewNhMallocWrapper(32);
    LOBYTE(v23) = 1;
    if ( v16 )
      v8 = ObjectCopyInitWithVTableSetup(v16, (int)v22);
    else
      v8 = 0;
    LOBYTE(v23) = 0;
    if ( v8 )
    {
      v17 = OperatorNewNhMallocWrapper(12);
      if ( v17 )
      {
        *(_DWORD *)v17 = v8;
        *(_DWORD *)(v17 + 4) = 0;
        *(_BYTE *)(v17 + 8) = 1;
      }
      else
      {
        v17 = 0;
      }
      if ( *(_DWORD *)v4 )
      {
        *(_DWORD *)(*(_DWORD *)(v4 + 4) + 4) = v17;
      }
      else
      {
        *(_DWORD *)v4 = v17;
        *(_DWORD *)(v4 + 8) = v17;
      }
      *(_DWORD *)(v4 + 4) = v17;
      ++*(_DWORD *)(v4 + 12);
    }
    if ( sub_587220(v8) == 2 && a4 )
    {
      LOWORD(v20) = 2;
      v21 = htonl(0);
      HIWORD(v20) = htons(0);
      Copy4DwordsStructToStruct((_DWORD *)(this + 2692), &v20);
      sub_57DD40((int **)this, &v20, (int)v8);
    }
    v7 = this + 2760;
  }
  CounterIncrementDecrementByFlag(v8, a3);
  if ( MutexProtectedPointerReadRelease((int *)this) == 3 && sub_587220(v8) == 2 )
  {
    LOWORD(v20) = 2;
    v21 = htonl(0);
    HIWORD(v20) = htons(0);
    Copy4DwordsStructToStruct((_DWORD *)(this + 2692), &v20);
    sub_57DD40((int **)this, &v20, (int)v8);
  }
  v18 = *(void **)(v7 + 16);
  if ( v18 )
    ReleaseMutex(v18);
  v23 = -1;
  SetVtablePointerAndCallInit(v22);
  return 0;
}

