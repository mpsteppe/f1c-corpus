int __cdecl sub_55B375(_DWORD *a1)
{
  int v1; // esi
  int v2; // ebx
  int result; // eax
  int v4; // ecx
  _BYTE *v5; // edi
  int v6; // edx
  int i; // eax
  int v8; // ebx
  int v9; // edx
  _BYTE *v10; // ecx
  int v11; // [esp+10h] [ebp-18h]
  int v12; // [esp+14h] [ebp-14h]
  int *v13; // [esp+18h] [ebp-10h]
  int v14; // [esp+1Ch] [ebp-Ch]
  int v15; // [esp+20h] [ebp-8h]
  int v16; // [esp+24h] [ebp-4h]

  v1 = a1[105];
  if ( a1[19] == 1 )
  {
    v14 = 510;
    *(_BYTE *)(v1 + 28) = 1;
  }
  else
  {
    v14 = 0;
    *(_BYTE *)(v1 + 28) = 0;
  }
  v2 = 0;
  *(_DWORD *)(v1 + 24) = (*(int (__cdecl **)(_DWORD *, int, int, _DWORD))(a1[1] + 8))(a1, 1, v14 + 256, a1[25]);
  result = *(_DWORD *)(v1 + 20);
  v11 = 0;
  if ( (int)a1[25] > 0 )
  {
    v13 = (int *)(v1 + 32);
    while ( 1 )
    {
      v4 = *v13;
      v12 = result / *v13;
      if ( v14 )
        *(_DWORD *)(*(_DWORD *)(v1 + 24) + 4 * v2) += 255;
      v5 = *(_BYTE **)(*(_DWORD *)(v1 + 24) + 4 * v2);
      v15 = 0;
      v16 = 0;
      v6 = (v4 + 254) / (2 * v4 - 2);
      do
      {
        if ( v16 > v6 )
        {
          for ( i = 510 * v15; ; i += 510 )
          {
            ++v15;
            v6 = (i + 510 + v4 + 254) / (2 * v4 - 2);
            if ( v16 <= v6 )
              break;
          }
        }
        v8 = v16++;
        v5[v8] = v12 * v15;
      }
      while ( v16 <= 255 );
      if ( v14 )
      {
        v9 = 1;
        v10 = v5 - 1;
        do
        {
          *v10 = *v5;
          v5[v9++ + 255] = v5[255];
          --v10;
        }
        while ( v9 <= 255 );
      }
      result = (int)a1;
      ++v13;
      v2 = ++v11;
      if ( v11 >= a1[25] )
        break;
      result = v12;
    }
  }
  return result;
}
