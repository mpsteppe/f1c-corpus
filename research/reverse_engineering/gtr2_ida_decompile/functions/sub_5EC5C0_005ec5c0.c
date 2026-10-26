int __thiscall sub_5EC5C0(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // edx
  int v6; // edx
  int v7; // esi
  int v8; // edx
  int v9; // esi
  int v10; // [esp+10h] [ebp-4h]

  result = this[90];
  v3 = 0;
  v10 = 0;
  if ( result > 0 )
  {
    do
    {
      v4 = this[91];
      v5 = *(_DWORD *)(v4 + v3);
      result = v3 + v4;
      if ( (v5 & 0x40) != 0 )
      {
        v6 = 0;
        if ( *(int *)(result + 8) > 0 )
        {
          v7 = 0;
          do
          {
            *(_DWORD *)(v7 + *(_DWORD *)(result + 32) + 24) = a2;
            ++v6;
            v7 += 64;
          }
          while ( v6 < *(_DWORD *)(result + 8) );
        }
      }
      else
      {
        if ( (v5 & 8) == 0 )
          return result;
        v8 = 0;
        if ( *(int *)(result + 8) > 0 )
        {
          v9 = 0;
          do
          {
            *(_DWORD *)(v9 + *(_DWORD *)(result + 32) + 24) = a2;
            ++v8;
            v9 += 88;
          }
          while ( v8 < *(_DWORD *)(result + 8) );
        }
      }
      result = v10 + 1;
      v3 += 108;
      ++v10;
    }
    while ( v10 < this[90] );
  }
  *this &= ~0x800u;
  return result;
}
