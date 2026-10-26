int __thiscall sub_4034D0(_DWORD *this)
{
  int result; // eax
  int v3; // ecx
  void *v4; // ebp
  int v5; // esi
  int v6; // ecx
  int v7; // ebx

  result = this[77];
  if ( result )
  {
    v3 = *(_DWORD *)(result - 4);
    v4 = (void *)(result - 4);
    v5 = result + 316 * v3;
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        v5 -= 316;
        EmptyStub_0170(v5);
        --v7;
      }
      while ( v7 );
    }
    FreeWrapper_7bcf(v4);
    result = 0;
    this[77] = 0;
    this[76] = 0;
  }
  else
  {
    this[77] = 0;
    this[76] = 0;
  }
  return result;
}

