unsigned int __stdcall sub_6B76CA(int a1, _BYTE *a2, int a3)
{
  unsigned int result; // eax
  unsigned int v5; // ecx
  int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // ecx
  bool i; // cf
  char *v10; // esi
  unsigned int v11; // ecx
  unsigned int v12; // esi
  char v14; // cl
  _BYTE *v15; // edx
  bool v16; // zf
  unsigned int v17; // ecx
  unsigned int v18; // esi
  char v20; // cl
  _BYTE *v21; // edx
  unsigned int v22; // ecx
  unsigned int v23; // esi
  char v25; // cl
  _BYTE *v26; // edx
  unsigned int v27; // ecx
  unsigned int v28; // [esp+4h] [ebp-4h]
  unsigned int v29; // [esp+4h] [ebp-4h]
  unsigned int v30; // [esp+4h] [ebp-4h]
  unsigned int v31; // [esp+10h] [ebp+8h]
  _BYTE *v32; // [esp+10h] [ebp+8h]
  int v33; // [esp+14h] [ebp+Ch]
  int v34; // [esp+14h] [ebp+Ch]
  int v35; // [esp+14h] [ebp+Ch]
  char *v36; // [esp+18h] [ebp+10h]
  int v37; // [esp+18h] [ebp+10h]

  result = a3;
  if ( a3 < 6 )
  {
    v5 = *(unsigned __int8 *)(a1 + 11);
    v6 = a3;
    switch ( v5 )
    {
      case 1u:
        v22 = dword_744FC0[a3];
        v23 = *(_DWORD *)a1;
        v37 = 0;
        v32 = a2;
        v35 = 7;
        v30 = dword_744FC0[v6];
        if ( v22 < v23 )
        {
          do
          {
            v37 |= (((unsigned __int8)a2[v30 >> 3] >> (7 - (v22 & 7))) & 1) << v35;
            if ( v35 )
            {
              --v35;
            }
            else
            {
              v25 = v37;
              v26 = v32++;
              v37 = 0;
              v35 = 7;
              *v26 = v25;
            }
            v30 += dword_744FDC[v6];
            LOBYTE(v22) = v30;
          }
          while ( v30 < v23 );
          v16 = v35 == 7;
          goto LABEL_29;
        }
        break;
      case 2u:
        v17 = dword_744FC0[a3];
        v18 = *(_DWORD *)a1;
        v37 = 0;
        v32 = a2;
        v34 = 6;
        v29 = dword_744FC0[v6];
        if ( v17 < v18 )
        {
          do
          {
            v37 |= (((unsigned __int8)a2[v29 >> 2] >> (2 * (3 - (v17 & 3)))) & 3) << v34;
            if ( v34 )
            {
              v34 -= 2;
            }
            else
            {
              v20 = v37;
              v21 = v32++;
              v37 = 0;
              v34 = 6;
              *v21 = v20;
            }
            v29 += dword_744FDC[v6];
            LOBYTE(v17) = v29;
          }
          while ( v29 < v18 );
          v16 = v34 == 6;
          goto LABEL_29;
        }
        break;
      case 4u:
        v11 = dword_744FC0[a3];
        v12 = *(_DWORD *)a1;
        v37 = 0;
        v32 = a2;
        v33 = 4;
        v28 = dword_744FC0[v6];
        if ( v11 < v12 )
        {
          do
          {
            v37 |= (((unsigned __int8)a2[v28 >> 1] >> (4 - 4 * (v11 & 1))) & 0xF) << v33;
            if ( v33 )
            {
              v33 -= 4;
            }
            else
            {
              v14 = v37;
              v15 = v32++;
              v37 = 0;
              v33 = 4;
              *v15 = v14;
            }
            v28 += dword_744FDC[v6];
            LOBYTE(v11) = v28;
          }
          while ( v28 < v12 );
          v16 = v33 == 4;
LABEL_29:
          if ( !v16 )
            *v32 = v37;
        }
        break;
      default:
        v7 = *(_DWORD *)a1;
        v31 = v5 >> 3;
        v8 = dword_744FC0[a3];
        v36 = a2;
        for ( i = v8 < v7; i; i = v8 < v7 )
        {
          v10 = &a2[v31 * v8];
          if ( v36 != v10 )
            qmemcpy(v36, v10, v31);
          v8 += dword_744FDC[v6];
          v36 += v31;
        }
        break;
    }
    result = (dword_744FDC[v6] - dword_744FC0[v6] + *(_DWORD *)a1 - 1) / (unsigned int)dword_744FDC[v6];
    v27 = (result * *(unsigned __int8 *)(a1 + 11) + 7) >> 3;
    *(_DWORD *)a1 = result;
    *(_DWORD *)(a1 + 4) = v27;
  }
  return result;
}
