char __thiscall sub_4F7DF0(_DWORD *this, int a2)
{
  int v2; // edx
  char result; // al
  int v4; // edi
  _DWORD *v5; // ebp
  int v6; // esi
  _DWORD *v7; // edx

  v2 = this[96];
  result = 0;
  if ( v2 > 0 )
  {
    v4 = 1;
    v5 = this;
    do
    {
      if ( a2 == *v5 )
      {
        result = 1;
        v6 = v4;
        if ( v4 < v2 )
        {
          v7 = v5;
          do
          {
            *v7 = v7[2];
            v7[1] = v7[3];
            ++v6;
            v7 += 2;
          }
          while ( v6 < this[96] );
        }
        this[2 * v6 - 2] = -2;
        this[2 * v6 - 1] = -1082130432;
        --this[96];
      }
      v2 = this[96];
      v5 += 2;
      ++v4;
    }
    while ( v4 - 1 < v2 );
  }
  return result;
}
