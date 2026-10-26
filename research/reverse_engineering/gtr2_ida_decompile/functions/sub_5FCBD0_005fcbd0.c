_DWORD *__thiscall sub_5FCBD0(_DWORD *this, int a2)
{
  int v2; // ebx
  _DWORD *result; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // edi
  unsigned int *v9; // eax
  int i; // edi
  int v11; // edx
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  int v15; // ebp

  v2 = a2;
  if ( a2 )
  {
    if ( a2 >= 0 )
    {
      if ( a2 > this[11] )
        v2 = this[11];
    }
    else
    {
      v2 = 0;
    }
    result = (_DWORD *)this[11];
    for ( i = 0; i < (int)result; ++i )
    {
      sub_5FCB20(this, i);
      result = (_DWORD *)this[11];
    }
    v11 = 0;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v13 = this[12];
        result = (_DWORD *)this[11];
        if ( v13 < (int)result && v11 < (int)result )
        {
          v14 = this[13];
          v15 = *(_DWORD *)(v14 + v12);
          result = (_DWORD *)(v12 + v14);
          if ( (v15 & 0x100) == 0 )
          {
            result[1] = v13;
            result[32] = this[24] + ((this[12] * this[9]) << 6);
            *(_DWORD *)(this[14] + 4 * this[12]) = result;
            *result |= 0x100u;
            ++this[12];
          }
        }
        ++v11;
        v12 += 132;
      }
      while ( v11 < v2 );
    }
  }
  else
  {
    result = (_DWORD *)this[11];
    v5 = 0;
    if ( (int)result > 0 )
    {
      v6 = 0;
      do
      {
        v7 = this[13];
        v8 = *(_DWORD *)(v7 + v6);
        v9 = (unsigned int *)(v6 + v7);
        v9[1] = 0;
        *v9 = v8 & 0xFFFFFEFF;
        result = (_DWORD *)this[11];
        ++v5;
        v6 += 132;
      }
      while ( v5 < (int)result );
    }
    this[12] = 0;
  }
  return result;
}
