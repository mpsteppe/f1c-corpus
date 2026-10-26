int __thiscall sub_5BD5F0(_DWORD *this)
{
  int i; // esi
  int v3; // ecx
  int result; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // esi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int j; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < this[105]; ++i )
    sub_5BD330((_DWORD *)(this[107] + 8 * i), 0);
  v3 = this[111];
  result = 0;
  v13 = v3;
  for ( j = 0; result < v3; j = result )
  {
    v5 = *(_DWORD *)(this[113] + 4 * result);
    v6 = 0;
    if ( *(int *)(v5 + 300) > 0 )
    {
      do
      {
        v7 = 8 * v6;
        v8 = *(_DWORD *)(*(_DWORD *)(v5 + 308) + 8 * v6 + 4);
        if ( v8 && (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 12))(v8) )
        {
          v9 = *(_DWORD *)(v5 + 308);
          v10 = *(_DWORD *)(v9 + v7 + 4);
          v11 = v7 + v9;
          if ( v10 )
            (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v11 + 4) + 12))(*(_DWORD *)(v11 + 4));
          sub_5C3E40(2);
        }
        ++v6;
      }
      while ( v6 < *(_DWORD *)(v5 + 300) );
      result = j;
      v3 = v13;
    }
    ++result;
  }
  return result;
}
