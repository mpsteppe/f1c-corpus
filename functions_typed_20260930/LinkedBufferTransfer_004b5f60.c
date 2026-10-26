_DWORD **__thiscall sub_4B5F60(_DWORD *this)
{
  _DWORD **result; // eax
  _DWORD *i; // ebp
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // edx

  result = (_DWORD **)this[453];
  this[455] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      v4 = this[453];
      if ( v4 )
      {
        while ( *(_DWORD **)v4 != i )
        {
          v4 = *(_DWORD *)(v4 + 4);
          if ( !v4 )
            goto LABEL_19;
        }
        if ( v4 == this[455] )
          this[455] = *(_DWORD *)(v4 + 4);
        v5 = *(_DWORD *)(v4 + 8);
        if ( v5 )
          *(_DWORD *)(v5 + 4) = *(_DWORD *)(v4 + 4);
        else
          this[453] = *(_DWORD *)(v4 + 4);
        v6 = *(_DWORD *)(v4 + 4);
        if ( v6 )
          *(_DWORD *)(v6 + 8) = *(_DWORD *)(v4 + 8);
        if ( this[454] == v4 )
          this[454] = *(_DWORD *)(v4 + 8);
        --this[456];
        if ( *(_BYTE *)(v4 + 12) )
          FreeWrapper_7bcf(*(LPVOID *)v4);
        FreeWrapper_7bcf((LPVOID)v4);
      }
LABEL_19:
      SmallStructZeroInit(i);
      v7 = OperatorNewNhMallocWrapper(12);
      if ( v7 )
      {
        *(_DWORD *)v7 = i;
        *(_DWORD *)(v7 + 4) = 0;
        *(_BYTE *)(v7 + 8) = 0;
      }
      else
      {
        v7 = 0;
      }
      v8 = this[12];
      if ( v8 )
      {
        *(_DWORD *)(v7 + 4) = v8;
      }
      else
      {
        this[13] = v7;
        this[14] = v7;
      }
      v9 = this[15] + 1;
      this[12] = v7;
      this[15] = v9;
      result = (_DWORD **)this[455];
      if ( !result )
        break;
    }
  }
  return result;
}

