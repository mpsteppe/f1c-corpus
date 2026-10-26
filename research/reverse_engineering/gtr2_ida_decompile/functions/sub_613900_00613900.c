int __thiscall sub_613900(int this, int a2, int a3)
{
  int v3; // ebx
  int v5; // ecx
  int v6; // edi
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // ebp
  int v12; // edi
  int v13; // eax
  _DWORD *v14; // ebx
  int i; // eax
  int result; // eax
  int v17; // [esp+10h] [ebp-4h]

  v3 = a3;
  v5 = *(_DWORD *)(this + 24);
  v6 = v5 / 4096;
  if ( v5 / 4096 == (v5 + a3 - 1) / 4096 && v6 < *(_DWORD *)(this + 16) )
  {
    v7 = *(_DWORD *)(*(_DWORD *)(this + 12) + 4 * v6);
    v8 = v5 % 4096;
    v9 = 0;
    if ( a3 > 0 )
    {
      v10 = v8 + v7;
      do
      {
        *(_BYTE *)(v10 + v9) = *(_BYTE *)(this + 24) ^ *(_BYTE *)(v9 + a2);
        ++v9;
        ++*(_DWORD *)(this + 24);
      }
      while ( v9 < a3 );
    }
  }
  else
  {
    v11 = 0;
    if ( a3 > 0 )
    {
      do
      {
        v12 = *(_DWORD *)(this + 24) / 4096;
        v13 = *(_DWORD *)(this + 16);
        v17 = *(_DWORD *)(this + 24) % 4096;
        if ( v12 >= v13 )
        {
          v14 = operator new(4 * v13 + 4);
          for ( i = 0; i < *(_DWORD *)(this + 16); ++i )
            v14[i] = *(_DWORD *)(*(_DWORD *)(this + 12) + 4 * i);
          j__free(*(void **)(this + 12));
          *(_DWORD *)(this + 12) = v14;
          v3 = a3;
          *(_DWORD *)(*(_DWORD *)(this + 12) + 4 * (*(_DWORD *)(this + 16))++) = operator new(0x1000u);
        }
        *(_BYTE *)(v17 + *(_DWORD *)(*(_DWORD *)(this + 12) + 4 * v12)) = *(_BYTE *)(this + 24) ^ *(_BYTE *)(a2 + v11++);
        ++*(_DWORD *)(this + 24);
      }
      while ( v11 < v3 );
    }
  }
  result = *(_DWORD *)(this + 24);
  if ( *(_DWORD *)(this + 20) < result )
    *(_DWORD *)(this + 20) = result;
  return result;
}
