char __cdecl sub_518032(int a1, char *a2, int a3)
{
  unsigned int v3; // ecx
  unsigned int v4; // eax
  char *v5; // ebx
  char *v6; // edx
  _BYTE *v7; // edi
  unsigned __int8 *v8; // esi
  int v9; // edx
  _BYTE *v10; // edi
  unsigned __int8 *v11; // esi
  int v12; // edx
  _BYTE *v13; // edi
  unsigned __int8 *v14; // esi
  int v15; // edx
  int v17; // [esp+8h] [ebp-Ch]
  int v18; // [esp+8h] [ebp-Ch]
  int v19; // [esp+8h] [ebp-Ch]
  int v20; // [esp+8h] [ebp-Ch]
  unsigned int v21; // [esp+Ch] [ebp-8h]
  int v22; // [esp+Ch] [ebp-8h]
  int v23; // [esp+Ch] [ebp-8h]
  int v24; // [esp+Ch] [ebp-8h]
  unsigned __int8 v25; // [esp+13h] [ebp-1h]

  v3 = *(unsigned __int8 *)(a1 + 251);
  if ( a3 == 255 )
  {
    v4 = (*(_DWORD *)(a1 + 184) * v3 + 7) >> 3;
    qmemcpy(a2, (const void *)(*(_DWORD *)(a1 + 220) + 1), 4 * ((*(_DWORD *)(a1 + 184) * v3 + 7) >> 5) + (v4 & 3));
  }
  else
  {
    switch ( v3 )
    {
      case 1u:
        v4 = *(_DWORD *)(a1 + 184);
        v13 = a2;
        v14 = (unsigned __int8 *)(*(_DWORD *)(a1 + 220) + 1);
        v24 = 128;
        v15 = 7;
        if ( v4 )
        {
          v20 = *(_DWORD *)(a1 + 184);
          do
          {
            LOBYTE(v4) = a3;
            if ( (a3 & v24) != 0 )
            {
              LOBYTE(v4) = ((*v14 >> v15) & 1) << v15;
              *v13 = v4 | *v13 & (32639 >> (7 - v15));
            }
            if ( v15 )
            {
              --v15;
            }
            else
            {
              ++v14;
              v15 = 7;
              ++v13;
            }
            if ( v24 == 1 )
              v24 = 128;
            else
              v24 >>= 1;
            --v20;
          }
          while ( v20 );
        }
        break;
      case 2u:
        v4 = *(_DWORD *)(a1 + 184);
        v10 = a2;
        v11 = (unsigned __int8 *)(*(_DWORD *)(a1 + 220) + 1);
        v23 = 128;
        v12 = 6;
        if ( v4 )
        {
          v19 = *(_DWORD *)(a1 + 184);
          do
          {
            LOBYTE(v4) = a3;
            if ( (a3 & v23) != 0 )
            {
              LOBYTE(v4) = ((*v11 >> v12) & 3) << v12;
              *v10 = v4 | *v10 & (16191 >> (6 - v12));
            }
            if ( v12 )
            {
              v12 -= 2;
            }
            else
            {
              ++v11;
              v12 = 6;
              ++v10;
            }
            if ( v23 == 1 )
              v23 = 128;
            else
              v23 >>= 1;
            --v19;
          }
          while ( v19 );
        }
        break;
      case 4u:
        v4 = *(_DWORD *)(a1 + 184);
        v7 = a2;
        v8 = (unsigned __int8 *)(*(_DWORD *)(a1 + 220) + 1);
        v22 = 128;
        v9 = 4;
        if ( v4 )
        {
          v18 = *(_DWORD *)(a1 + 184);
          do
          {
            LOBYTE(v4) = a3;
            if ( (a3 & v22) != 0 )
            {
              LOBYTE(v4) = ((*v8 >> v9) & 0xF) << v9;
              *v7 = v4 | *v7 & (3855 >> (4 - v9));
            }
            if ( v9 )
            {
              v9 -= 4;
            }
            else
            {
              ++v8;
              v9 = 4;
              ++v7;
            }
            if ( v22 == 1 )
              v22 = 128;
            else
              v22 >>= 1;
            --v18;
          }
          while ( v18 );
        }
        break;
      default:
        v4 = *(_DWORD *)(a1 + 184);
        v5 = a2;
        v6 = (char *)(*(_DWORD *)(a1 + 220) + 1);
        v21 = v3 >> 3;
        v25 = 0x80;
        if ( v4 )
        {
          v17 = *(_DWORD *)(a1 + 184);
          do
          {
            LOBYTE(v4) = a3;
            if ( ((unsigned __int8)a3 & v25) != 0 )
            {
              v4 = v3 >> 3;
              qmemcpy(v5, v6, v21);
            }
            v6 += v21;
            v5 += v21;
            if ( v25 == 1 )
              v25 = 0x80;
            else
              v25 >>= 1;
            --v17;
          }
          while ( v17 );
        }
        break;
    }
  }
  return v4;
}
