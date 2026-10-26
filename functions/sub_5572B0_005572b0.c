_DWORD *__thiscall sub_5572B0(_DWORD *this)
{
  int v1; // edx
  _DWORD *v2; // eax
  int v3; // edx
  _DWORD *v4; // eax
  int v5; // edx
  _DWORD *result; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // ecx

  v1 = this[109];
  if ( v1 )
  {
    v2 = (_DWORD *)(this[110] + 520);
    do
    {
      *v2 = 0;
      v2 += 132;
      --v1;
    }
    while ( v1 );
  }
  v3 = this[113];
  if ( v3 )
  {
    v4 = (_DWORD *)(this[114] + 520);
    do
    {
      *v4 = 0;
      v4 += 132;
      --v3;
    }
    while ( v3 );
  }
  v5 = this[111];
  result = (_DWORD *)this[112];
  if ( v5 )
  {
    result += 130;
    do
    {
      *result = 0;
      result += 132;
      --v5;
    }
    while ( v5 );
  }
  v7 = this[115];
  v8 = this[116];
  if ( v7 )
  {
    result = (_DWORD *)(v8 + 520);
    v9 = v7;
    do
    {
      *result = 0;
      result += 132;
      --v9;
    }
    while ( v9 );
  }
  return result;
}
