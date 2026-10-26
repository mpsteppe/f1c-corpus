int __cdecl sub_556B41(_DWORD *a1)
{
  _DWORD *v2; // edi
  int v3; // eax
  _DWORD *i; // eax
  unsigned int v5; // ebx
  bool v6; // cf
  bool v7; // cc
  int v8; // ecx
  int v9; // ebx
  int v10; // edx
  int *j; // ebx
  _DWORD v14[4]; // [esp+Ch] [ebp-34h]
  int *v15; // [esp+1Ch] [ebp-24h]
  int v16; // [esp+20h] [ebp-20h]
  unsigned int v17; // [esp+24h] [ebp-1Ch]
  _DWORD *v18; // [esp+28h] [ebp-18h]
  int v19; // [esp+2Ch] [ebp-14h]
  _DWORD *v20; // [esp+30h] [ebp-10h]
  int v21; // [esp+34h] [ebp-Ch]
  int v22; // [esp+38h] [ebp-8h]
  _DWORD *v23; // [esp+3Ch] [ebp-4h]
  int v24; // [esp+48h] [ebp+8h]
  int v25; // [esp+48h] [ebp+8h]

  v24 = 0;
  v2 = (_DWORD *)a1[97];
  if ( (int)a1[72] > 0 )
  {
    v23 = a1 + 73;
    do
    {
      v3 = (*(int (__cdecl **)(_DWORD *, _DWORD, int, _DWORD, int))(a1[1] + 32))(
             a1,
             v2[*(_DWORD *)(*v23 + 4) + 18],
             *(_DWORD *)(*v23 + 12) * a1[32],
             *(_DWORD *)(*v23 + 12),
             1);
      ++v23;
      v14[v24++] = v3;
    }
    while ( v24 < a1[72] );
  }
  for ( i = (_DWORD *)v2[6]; ; i = (_DWORD *)((char *)i + 1) )
  {
    v7 = (int)i < v2[7];
    v23 = i;
    if ( !v7 )
    {
      if ( ++a1[32] >= a1[70] )
      {
        (*(void (__cdecl **)(_DWORD *))(a1[99] + 12))(a1);
        return 4;
      }
      else
      {
        sub_556915(a1);
        return 3;
      }
    }
    v5 = v2[5];
    v6 = v5 < a1[77];
    v17 = v5;
    if ( v6 )
      break;
LABEL_20:
    v2[5] = 0;
  }
  while ( 1 )
  {
    v7 = a1[72] <= 0;
    v22 = 0;
    v25 = 0;
    if ( !v7 )
    {
      v18 = a1 + 73;
      do
      {
        v8 = *v18;
        v9 = *(_DWORD *)(*v18 + 52);
        v19 = 0;
        if ( *(int *)(v8 + 56) > 0 )
        {
          v16 = (v17 * v9) << 7;
          v20 = (_DWORD *)(v14[v25] + 4 * (_DWORD)v23);
          do
          {
            v10 = v16 + *v20;
            v21 = 0;
            if ( v9 > 0 )
            {
              for ( j = &v2[v22 + 8]; ; j = v15 )
              {
                ++v22;
                *j = v10;
                v10 += 128;
                ++v21;
                v15 = j + 1;
                v9 = *(_DWORD *)(v8 + 52);
                if ( v21 >= v9 )
                  break;
              }
            }
            ++v19;
            ++v20;
          }
          while ( v19 < *(_DWORD *)(v8 + 56) );
        }
        ++v25;
        ++v18;
      }
      while ( v25 < a1[72] );
      v5 = v17;
    }
    if ( !(*(unsigned __int8 (__cdecl **)(_DWORD *, _DWORD *))(a1[101] + 4))(a1, v2 + 8) )
      break;
    v6 = ++v5 < a1[77];
    v17 = v5;
    if ( !v6 )
    {
      i = v23;
      goto LABEL_20;
    }
  }
  v2[6] = v23;
  v2[5] = v5;
  return 0;
}
