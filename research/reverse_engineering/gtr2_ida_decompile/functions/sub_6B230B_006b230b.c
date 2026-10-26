int __thiscall sub_6B230B(_DWORD *this)
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
  _DWORD v11[2]; // [esp+Ch] [ebp-18h] BYREF
  _DWORD v12[2]; // [esp+14h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-8h]
  unsigned int v14; // [esp+20h] [ebp-4h]

  v2 = this[64];
  v3 = *(_DWORD *)(v2 + 12);
  v14 = 0;
  if ( v3 )
  {
    v4 = this[5];
    v5 = *(_DWORD **)(v2 + 16);
    do
    {
      if ( (*(_BYTE *)(*(_DWORD *)(v4 + 4 * *v5) + 3) & 2) == 0 )
        break;
      ++v14;
      ++v5;
    }
    while ( v14 < v3 );
  }
  if ( v14 < v3 )
    return sub_6CCB66(
             15,
             *(_DWORD *)(this[64] + 16),
             *(_DWORD *)(this[64] + 8),
             *(_DWORD *)(this[64] + 12),
             *(_DWORD *)(this[64] + 4),
             0,
             0);
  v7 = (_DWORD *)this[64];
  if ( (unsigned __int16)this[50] >= 0x200u )
    return sub_6CCB66(79, v7[4], v7[2], v7[3], v7[1], 0, 0);
  v8 = v7[3] <= v7[1];
  v13 = 0;
  if ( v8 )
  {
    v14 = 0;
    if ( v3 )
    {
      do
      {
        if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(4 * v14 + *(_DWORD *)(this[64] + 16))) + 16) == 2 )
        {
          result = sub_6CB29C(
                     79,
                     4 * v14 + *(_DWORD *)(this[64] + 16),
                     1,
                     4 * v14 + *(_DWORD *)(this[64] + 8),
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
          if ( !v13 )
          {
            result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD *, int, _DWORD, _DWORD))(*this + 128))(
                       this,
                       this[63],
                       v11,
                       4,
                       0,
                       0);
            if ( result < 0 )
              return result;
            v13 = 1;
          }
          result = sub_6CB29C(79, v12, 1, 4 * v14 + *(_DWORD *)(this[64] + 8), 0, 0, 1, 0, 0, 0, 0);
          if ( result < 0 )
            return result;
          result = sub_6CB29C(1, 4 * v14 + *(_DWORD *)(this[64] + 16), 1, v12, 0, 0, 1, 0, 0, 0, 0);
        }
        if ( result < 0 )
          return result;
        ++v14;
      }
      while ( v14 < *(_DWORD *)(this[64] + 12) );
    }
    return 0;
  }
  result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD *, int, _DWORD, _DWORD))(*this + 128))(
             this,
             this[63],
             v11,
             4,
             0,
             0);
  if ( result >= 0 )
  {
    result = sub_6CB29C(79, v12, 1, *(_DWORD *)(this[64] + 8), 0, 0, 1, 0, 0, 0, 0);
    if ( result >= 0 )
    {
      v9 = this[64];
      for ( i = 0; i < *(_DWORD *)(v9 + 12); ++i )
        v11[i] = v12[0];
      result = sub_6CB29C(
                 1,
                 *(_DWORD *)(this[64] + 16),
                 *(_DWORD *)(this[64] + 12),
                 v11,
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
