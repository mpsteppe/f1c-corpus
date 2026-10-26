int __thiscall sub_6CCB66(
        _DWORD *this,
        int a2,
        _DWORD *a3,
        _DWORD *a4,
        unsigned int a5,
        unsigned int a6,
        int a7,
        int a8)
{
  int result; // eax
  _DWORD *v10; // ebx
  int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  bool v14; // cf
  unsigned int v15; // ecx
  unsigned int i; // edi
  unsigned int v17; // eax
  unsigned int v18; // ecx
  int v19; // eax
  unsigned int v20; // edi
  _DWORD *v21; // ecx
  int v22; // eax
  _DWORD *v23; // ecx
  _DWORD v24[4]; // [esp+4h] [ebp-30h] BYREF
  _DWORD v25[4]; // [esp+14h] [ebp-20h] BYREF
  _DWORD *v26; // [esp+24h] [ebp-10h]
  int v27; // [esp+28h] [ebp-Ch]
  BOOL v28; // [esp+2Ch] [ebp-8h]
  unsigned int v29; // [esp+30h] [ebp-4h]
  unsigned int v30; // [esp+4Ch] [ebp+18h]
  int v31; // [esp+4Ch] [ebp+18h]

  if ( a5 > a6 && a6 == 1 && **(_DWORD **)(this[64] + 8) == *a4 )
    return sub_6CCA8D(this, a2, 0);
  v10 = a3;
  v11 = 4 * *a4;
  v12 = 4 * *a3;
  if ( *(_DWORD *)(*(_DWORD *)(this[5] + v12) + 4) == *(_DWORD *)(*(_DWORD *)(v11 + this[5]) + 4)
    && *(_DWORD *)(*(_DWORD *)(this[5] + v12) + 8) == *(_DWORD *)(*(_DWORD *)(this[5] + v11) + 8)
    && *(_DWORD *)(*(_DWORD *)(this[5] + v12) + 12) == *(_DWORD *)(*(_DWORD *)(this[5] + v11) + 12) )
  {
    v13 = 0;
    v14 = a5 != 0;
    if ( a5 )
    {
      do
      {
        v30 = 0;
        if ( v13 )
        {
          do
          {
            if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a4[v13]) + 16) == *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a3[v30])
                                                                                   + 16) )
              break;
            ++v30;
          }
          while ( v30 < v13 );
          if ( v30 < v13 )
            break;
        }
        ++v13;
      }
      while ( v13 < a5 );
      v14 = v13 < a5;
    }
    v28 = v14;
    if ( v14 )
    {
      v15 = 0;
      for ( i = 0; v15 < a5; ++v15 )
      {
        v17 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a3[v15]) + 16);
        if ( i <= v17 )
          i = v17 + 1;
      }
      result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD *, unsigned int, _DWORD, _DWORD))(*this + 128))(
                 this,
                 this[63],
                 v24,
                 i,
                 0,
                 0);
      v18 = 0;
      if ( result < 0 )
        return result;
      if ( a5 )
      {
        v19 = this[5];
        do
        {
          v25[v18] = v24[*(_DWORD *)(*(_DWORD *)(v19 + 4 * *(_DWORD *)((char *)&v25[v18] + (char *)a3 - (char *)v25))
                                   + 16)];
          ++v18;
        }
        while ( v18 < a5 );
      }
      v26 = a3;
      v10 = v25;
      a3 = v25;
    }
  }
  else
  {
    v28 = 0;
  }
  v20 = 0;
  if ( a5 )
  {
    while ( 1 )
    {
      v31 = 1;
      if ( v20 + 1 < a5 )
      {
        v21 = &a4[v20];
        v22 = this[5];
        v27 = *(_DWORD *)(*(_DWORD *)(v22 + 4 * *v21) + 16);
        v29 = v20 + 1;
        v23 = v21 + 1;
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)(v22 + 4 * *v23) + 16) != v27 )
            break;
          ++v31;
          ++v29;
          ++v23;
        }
        while ( v29 < a5 );
        v10 = a3;
      }
      result = sub_6CB29C(this, a2, &v10[v20], v31, &a4[v20], 0, 0, v31, a7, a7, a7, 0);
      if ( result < 0 )
        break;
      v20 += v31;
      if ( v20 >= a5 )
        goto LABEL_34;
    }
  }
  else
  {
LABEL_34:
    if ( !v28 )
      return 0;
    result = sub_6CB29C(this, 1, v26, a5, v10, 0, 0, a5, 0, 0, 0, 0);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
