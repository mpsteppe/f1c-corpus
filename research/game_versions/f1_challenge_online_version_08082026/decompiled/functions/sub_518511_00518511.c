char __cdecl sub_518511(int a1, int a2, _BYTE *a3, unsigned __int8 *a4, int a5)
{
  unsigned int v5; // eax
  _BYTE *v6; // edx
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx
  int v9; // esi
  int v10; // ecx
  int v11; // esi
  int v12; // edx
  int v13; // ebx
  int v14; // eax
  bool v15; // zf
  _BYTE *v16; // esi
  unsigned __int8 *v17; // edi
  unsigned int v18; // ecx
  unsigned __int8 *j; // ebx
  unsigned int v20; // esi
  unsigned int i; // ecx
  unsigned int v22; // ecx
  _BYTE *v23; // esi
  _BYTE *v24; // edx
  unsigned int v25; // ecx
  int v27; // [esp+8h] [ebp-14h]
  unsigned int v28; // [esp+Ch] [ebp-10h]
  _BYTE *v29; // [esp+10h] [ebp-Ch]
  int v30; // [esp+14h] [ebp-8h]
  unsigned __int8 *v31; // [esp+18h] [ebp-4h]
  unsigned __int8 *v32; // [esp+34h] [ebp+18h]

  LOBYTE(v5) = a5;
  if ( a5 )
  {
    switch ( a5 )
    {
      case 1:
        v22 = *(_DWORD *)(a2 + 4);
        v5 = (*(unsigned __int8 *)(a2 + 11) + 7) >> 3;
        v23 = &a3[v5];
        if ( v5 < v22 )
        {
          v24 = a3;
          v25 = v22 - v5;
          do
          {
            LOBYTE(v5) = *v24;
            *v23++ += *v24++;
            --v25;
          }
          while ( v25 );
        }
        break;
      case 2:
        v20 = *(_DWORD *)(a2 + 4);
        v5 = (unsigned int)a3;
        for ( i = 0; i < v20; ++i )
          *(_BYTE *)v5++ += a4[i];
        break;
      case 3:
        v16 = a3;
        v17 = a4;
        v5 = (*(unsigned __int8 *)(a2 + 11) + 7) >> 3;
        v18 = *(_DWORD *)(a2 + 4) - v5;
        for ( j = a3; v5; --v5 )
          *v16++ += *v17++ >> 1;
        for ( ; v18; --v18 )
        {
          v5 = (*v17 + *j) / 2;
          *v16 += v5;
          ++j;
          ++v17;
          ++v16;
        }
        break;
      case 4:
        v6 = a3;
        v7 = a4;
        v5 = (*(unsigned __int8 *)(a2 + 11) + 7) >> 3;
        v8 = *(_DWORD *)(a2 + 4) - v5;
        v29 = a3;
        v32 = a3;
        v31 = a4;
        if ( v5 )
        {
          v9 = (*(unsigned __int8 *)(a2 + 11) + 7) >> 3;
          do
          {
            LOBYTE(v5) = *v7;
            *v6++ += *v7++;
            --v9;
          }
          while ( v9 );
          v29 = v6;
        }
        if ( v8 )
        {
          v28 = v8;
          do
          {
            v10 = *v32;
            v11 = *v31;
            ++v32;
            v27 = *v7++;
            ++v31;
            v12 = v10 - v11;
            if ( v27 - v11 >= 0 )
              v30 = v27 - v11;
            else
              v30 = v11 - v27;
            v13 = v10 - v11;
            if ( v12 < 0 )
              v13 = v11 - v10;
            v14 = v12 + v27 - v11;
            if ( v14 < 0 )
              v14 = -v14;
            if ( v30 > v13 || v30 > v14 )
            {
              LOBYTE(v10) = v27;
              if ( v13 > v14 )
                LOBYTE(v10) = v11;
            }
            *v29 += v10;
            LOBYTE(v5) = (_BYTE)v29 + 1;
            v15 = v28-- == 1;
            ++v29;
          }
          while ( !v15 );
        }
        break;
      default:
        sub_511887(a1, (int)"Ignoring bad adaptive filter type");
        LOBYTE(v5) = (_BYTE)a3;
        *a3 = 0;
        break;
    }
  }
  return v5;
}
