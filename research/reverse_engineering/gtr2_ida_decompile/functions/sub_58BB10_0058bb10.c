int __thiscall sub_58BB10(int *this, int a2, int a3, float a4, int a5, int a6, float a7)
{
  int result; // eax
  int v9; // ebx
  float *i; // esi
  int v12; // esi
  int v13; // ebx
  int j; // esi
  float v15; // [esp+18h] [ebp-20h]
  float v16; // [esp+18h] [ebp-20h]
  float v17; // [esp+1Ch] [ebp-1Ch]
  float v18; // [esp+1Ch] [ebp-1Ch]
  float v19; // [esp+1Ch] [ebp-1Ch]
  float v20; // [esp+3Ch] [ebp+4h]

  result = *this;
  v9 = 0;
  if ( *this > 0 )
  {
    for ( i = (float *)(this + 1); a4 > (double)i[1] || a4 < (double)*i; i += 4 )
    {
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 4 * v9) + 8))(*(_DWORD *)(a2 + 4 * v9));
      result = *this;
      if ( ++v9 >= *this )
        return result;
    }
    v12 = v9 + 1;
    if ( v9 + 1 == *this || a4 < (double)*(float *)&this[4 * v12 + 1] )
    {
      v19 = a4 * *(float *)&this[4 * v9 + 4];
      for ( result = (*(int (__stdcall **)(int, int, int, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 4 * v9) + 4))(
                       a3,
                       a5,
                       a6,
                       LODWORD(a7),
                       LODWORD(v19),
                       0); v12 < *this; ++v12 )
      {
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 4 * v12) + 8))(*(_DWORD *)(a2 + 4 * v12));
        result = *this;
      }
    }
    else
    {
      v13 = v9 + 1;
      v20 = (a4 - *(float *)&this[4 * v12 + 1]) * *(float *)&this[4 * v12 + 3];
      v17 = a4 * *(float *)&this[4 * v13];
      v15 = (1.0 - v20) * a7;
      (*(void (__thiscall **)(_DWORD, int, int, int, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 4 * v13 - 4) + 4))(
        *(_DWORD *)(a2 + 4 * v13 - 4),
        a3,
        a5,
        a6,
        LODWORD(v15),
        LODWORD(v17),
        0);
      v18 = a4 * *(float *)&this[4 * v12 + 4];
      v16 = v20 * a7;
      (*(void (__thiscall **)(_DWORD, int, int, int, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 4 * v12) + 4))(
        *(_DWORD *)(a2 + 4 * v12),
        a3,
        a5,
        a6,
        LODWORD(v16),
        LODWORD(v18),
        0);
      result = *this;
      for ( j = v12 + 1; j < *this; ++j )
      {
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 4 * j) + 8))(*(_DWORD *)(a2 + 4 * j));
        result = *this;
      }
    }
  }
  return result;
}
