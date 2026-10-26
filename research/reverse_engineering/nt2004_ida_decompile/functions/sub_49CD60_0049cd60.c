char __thiscall sub_49CD60(_DWORD *this, int a2, char a3)
{
  char result; // al
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  CHAR *v7; // ebp
  _DWORD *v8; // eax

  result = 0;
  if ( a2 )
  {
    v5 = operator new(0x1Cu);
    if ( v5 )
    {
      *v5 = 0;
      v5[1] = 0;
      v5[2] = -1;
      v5[5] = 0;
      v5[6] = -1;
      v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    sub_4AFE40(a3);
    sub_4AFF20(this[3], this[1]);
    sub_4B0090(*(_DWORD *)(a2 + 20), *(float *)(a2 + 24));
    v7 = *(CHAR **)a2;
    if ( !*(_DWORD *)a2 )
      v7 = &byte_629120;
    sub_578600(v7);
    if ( v6 )
    {
      v8 = operator new(0xCu);
      if ( v8 )
      {
        *v8 = v6;
        v8[1] = 0;
        *((_BYTE *)v8 + 8) = 1;
      }
      else
      {
        v8 = 0;
      }
      if ( !this[21] )
      {
        this[21] = v8;
        this[23] = v8;
        this[22] = v8;
        ++this[24];
        return 1;
      }
      *(_DWORD *)(this[22] + 4) = v8;
      this[22] = v8;
      ++this[24];
    }
    return 1;
  }
  return result;
}
