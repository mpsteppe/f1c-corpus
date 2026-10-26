int __thiscall sub_5BC1F0(_DWORD *this, double *a2)
{
  int result; // eax
  int v4; // ebx
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int i; // [esp+24h] [ebp-4h]

  result = this[111];
  v4 = 0;
  for ( i = result; v4 < i; ++v4 )
  {
    v5 = *(_DWORD **)(this[113] + 4 * v4);
    v6 = this[135];
    if ( v6 < v5[75] )
    {
      v7 = *(_DWORD *)(v5[77] + 8 * v6 + 4);
      if ( v7 )
      {
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 12))(v7) )
        {
          v8 = v5[77] + 8 * this[135];
          if ( *(_DWORD *)(v8 + 4) )
            v9 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v8 + 4) + 12))(*(_DWORD *)(v8 + 4));
          else
            v9 = 0;
          (*(void (__thiscall **)(int, _DWORD *, _DWORD *, _DWORD, _DWORD))(*(_DWORD *)v9 + 4))(
            v9,
            this,
            v5,
            COERCE_UNSIGNED_INT64(*a2),
            HIDWORD(COERCE_UNSIGNED_INT64(*a2)));
        }
      }
    }
    v10 = this[135];
    if ( v10 < v5[81] )
    {
      v11 = *(_DWORD *)(v5[83] + 8 * v10 + 4);
      if ( v11 )
      {
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 12))(v11) )
        {
          v12 = v5[83] + 8 * this[135];
          if ( *(_DWORD *)(v12 + 4) )
            v13 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v12 + 4) + 12))(*(_DWORD *)(v12 + 4));
          else
            v13 = 0;
          (*(void (__thiscall **)(int, _DWORD *, _DWORD *, _DWORD, _DWORD))(*(_DWORD *)v13 + 4))(
            v13,
            this,
            v5,
            COERCE_UNSIGNED_INT64(*a2),
            HIDWORD(COERCE_UNSIGNED_INT64(*a2)));
        }
      }
    }
    result = i;
  }
  return result;
}
