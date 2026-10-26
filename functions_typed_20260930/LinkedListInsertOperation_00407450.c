void __thiscall LinkedListInsertOperation(_DWORD *this, char *a2)
{
  char ***v3; // eax
  char **v4; // eax
  char *v5; // eax
  int v6; // eax
  char ***v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  int v10; // eax

  if ( a2 )
  {
    v3 = (char ***)this[10];
    this[12] = v3;
    if ( v3 && (v4 = *v3) != 0 )
    {
      while ( 1 )
      {
        v5 = *v4;
        if ( !v5 )
          v5 = byte_5EA438;
        if ( !sub_588410(a2, v5) )
          break;
        v6 = this[12];
        if ( v6 )
          this[12] = *(_DWORD *)(v6 + 4);
        v7 = (char ***)this[12];
        if ( v7 )
        {
          v4 = *v7;
          if ( v4 )
            continue;
        }
        goto LABEL_11;
      }
    }
    else
    {
LABEL_11:
      v8 = (_DWORD *)OperatorNewNhMallocWrapper(8);
      v9 = v8;
      if ( v8 )
      {
        *v8 = 0;
        v8[1] = -1;
        StringCopyWithBufferRealloc((int)v8, a2);
      }
      else
      {
        v9 = 0;
      }
      if ( v9 )
      {
        v10 = OperatorNewNhMallocWrapper(12);
        if ( v10 )
        {
          *(_DWORD *)v10 = v9;
          *(_DWORD *)(v10 + 4) = 0;
          *(_BYTE *)(v10 + 8) = 1;
        }
        else
        {
          v10 = 0;
        }
        if ( this[10] )
        {
          *(_DWORD *)(this[11] + 4) = v10;
        }
        else
        {
          this[10] = v10;
          this[12] = v10;
        }
        this[11] = v10;
        ++this[13];
      }
    }
  }
}

