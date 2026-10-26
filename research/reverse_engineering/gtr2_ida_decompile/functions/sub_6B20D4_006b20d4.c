int __thiscall sub_6B20D4(_DWORD *this)
{
  int v2; // eax
  unsigned int v3; // ecx
  int v4; // edx
  _DWORD *v5; // eax
  int result; // eax
  _DWORD *v7; // eax
  bool v8; // cc
  int v9; // eax
  unsigned int i; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // ebx
  int v14; // edx
  _BYTE *v15; // ecx
  int v16; // ecx
  _DWORD v17[2]; // [esp+Ch] [ebp-18h] BYREF
  _DWORD v18[2]; // [esp+14h] [ebp-10h] BYREF
  int v19; // [esp+1Ch] [ebp-8h]
  unsigned int v20; // [esp+20h] [ebp-4h]

  v2 = this[64];
  v3 = *(_DWORD *)(v2 + 12);
  v20 = 0;
  if ( v3 )
  {
    v4 = this[5];
    v5 = *(_DWORD **)(v2 + 16);
    do
    {
      if ( (*(_BYTE *)(*(_DWORD *)(v4 + 4 * *v5) + 3) & 2) == 0 )
        break;
      ++v20;
      ++v5;
    }
    while ( v20 < v3 );
  }
  if ( v20 < v3 )
    return sub_6CCB66(
             14,
             *(_DWORD *)(this[64] + 16),
             *(_DWORD *)(this[64] + 8),
             *(_DWORD *)(this[64] + 12),
             *(_DWORD *)(this[64] + 4),
             0,
             0);
  v7 = (_DWORD *)this[64];
  if ( (unsigned __int16)this[50] >= 0x200u )
    return sub_6CCB66(78, v7[4], v7[2], v7[3], v7[1], 0, 0);
  v8 = v7[3] <= v7[1];
  v19 = 0;
  if ( v8 )
  {
    v20 = 0;
    if ( v3 )
    {
      do
      {
        v11 = this[64];
        v12 = this[5];
        v13 = 4 * v20;
        v14 = *(_DWORD *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(4 * v20 + *(_DWORD *)(v11 + 16))) + 16);
        v15 = *(_BYTE **)(v12 + 4 * *(_DWORD *)(4 * v20 + *(_DWORD *)(v11 + 8)));
        if ( !v14 && (*v15 & 2) != 0 || v14 == 2 || v14 == 3 && (v16 = *(_DWORD *)v15, (v16 & 4) != 0) && (v16 & 8) != 0 )
        {
          result = sub_6CB29C(
                     78,
                     v13 + *(_DWORD *)(this[64] + 16),
                     1,
                     v13 + *(_DWORD *)(this[64] + 8),
                     0,
                     0,
                     1,
                     0,
                     0,
                     0,
                     0);
        }
        else
        {
          if ( !v19 )
          {
            result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD *, int, _DWORD, _DWORD))(*this + 128))(
                       this,
                       this[63],
                       v17,
                       4,
                       0,
                       0);
            if ( result < 0 )
              return result;
            v19 = 1;
          }
          result = sub_6CB29C(78, v18, 1, v13 + *(_DWORD *)(this[64] + 8), 0, 0, 1, 0, 0, 0, 0);
          if ( result < 0 )
            return result;
          result = sub_6CB29C(1, v13 + *(_DWORD *)(this[64] + 16), 1, v18, 0, 0, 1, 0, 0, 0, 0);
        }
        if ( result < 0 )
          return result;
        ++v20;
      }
      while ( v20 < *(_DWORD *)(this[64] + 12) );
    }
    return 0;
  }
  result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD *, int, _DWORD, _DWORD))(*this + 128))(
             this,
             this[63],
             v17,
             4,
             0,
             0);
  if ( result >= 0 )
  {
    result = sub_6CB29C(78, v18, 1, *(_DWORD *)(this[64] + 8), 0, 0, 1, 0, 0, 0, 0);
    if ( result >= 0 )
    {
      v9 = this[64];
      for ( i = 0; i < *(_DWORD *)(v9 + 12); ++i )
        v17[i] = v18[0];
      result = sub_6CB29C(
                 1,
                 *(_DWORD *)(this[64] + 16),
                 *(_DWORD *)(this[64] + 12),
                 v17,
                 0,
                 0,
                 *(_DWORD *)(this[64] + 12),
                 0,
                 0,
                 0,
                 0);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}
