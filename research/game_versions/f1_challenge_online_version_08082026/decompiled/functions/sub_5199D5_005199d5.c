int __cdecl sub_5199D5(_DWORD *a1, int a2)
{
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // esi
  int v8; // ecx
  int v9; // ebx
  void (__cdecl *v12)(_DWORD *, _DWORD *, _DWORD, int, int); // [esp+Ch] [ebp-38h]
  unsigned int v13; // [esp+10h] [ebp-34h]
  unsigned int v14; // [esp+14h] [ebp-30h]
  int v15; // [esp+18h] [ebp-2Ch]
  int v16; // [esp+1Ch] [ebp-28h]
  _DWORD *v17; // [esp+20h] [ebp-24h]
  int v18; // [esp+24h] [ebp-20h]
  int i; // [esp+28h] [ebp-1Ch]
  int v20; // [esp+2Ch] [ebp-18h]
  _DWORD *v21; // [esp+30h] [ebp-14h]
  int v22; // [esp+34h] [ebp-10h]
  int v23; // [esp+38h] [ebp-Ch]
  int v24; // [esp+3Ch] [ebp-8h]
  int v25; // [esp+40h] [ebp-4h]
  unsigned int v26; // [esp+4Ch] [ebp+8h]

  v3 = a1[97];
  v4 = a1[77] - 1;
  v13 = a1[70] - 1;
  v5 = *(_DWORD *)(v3 + 24);
  v18 = v3;
  v14 = v4;
  while ( 1 )
  {
    v25 = v5;
    if ( v5 >= *(_DWORD *)(v3 + 28) )
    {
      ++a1[34];
      if ( ++a1[32] >= a1[70] )
      {
        (*(void (__cdecl **)(_DWORD *))(a1[99] + 12))(a1);
        return 4;
      }
      else
      {
        sub_519986(a1);
        return 3;
      }
    }
    v26 = *(_DWORD *)(v3 + 20);
    if ( v26 <= v4 )
      break;
LABEL_24:
    *(_DWORD *)(v3 + 20) = 0;
    ++v5;
  }
  while ( 1 )
  {
    sub_5159A8(*(void **)(v3 + 32), a1[79] << 7);
    if ( !(*(unsigned __int8 (__cdecl **)(_DWORD *, int))(a1[101] + 4))(a1, v3 + 32) )
      break;
    v6 = 0;
    v20 = 0;
    v23 = 0;
    if ( (int)a1[72] > 0 )
    {
      v17 = a1 + 73;
      do
      {
        v7 = (_DWORD *)*v17;
        if ( *(_BYTE *)(*v17 + 48) )
        {
          v12 = *(void (__cdecl **)(_DWORD *, _DWORD *, _DWORD, int, int))(a1[102] + 4 * v7[1] + 4);
          if ( v26 >= v14 )
            v8 = v7[17];
          else
            v8 = v7[13];
          v9 = v26 * v7[16];
          v24 = 0;
          v16 = v8;
          for ( i = *(_DWORD *)(a2 + 4 * v23) + 4 * v25 * v7[9]; v24 < v7[14]; v20 = v6 )
          {
            if ( a1[32] < v13 || v25 + v24 < v7[18] )
            {
              v22 = v9;
              if ( v16 > 0 )
              {
                v21 = (_DWORD *)(v18 + 4 * v6 + 32);
                v15 = v16;
                do
                {
                  v12(a1, v7, *v21, i, v22);
                  v22 += v7[9];
                  ++v21;
                  --v15;
                }
                while ( v15 );
                v6 = v20;
              }
            }
            v6 += v7[13];
            ++v24;
            i += 4 * v7[9];
          }
          v3 = v18;
        }
        else
        {
          v6 += v7[15];
          v20 = v6;
        }
        ++v23;
        ++v17;
      }
      while ( v23 < a1[72] );
      v4 = v14;
    }
    if ( ++v26 > v4 )
    {
      v5 = v25;
      goto LABEL_24;
    }
  }
  *(_DWORD *)(v3 + 24) = v25;
  *(_DWORD *)(v3 + 20) = v26;
  return 0;
}
