char __cdecl sub_5126D9(int *a1, _BYTE *a2, unsigned __int8 *a3)
{
  int i; // eax
  int v5; // edi
  bool v6; // zf
  int v7; // edx
  int v8; // ebx
  int v9; // ebx
  int v10; // ecx
  unsigned __int8 *v11; // esi
  _BYTE *v12; // esi
  _BYTE *v13; // esi
  unsigned int j; // edi
  int v15; // esi
  _BYTE *v16; // edi
  int v17; // esi
  _DWORD v19[4]; // [esp+4h] [ebp-14h] BYREF
  unsigned int v20; // [esp+14h] [ebp-4h]
  __int16 v21; // [esp+20h] [ebp+8h]
  unsigned int k; // [esp+20h] [ebp+8h]
  unsigned int v23; // [esp+20h] [ebp+8h]

  LOBYTE(i) = *((_BYTE *)a1 + 8);
  if ( (_BYTE)i != 3 )
  {
    v21 = 0;
    v5 = *a1;
    v6 = (i & 2) == 0;
    LOBYTE(i) = (_BYTE)a3;
    if ( v6 )
    {
      v7 = *((unsigned __int8 *)a1 + 9) - a3[3];
      v9 = 1;
    }
    else
    {
      v7 = *((unsigned __int8 *)a1 + 9) - *a3;
      v8 = a3[2];
      v19[1] = *((unsigned __int8 *)a1 + 9) - a3[1];
      v19[2] = *((unsigned __int8 *)a1 + 9) - v8;
      v9 = 3;
    }
    v6 = (a1[2] & 4) == 0;
    v19[0] = v7;
    if ( !v6 )
    {
      i = *((unsigned __int8 *)a1 + 9) - a3[4];
      v19[v9] = i;
      LOBYTE(v7) = v19[0];
      ++v9;
    }
    v10 = 0;
    if ( v9 > 0 )
    {
      do
      {
        i = (int)&v19[v10];
        if ( *(int *)i > 0 )
        {
          v21 = 1;
        }
        else
        {
          *(_DWORD *)i = 0;
          LOBYTE(v7) = v19[0];
        }
        ++v10;
      }
      while ( v10 < v9 );
      if ( v21 )
      {
        if ( *((_BYTE *)a1 + 9) == 2 )
        {
          v17 = a1[1];
          for ( i = (int)a2; v17; --v17 )
          {
            *(_BYTE *)i = (*(_BYTE *)i >> 1) & 0x55;
            ++i;
          }
        }
        else if ( *((_BYTE *)a1 + 9) == 4 )
        {
          v15 = a1[1];
          v16 = a2;
          for ( LOBYTE(i) = (15 >> v7) | (240 >> v7) & 0xF0; v15; --v15 )
          {
            *v16 = i & (*v16 >> v7);
            ++v16;
          }
        }
        else
        {
          LOBYTE(i) = *((_BYTE *)a1 + 9) - 8;
          if ( *((_BYTE *)a1 + 9) == 8 )
          {
            v13 = a2;
            v23 = v9 * v5;
            for ( j = 0; j < v23; ++j )
            {
              i = j / v9;
              *v13++ >>= LOBYTE(v19[j % v9]);
            }
          }
          else
          {
            LOBYTE(i) = *((_BYTE *)a1 + 9) - 16;
            if ( *((_BYTE *)a1 + 9) == 16 )
            {
              v11 = a2;
              v20 = v9 * v5;
              for ( k = 0; k < v20; LOBYTE(i) = k )
              {
                LOWORD(i) = (unsigned __int16)(v11[1] + (*v11 << 8)) >> LOWORD(v19[k % v9]);
                *v11 = BYTE1(i);
                v12 = v11 + 1;
                *v12 = i;
                v11 = v12 + 1;
                ++k;
              }
            }
          }
        }
      }
    }
  }
  return i;
}
