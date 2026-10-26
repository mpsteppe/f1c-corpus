int __thiscall sub_4BB200(_DWORD *this)
{
  int result; // eax
  _DWORD *v3; // ebp
  char *v4; // eax
  char *v5; // esi
  int v6; // ebx
  char *v7; // eax
  int i; // ebp
  int v9; // esi
  int v10; // ecx
  char *v11; // [esp+10h] [ebp-4h]
  _DWORD *v12; // [esp+10h] [ebp-4h]

  result = OperatorNewNhMallocWrapper(4);
  v3 = (_DWORD *)result;
  if ( result )
  {
    v4 = (char *)OperatorNewNhMallocWrapper(384);
    v11 = v4;
    if ( v4 )
    {
      v5 = v4;
      v6 = 32;
      do
      {
        WrapperPassThrough(v5);
        v5 += 12;
        --v6;
      }
      while ( v6 );
      v7 = v11;
    }
    else
    {
      v7 = 0;
    }
    *v3 = v7;
    v12 = v3;
    result = OperatorNewNhMallocWrapper(12);
    if ( result )
    {
      *(_DWORD *)result = v3;
      *(_DWORD *)(result + 4) = 0;
      *(_BYTE *)(result + 8) = 1;
    }
    else
    {
      result = 0;
    }
    if ( *this )
    {
      *(_DWORD *)(this[1] + 4) = result;
    }
    else
    {
      *this = result;
      this[2] = result;
    }
    this[1] = result;
    ++this[3];
  }
  else
  {
    v12 = 0;
  }
  for ( i = 0; i < 384; i += 12 )
  {
    v9 = i + *v12;
    if ( v9 )
    {
      result = OperatorNewNhMallocWrapper(12);
      if ( result )
      {
        *(_DWORD *)result = v9;
        *(_DWORD *)(result + 4) = 0;
        *(_BYTE *)(result + 8) = 0;
      }
      else
      {
        result = 0;
      }
      v10 = this[4];
      if ( v10 )
      {
        *(_DWORD *)(result + 4) = v10;
      }
      else
      {
        this[5] = result;
        this[6] = result;
      }
      this[4] = result;
      ++this[7];
    }
  }
  return result;
}

