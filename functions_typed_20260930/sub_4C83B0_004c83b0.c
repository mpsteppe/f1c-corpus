int __thiscall sub_4C83B0(int *this)
{
  int v2; // edi
  LPVOID **v3; // ebp
  bool v4; // zf
  char *v5; // eax
  char *v6; // eax
  int result; // eax
  int v8; // ecx
  int v9; // edi
  int v10; // eax
  int v11; // edx
  int v12; // et2
  char *v13; // eax

  v2 = *this;
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8) == 0;
    v2 = *(_DWORD *)(v2 + 4);
    if ( !v4 && *v3 )
      ConditionalFreeWithBit0Flag(*v3, 1);
    FreeWrapper_7bcf(v3);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  v5 = (char *)dword_5EC448;
  if ( !dword_5EC448 )
    v5 = byte_5EA438;
  sub_4C84A0(aWav, v5);
  v6 = (char *)dword_5EC448;
  if ( !dword_5EC448 )
    v6 = byte_5EA438;
  result = sub_4C84A0(aMp3, v6);
  v9 = this[3];
  if ( v9 > 0 )
  {
    v10 = RandLCGRandomNumberGenerator(v8);
    v12 = v10 % v9;
    result = v10 / v9;
    v11 = v12;
    if ( v12 < 0 || v11 >= this[3] )
    {
      this[2] = 0;
    }
    else
    {
      result = *this;
      for ( this[2] = *this; v11 > 0; this[2] = *(_DWORD *)(result + 4) )
      {
        result = this[2];
        if ( !result )
          break;
        --v11;
      }
    }
  }
  if ( !this[3] && dword_8AC4C4 )
  {
    v13 = (char *)dword_5EC448;
    if ( !dword_5EC448 )
      v13 = byte_5EA438;
    off_5D325C[0] = v13;
    return (*(int (__stdcall **)(char **, int))(*(_DWORD *)dword_8AC4C4 + 72))(off_5D325C, dword_5D3254);
  }
  return result;
}

