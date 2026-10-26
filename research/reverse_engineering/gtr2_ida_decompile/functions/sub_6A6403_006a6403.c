unsigned int __thiscall sub_6A6403(_DWORD *this, int a2, unsigned int a3, unsigned int a4, int a5, int a6, _DWORD *a7)
{
  unsigned int i; // ecx
  int v8; // edi
  unsigned int v9; // ebx
  int v10; // esi
  _DWORD *v11; // edx
  unsigned int v14; // [esp+4h] [ebp-4h]

  v14 = 0;
  *a7 = 0;
  for ( i = a3; i < a4; ++i )
  {
    v8 = *(_DWORD *)(a2 + 4 * i);
    v9 = 0;
    if ( v8 && *(_DWORD *)(v8 + 4) )
    {
      do
      {
        v10 = *(_DWORD *)(*(_DWORD *)(v8 + 8) + 4 * v9);
        v11 = *(_DWORD **)(this[5] + 4 * v10);
        if ( v10 == a5 || v11[14] == a5 )
        {
          v11[3] = *(_DWORD *)(a6 + 12);
          v11[4] = *(_DWORD *)(a6 + 16);
          v14 = i;
          *a7 = 1;
        }
        ++v9;
      }
      while ( v9 < *(_DWORD *)(v8 + 4) );
    }
  }
  return v14;
}
