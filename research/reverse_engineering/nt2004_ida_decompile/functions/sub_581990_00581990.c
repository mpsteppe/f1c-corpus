int __thiscall sub_581990(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // edi
  int v5; // ebx
  int result; // eax
  int v7; // edi
  int v8; // ebx

  v2 = 0;
  if ( (int)this[2] > 0 )
  {
    v3 = 0;
    do
    {
      sub_57FD00((_DWORD *)(v3 + this[3]));
      ++v2;
      v3 += 48;
    }
    while ( v2 < this[2] );
  }
  v4 = 0;
  if ( (int)this[4] > 0 )
  {
    v5 = 0;
    do
    {
      sub_57FDB0((_DWORD *)(v5 + this[5]));
      ++v4;
      v5 += 48;
    }
    while ( v4 < this[4] );
  }
  result = this[6];
  v7 = 0;
  if ( result > 0 )
  {
    v8 = 0;
    do
    {
      sub_580060(v8 + this[7]);
      result = this[6];
      ++v7;
      v8 += 72;
    }
    while ( v7 < result );
  }
  return result;
}
