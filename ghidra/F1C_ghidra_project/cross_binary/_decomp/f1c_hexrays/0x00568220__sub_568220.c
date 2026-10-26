// f1c  0x00568220  size=244
int __thiscall sub_568220(_DWORD *this, const char *a2)
{
  int result; // eax
  int *v4; // eax
  int v5; // esi
  char *v6; // eax
  int v7; // eax
  int *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // esi
  int v11; // ebx
  int v12; // eax

  result = -1;
  if ( a2 )
  {
    v4 = (int *)this[9];
    this[11] = v4;
    if ( !v4 )
      goto LABEL_13;
    v5 = *v4;
    if ( !*v4 )
      goto LABEL_13;
    while ( 1 )
    {
      v6 = *(char **)v5;
      if ( !*(_DWORD *)v5 )
        v6 = byte_5EA438;
      if ( !sub_588410(v6, a2) )
        break;
      v7 = this[11];
      if ( v7 )
        this[11] = *(_DWORD *)(v7 + 4);
      v8 = (int *)this[11];
      if ( v8 )
      {
        v5 = *v8;
        if ( *v8 )
          continue;
      }
      goto LABEL_13;
    }
    result = *(_DWORD *)(v5 + 8);
    if ( result == -1 )
    {
LABEL_13:
      v9 = (_DWORD *)sub_587C03(12);
      v10 = v9;
      if ( v9 )
      {
        v11 = this[13];
        this[13] = v11 + 1;
        *v9 = 0;
        v9[1] = -1;
        sub_566650((int)v9, a2);
        v10[2] = v11;
      }
      else
      {
        v10 = 0;
      }
      if ( v10 )
      {
        v12 = sub_587C03(12);
        if ( v12 )
        {
          *(_DWORD *)v12 = v10;
          *(_DWORD *)(v12 + 4) = 0;
          *(_BYTE *)(v12 + 8) = 1;
        }
        else
        {
          v12 = 0;
        }
        if ( !this[9] )
        {
          this[9] = v12;
          this[11] = v12;
          this[10] = v12;
          ++this[12];
          return v10[2];
        }
        *(_DWORD *)(this[10] + 4) = v12;
        this[10] = v12;
        ++this[12];
      }
      return v10[2];
    }
  }
  return result;
}
