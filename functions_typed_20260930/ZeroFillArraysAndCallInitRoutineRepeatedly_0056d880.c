void __thiscall sub_56D880(int *this, int a2, int a3)
{
  int v3; // esi
  int *v5; // ecx
  int i; // eax
  int v7; // edi
  int v8; // edi
  int v9; // [esp+Ch] [ebp-4h]

  v3 = 0;
  if ( a3 > 0 )
  {
    v5 = (int *)a2;
    v9 = a3;
    do
    {
      for ( i = 0; i < a3; ++i )
      {
        v7 = *v5;
        *(_DWORD *)(v7 + 8 * i) = 0;
        *(_DWORD *)(v7 + 8 * i + 4) = 0;
      }
      ++v5;
      --v9;
    }
    while ( v9 );
  }
  if ( *this > 0 )
  {
    v8 = 0;
    do
    {
      sub_568FB0((_DWORD *)(v8 + this[1]), a2);
      ++v3;
      v8 += 580;
    }
    while ( v3 < *this );
  }
}

