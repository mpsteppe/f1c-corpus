int __stdcall sub_67B82C(int a1, _BYTE *a2, unsigned __int8 *a3)
{
  int result; // eax
  char v4; // dl
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  int v8; // ebx
  bool v9; // zf
  int v10; // edi
  int *v11; // esi
  unsigned int v12; // edi
  unsigned __int8 *v13; // esi
  __int16 v14; // ax
  _BYTE *v15; // esi
  _BYTE *v16; // esi
  int v17; // edi
  _BYTE *v18; // esi
  _BYTE *i; // ecx
  _DWORD v20[4]; // [esp+0h] [ebp-14h] BYREF
  int v21; // [esp+10h] [ebp-4h]
  __int16 v22; // [esp+1Ch] [ebp+8h]
  unsigned int j; // [esp+20h] [ebp+Ch]

  result = a1;
  v4 = *(_BYTE *)(a1 + 8);
  if ( v4 != 3 )
  {
    v22 = 0;
    v5 = *(_DWORD *)result;
    v21 = *(_DWORD *)result;
    if ( (v4 & 2) != 0 )
    {
      v6 = *(unsigned __int8 *)(result + 9) - *a3;
      v7 = *(unsigned __int8 *)(result + 9) - a3[2];
      v20[1] = *(unsigned __int8 *)(result + 9) - a3[1];
      v20[2] = v7;
      v5 = v21;
      v8 = 3;
    }
    else
    {
      v6 = *(unsigned __int8 *)(result + 9) - a3[3];
      v8 = 1;
    }
    v9 = (*(_BYTE *)(result + 8) & 4) == 0;
    v20[0] = v6;
    if ( !v9 )
    {
      v20[v8] = *(unsigned __int8 *)(result + 9) - a3[4];
      LOBYTE(v6) = v20[0];
      ++v8;
    }
    v10 = 0;
    if ( v8 > 0 )
    {
      do
      {
        v11 = &v20[v10];
        if ( *v11 > 0 )
        {
          v22 = 1;
        }
        else
        {
          *v11 = 0;
          LOBYTE(v6) = v20[0];
        }
        ++v10;
      }
      while ( v10 < v8 );
      v12 = 0;
      if ( v22 )
      {
        switch ( *(_BYTE *)(result + 9) )
        {
          case 2:
            result = *(_DWORD *)(result + 4);
            for ( i = a2; result; --result )
            {
              *i = (*i >> 1) & 0x55;
              ++i;
            }
            break;
          case 4:
            v17 = *(_DWORD *)(result + 4);
            v18 = a2;
            result = 240 >> v6;
            for ( LOBYTE(result) = (15 >> v6) | (240 >> v6) & 0xF0; v17; --v17 )
            {
              *v18 = result & (*v18 >> v6);
              ++v18;
            }
            break;
          case 8:
            v16 = a2;
            if ( v8 * v5 )
            {
              do
              {
                result = v12 / v8;
                *v16++ >>= LOBYTE(v20[v12 % v8]);
                ++v12;
              }
              while ( v12 < v8 * v5 );
            }
            break;
          case 0x10:
            v13 = a2;
            for ( j = 0; j < v8 * v5; result = j )
            {
              v14 = (unsigned __int16)(v13[1] + (*v13 << 8)) >> LOWORD(v20[j % v8]);
              *v13 = HIBYTE(v14);
              v15 = v13 + 1;
              *v15 = v14;
              v13 = v15 + 1;
              ++j;
            }
            break;
        }
      }
    }
  }
  return result;
}
