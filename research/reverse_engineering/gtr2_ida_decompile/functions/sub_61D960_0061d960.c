int __thiscall sub_61D960(int *this, _DWORD *a2, int a3)
{
  int v3; // ebp
  _DWORD *v5; // ecx
  int v6; // edi
  int v7; // eax
  int result; // eax
  int v9; // esi
  int v10; // edi

  v3 = (int)a2;
  if ( a3 > 0 )
  {
    v5 = a2;
    v6 = a3;
    do
    {
      v7 = 0;
      if ( a3 >= 4 )
      {
        do
        {
          *(double *)(*v5 + 8 * v7) = 0.0;
          v7 += 4;
          *(double *)(*v5 + 8 * v7 - 24) = 0.0;
          *(double *)(*v5 + 8 * v7 - 16) = 0.0;
          *(double *)(*v5 + 8 * v7 - 8) = 0.0;
        }
        while ( v7 < a3 - 3 );
      }
      for ( ; v7 < a3; ++v7 )
        *(double *)(*v5 + 8 * v7) = 0.0;
      ++v5;
      --v6;
    }
    while ( v6 );
    v3 = (int)a2;
  }
  result = *this;
  v9 = 0;
  if ( *this > 0 )
  {
    v10 = 0;
    do
    {
      sub_618A70((_DWORD *)(v10 + this[1]), v3);
      result = *this;
      ++v9;
      v10 += 584;
    }
    while ( v9 < *this );
  }
  return result;
}
