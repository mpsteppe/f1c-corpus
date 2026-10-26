int __thiscall sub_6AF146(_DWORD *this, char **a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // ecx
  bool v6; // zf
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // edx
  int v11; // edx
  unsigned int v12; // ecx
  int v13; // ebx
  int v14; // eax
  unsigned int j; // eax
  int result; // eax
  _DWORD *v17; // eax
  char *v18; // eax
  int v19; // eax
  unsigned int k; // ecx
  unsigned int m; // eax
  _DWORD *v22; // ecx
  _DWORD v23[4]; // [esp+Ch] [ebp-2Ch] BYREF
  _DWORD v24[4]; // [esp+1Ch] [ebp-1Ch] BYREF
  int v25; // [esp+2Ch] [ebp-Ch]
  int v26; // [esp+30h] [ebp-8h]
  int v27; // [esp+34h] [ebp-4h]
  int i; // [esp+48h] [ebp+10h]

  v5 = 0;
  v6 = a4 == 0;
  if ( a4 )
  {
    v7 = this[64];
    v8 = *(_DWORD *)(v7 + 8);
    v9 = **(_DWORD **)(v7 + 16);
    v26 = v8;
    v10 = this[5];
    v25 = *(_DWORD *)(*(_DWORD *)(v10 + 4 * v9) + 4);
    v27 = 0;
    do
    {
      if ( v25 == *(_DWORD *)(*(_DWORD *)(v10 + 4 * *(_DWORD *)(v27 + v26)) + 4)
        && *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 16)) + 12) == *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v27 + *(_DWORD *)(this[64] + 8)))
                                                                                                  + 12) )
      {
        break;
      }
      v27 += 4 * a3;
      ++v5;
    }
    while ( v5 < a4 );
    v6 = v5 == a4;
  }
  if ( v6 )
    return 0;
  v11 = *(_DWORD *)(this[64] + 8) + 4 * a3 * v5;
  memset(v24, 255, sizeof(v24));
  v12 = 0;
  v13 = 0;
  for ( i = v11; v12 < a3; v24[*(_DWORD *)(*(_DWORD *)(this[5] + 4 * v14) + 16)] = v14 )
    v14 = *(_DWORD *)(v11 + 4 * v12++);
  for ( j = 0; j < 4; ++j )
    v13 += v24[j] != -1;
  result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD *, int, _DWORD, _DWORD))(*this + 128))(
             this,
             this[63],
             v23,
             4,
             0,
             0);
  if ( result >= 0 )
  {
    v17 = (_DWORD *)sub_681186(116);
    if ( v17 )
      v18 = (char *)sub_680CEC(v17);
    else
      v18 = 0;
    *a2 = v18;
    if ( !v18 )
      return -2147024882;
    result = sub_6811D1(v18, v13 & 0xFFFFF | 0x10000000, v13, v13, 0);
    if ( result >= 0 )
    {
      result = sub_680D22(*a2, this[64]);
      if ( result >= 0 )
      {
        v19 = 0;
        for ( k = 0; k < 4; ++k )
        {
          if ( v24[k] != -1 )
          {
            *(_DWORD *)(v19 + *((_DWORD *)*a2 + 4)) = v23[k];
            *(_DWORD *)(v19 + *((_DWORD *)*a2 + 2)) = v24[k];
            v19 += 4;
          }
        }
        for ( m = 0; m < a3; *v22 = v23[*(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v22) + 16)] )
          v22 = (_DWORD *)(i + 4 * m++);
        return 0;
      }
    }
  }
  return result;
}
