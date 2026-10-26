_DWORD *__thiscall sub_5824F0(_DWORD *this)
{
  _DWORD *v2; // ebp
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  _DWORD *v5; // edi
  int v6; // eax
  int v7; // ebp
  int v8; // edi
  int v9; // eax
  int v10; // ecx
  _DWORD *v12; // [esp+10h] [ebp-18h]

  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  v2 = (_DWORD *)OperatorNewNhMallocWrapper(4);
  if ( v2 )
  {
    v3 = (_DWORD *)OperatorNewNhMallocWrapper(644);
    if ( v3 )
    {
      v4 = v3 + 1;
      *v3 = 16;
      NTimeCallbackLoopWithSEH_a6eb(v3 + 1, 40, 16, StructInitializationWithVTable, sub_57AEF0);
      *v2 = v4;
    }
    else
    {
      *v2 = 0;
    }
    v5 = v2;
    v12 = v2;
  }
  else
  {
    v12 = 0;
    v5 = 0;
  }
  if ( v5 )
  {
    v6 = OperatorNewNhMallocWrapper(12);
    if ( v6 )
    {
      *(_DWORD *)v6 = v5;
      *(_DWORD *)(v6 + 4) = 0;
      *(_BYTE *)(v6 + 8) = 1;
    }
    else
    {
      v6 = 0;
    }
    if ( !*this )
    {
      *this = v6;
      this[2] = v6;
      this[1] = v6;
      v7 = 0;
      ++this[3];
      goto LABEL_16;
    }
    *(_DWORD *)(this[1] + 4) = v6;
    this[1] = v6;
    ++this[3];
  }
  v7 = 0;
  while ( 1 )
  {
LABEL_16:
    v8 = v7 + *v5;
    if ( v8 )
    {
      v9 = OperatorNewNhMallocWrapper(12);
      if ( v9 )
      {
        *(_DWORD *)v9 = v8;
        *(_DWORD *)(v9 + 4) = 0;
        *(_BYTE *)(v9 + 8) = 0;
      }
      else
      {
        v9 = 0;
      }
      v10 = this[4];
      if ( v10 )
      {
        *(_DWORD *)(v9 + 4) = v10;
      }
      else
      {
        this[5] = v9;
        this[6] = v9;
      }
      this[4] = v9;
      ++this[7];
    }
    v7 += 40;
    if ( v7 >= 640 )
      break;
    v5 = v12;
  }
  return this;
}

