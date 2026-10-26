// f1c  0x00567e10  size=241
int __thiscall sub_567E10(_DWORD *this, int a2)
{
  char ***v3; // eax
  char **v4; // eax
  char *v5; // ecx
  char *v6; // eax
  int result; // eax
  int v8; // eax
  char ***v9; // eax
  _DWORD *v10; // esi
  const char *v11; // eax
  int v12; // ebx

  v3 = (char ***)this[9];
  this[11] = v3;
  if ( v3 && (v4 = *v3) != 0 )
  {
    while ( 1 )
    {
      v5 = *(char **)(a2 + 4);
      if ( !v5 )
        v5 = byte_5EA438;
      v6 = *v4;
      if ( !v6 )
        v6 = byte_5EA438;
      result = sub_588410(v6, v5);
      if ( !result )
        break;
      v8 = this[11];
      if ( v8 )
        this[11] = *(_DWORD *)(v8 + 4);
      v9 = (char ***)this[11];
      if ( v9 )
      {
        v4 = *v9;
        if ( v4 )
          continue;
      }
      goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    result = sub_587C03(12);
    v10 = (_DWORD *)result;
    if ( result )
    {
      v11 = *(const char **)(a2 + 4);
      v12 = this[13];
      if ( !v11 )
        v11 = byte_5EA438;
      this[13] = v12 + 1;
      *v10 = 0;
      v10[1] = -1;
      result = sub_566650((int)v10, v11);
      v10[2] = v12;
    }
    else
    {
      v10 = 0;
    }
    if ( v10 )
    {
      result = sub_587C03(12);
      if ( result )
      {
        *(_DWORD *)result = v10;
        *(_DWORD *)(result + 4) = 0;
        *(_BYTE *)(result + 8) = 1;
      }
      else
      {
        result = 0;
      }
      if ( this[9] )
      {
        *(_DWORD *)(this[10] + 4) = result;
        this[10] = result;
        ++this[12];
      }
      else
      {
        this[9] = result;
        this[11] = result;
        this[10] = result;
        result = this[12] + 1;
        this[12] = result;
      }
    }
  }
  return result;
}
