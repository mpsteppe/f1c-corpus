char __thiscall sub_57B330(int this, int a2)
{
  _DWORD *v3; // ecx
  int v5; // edi
  int v6; // ebp
  _DWORD *v7; // edi
  void *v8; // ebp
  _DWORD **v9; // eax
  _DWORD *v10; // ebp
  int v11; // eax
  int v12; // edi
  int v13; // eax
  int v14; // edx
  int v15; // eax
  _DWORD **v16; // eax
  _DWORD **v17; // eax
  _DWORD *i; // edi
  _DWORD *v19; // ebp
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  int v22; // ecx
  _DWORD *v23; // [esp+1Ch] [ebp+4h]

  v3 = (_DWORD *)a2;
  if ( !a2 )
    return 0;
  *(_BYTE *)(this + 4) = *(_BYTE *)(a2 + 4);
  v5 = *(_DWORD *)(this + 8);
  if ( v5 )
  {
    do
    {
      v6 = v5;
      v5 = *(_DWORD *)(v5 + 4);
      if ( *(_BYTE *)(v6 + 8) )
        FreeWrapper_7bcf(*(LPVOID *)v6);
      FreeWrapper_7bcf((LPVOID)v6);
    }
    while ( v5 );
    v3 = (_DWORD *)a2;
  }
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 20) = 0;
  v7 = *(_DWORD **)(this + 24);
  if ( v7 )
  {
    do
    {
      v8 = v7;
      v7 = (_DWORD *)v7[1];
      ConditionalFreeByFlagCheck(v8);
      FreeWrapper_7bcf(v8);
    }
    while ( v7 );
    v3 = (_DWORD *)a2;
  }
  *(_DWORD *)(this + 24) = 0;
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  v9 = (_DWORD **)v3[2];
  v3[4] = v9;
  if ( v9 )
  {
    v10 = *v9;
    if ( *v9 )
    {
      do
      {
        v11 = OperatorNewNhMallocWrapper(16);
        v12 = v11;
        if ( v11 )
        {
          *(_WORD *)v11 = 2;
          *(_DWORD *)(v11 + 4) = htonl(0);
          *(_WORD *)(v12 + 2) = htons(0);
        }
        else
        {
          v12 = 0;
        }
        *(_DWORD *)v12 = *v10;
        *(_DWORD *)(v12 + 4) = v10[1];
        *(_DWORD *)(v12 + 8) = v10[2];
        *(_DWORD *)(v12 + 12) = v10[3];
        v13 = OperatorNewNhMallocWrapper(12);
        if ( v13 )
        {
          *(_DWORD *)v13 = v12;
          *(_DWORD *)(v13 + 4) = 0;
          *(_BYTE *)(v13 + 8) = 1;
        }
        else
        {
          v13 = 0;
        }
        if ( *(_DWORD *)(this + 8) )
        {
          *(_DWORD *)(*(_DWORD *)(this + 12) + 4) = v13;
        }
        else
        {
          *(_DWORD *)(this + 8) = v13;
          *(_DWORD *)(this + 16) = v13;
        }
        v14 = *(_DWORD *)(this + 20);
        *(_DWORD *)(this + 12) = v13;
        *(_DWORD *)(this + 20) = v14 + 1;
        v15 = *(_DWORD *)(a2 + 16);
        if ( !v15 )
          break;
        v16 = *(_DWORD ***)(v15 + 4);
        *(_DWORD *)(a2 + 16) = v16;
        if ( !v16 )
          break;
        v10 = *v16;
      }
      while ( *v16 );
      v3 = (_DWORD *)a2;
    }
  }
  v17 = (_DWORD **)v3[6];
  v23 = v3 + 6;
  v3[8] = v17;
  if ( v17 )
  {
    for ( i = *v17; i; i = (_DWORD *)LinkedListNodeAdvance(v23) )
    {
      v19 = (_DWORD *)OperatorNewNhMallocWrapper(4);
      *v19 = *i;
      v20 = (_DWORD *)OperatorNewNhMallocWrapper(12);
      if ( v20 )
        v21 = ShortComputation_ac20(v20, (int)v19, 1);
      else
        v21 = 0;
      if ( *(_DWORD *)(this + 24) )
      {
        *(_DWORD *)(*(_DWORD *)(this + 28) + 4) = v21;
      }
      else
      {
        *(_DWORD *)(this + 24) = v21;
        *(_DWORD *)(this + 32) = v21;
      }
      v22 = *(_DWORD *)(this + 36);
      *(_DWORD *)(this + 28) = v21;
      *(_DWORD *)(this + 36) = v22 + 1;
    }
  }
  return 1;
}
