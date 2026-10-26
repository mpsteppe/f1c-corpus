int __thiscall sub_6B1E0E(_DWORD *this)
{
  bool v2; // cc
  int result; // eax
  int v4; // eax
  unsigned int i; // ecx
  int v6; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  _DWORD *v9; // eax
  int v10; // [esp+Ch] [ebp-2Ch] BYREF
  _DWORD v11[3]; // [esp+10h] [ebp-28h] BYREF
  int v12; // [esp+1Ch] [ebp-1Ch]
  unsigned int v13; // [esp+20h] [ebp-18h]
  int v14; // [esp+24h] [ebp-14h]
  int v15; // [esp+28h] [ebp-10h]
  unsigned int v16; // [esp+2Ch] [ebp-Ch]
  unsigned int v17; // [esp+30h] [ebp-8h]
  unsigned int v18; // [esp+34h] [ebp-4h]

  v2 = *(_DWORD *)(this[64] + 12) <= *(_DWORD *)(this[64] + 4);
  v14 = 0;
  if ( v2 )
  {
    v15 = 0;
    while ( 1 )
    {
      v6 = this[64];
      v7 = *(_DWORD *)(v6 + 12);
      v18 = 0;
      v13 = v7;
      if ( v7 )
        break;
LABEL_37:
      if ( (unsigned int)++v15 >= 2 )
        return 0;
    }
    v16 = 1;
    v17 = 2;
    while ( 1 )
    {
      v8 = 4 * v18;
      v9 = (_DWORD *)(4 * v18 + *(_DWORD *)(v6 + 16));
      v12 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v9) + 16);
      if ( v12 == 1 && v17 < v13 )
      {
        if ( v15 == 1 )
        {
          result = sub_6CB29C(
                     78,
                     v8 + *(_DWORD *)(this[64] + 16),
                     1,
                     v8 + *(_DWORD *)(this[64] + 8),
                     0,
                     0,
                     1,
                     0,
                     0,
                     0,
                     0);
LABEL_22:
          if ( result < 0 )
            return result;
        }
      }
      else
      {
        if ( v16 < v13 )
        {
          if ( v12 || *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v9[1]) + 16) != 1 )
          {
            if ( !v15 )
            {
              if ( !v14 )
              {
                result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int, _DWORD, _DWORD))(*this + 128))(
                           this,
                           this[63],
                           &v10,
                           4,
                           0,
                           0);
                if ( result < 0 )
                  return result;
                v14 = 1;
              }
              result = sub_6CB29C(19, &v10, 2, v8 + *(_DWORD *)(this[64] + 8), 0, 0, 2, 0, 0, 0, 0);
              if ( result < 0 )
                return result;
              result = sub_6CB29C(1, v8 + *(_DWORD *)(this[64] + 16), 2, &v10, 0, 0, 2, 0, 0, 0, 0);
LABEL_34:
              if ( result < 0 )
                return result;
            }
          }
          else if ( v15 == 1 )
          {
            result = sub_6CB29C(
                       19,
                       v8 + *(_DWORD *)(this[64] + 16),
                       2,
                       v8 + *(_DWORD *)(this[64] + 8),
                       0,
                       0,
                       2,
                       0,
                       0,
                       0,
                       0);
            goto LABEL_34;
          }
          v17 += 2;
          v18 += 2;
          v16 += 2;
          goto LABEL_36;
        }
        if ( !v15 )
        {
          if ( !v14 )
          {
            result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int, _DWORD, _DWORD))(*this + 128))(
                       this,
                       this[63],
                       &v10,
                       4,
                       0,
                       0);
            if ( result < 0 )
              return result;
            v14 = 1;
          }
          result = sub_6CB29C(78, v11, 1, v8 + *(_DWORD *)(this[64] + 8), 0, 0, 1, 0, 0, 0, 0);
          if ( result < 0 )
            return result;
          result = sub_6CB29C(1, v8 + *(_DWORD *)(this[64] + 16), 1, v11, 0, 0, 1, 0, 0, 0, 0);
          goto LABEL_22;
        }
      }
      ++v18;
      ++v17;
      ++v16;
LABEL_36:
      v6 = this[64];
      v13 = *(_DWORD *)(v6 + 12);
      if ( v18 >= v13 )
        goto LABEL_37;
    }
  }
  result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int, _DWORD, _DWORD))(*this + 128))(
             this,
             this[63],
             &v10,
             4,
             0,
             0);
  if ( result >= 0 )
  {
    result = sub_6CB29C(78, v11, 1, *(_DWORD *)(this[64] + 8), 0, 0, 1, 0, 0, 0, 0);
    if ( result >= 0 )
    {
      v4 = this[64];
      for ( i = 0; i < *(_DWORD *)(v4 + 12); ++i )
        v11[i - 1] = v11[0];
      result = sub_6CB29C(
                 1,
                 *(_DWORD *)(this[64] + 16),
                 *(_DWORD *)(this[64] + 12),
                 &v10,
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
