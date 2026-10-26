int __stdcall sub_6798D0(int *a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int result; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // esi
  _DWORD *v7; // esi
  _DWORD *v8; // esi
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  int *v12; // esi
  int v13; // eax

  v2 = a1[5];
  if ( v2 != 100 )
  {
    v3 = *a1;
    *(_DWORD *)(v3 + 20) = 20;
    *(_DWORD *)(v3 + 24) = v2;
    (*(void (__stdcall **)(int *))v3)(a1);
  }
  result = a2;
  a1[16] = a2;
  a1[52] = 0;
  a1[55] = 0;
  a1[56] = 1;
  a1[57] = 1;
  switch ( a2 )
  {
    case 0:
      v9 = a1[9];
      a1[15] = v9;
      if ( v9 < 1 || v9 > 10 )
      {
        v10 = *a1;
        *(_DWORD *)(v10 + 20) = 26;
        *(_DWORD *)(v10 + 24) = v9;
        *(_DWORD *)(v10 + 28) = 10;
        (*(void (__stdcall **)(int *))v10)(a1);
      }
      v11 = a1[15];
      result = 0;
      if ( v11 > 0 )
      {
        v12 = (int *)a1[17];
        do
        {
          *v12 = result;
          v12[2] = 1;
          v12[3] = 1;
          v12[4] = 0;
          v12[5] = 0;
          v12[6] = 0;
          ++result;
          v12 += 21;
        }
        while ( result < v11 );
      }
      break;
    case 1:
      a1[52] = 1;
      a1[15] = 1;
      v5 = (_DWORD *)a1[17];
      *v5 = 1;
      v5[2] = 1;
      v5[3] = 1;
      v5[4] = 0;
      v5[5] = 0;
      v5[6] = 0;
      break;
    case 2:
      a1[55] = 1;
      a1[15] = 3;
      v6 = (_DWORD *)a1[17];
      v6[2] = 1;
      v6[3] = 1;
      v6[4] = 0;
      v6[5] = 0;
      v6[6] = 0;
      *v6 = 82;
      v6[23] = 1;
      v6[24] = 1;
      v6[25] = 0;
      v6[26] = 0;
      v6[27] = 0;
      v6[21] = 71;
      v6[44] = 1;
      v6[45] = 1;
      v6[46] = 0;
      v6[47] = 0;
      v6[48] = 0;
      v6[42] = 66;
      break;
    case 3:
      result = 3;
      a1[52] = 1;
      a1[15] = 3;
      v7 = (_DWORD *)a1[17];
      *v7 = 1;
      v7[4] = 0;
      v7[5] = 0;
      v7[6] = 0;
      v7[2] = 2;
      v7[3] = 2;
      v7[23] = 1;
      v7[24] = 1;
      v7[25] = 1;
      v7[26] = 1;
      v7[27] = 1;
      v7[21] = 2;
      v7[44] = 1;
      v7[45] = 1;
      v7[46] = 1;
      v7[47] = 1;
      v7[48] = 1;
      v7[42] = 3;
      break;
    case 4:
      a1[55] = 1;
      a1[15] = 4;
      v8 = (_DWORD *)a1[17];
      v8[2] = 1;
      v8[3] = 1;
      v8[4] = 0;
      v8[5] = 0;
      v8[6] = 0;
      *v8 = 67;
      v8[23] = 1;
      v8[24] = 1;
      v8[25] = 0;
      v8[26] = 0;
      v8[27] = 0;
      v8[21] = 77;
      v8[44] = 1;
      v8[45] = 1;
      v8[46] = 0;
      v8[47] = 0;
      v8[48] = 0;
      v8[42] = 89;
      v8[65] = 1;
      v8[66] = 1;
      v8[67] = 0;
      v8[68] = 0;
      v8[69] = 0;
      v8[63] = 75;
      break;
    case 5:
      result = a1[17];
      *(_DWORD *)result = 1;
      *(_DWORD *)(result + 16) = 0;
      *(_DWORD *)(result + 20) = 0;
      *(_DWORD *)(result + 24) = 0;
      *(_DWORD *)(result + 8) = 2;
      *(_DWORD *)(result + 12) = 2;
      *(_DWORD *)(result + 92) = 1;
      *(_DWORD *)(result + 96) = 1;
      *(_DWORD *)(result + 100) = 1;
      *(_DWORD *)(result + 104) = 1;
      *(_DWORD *)(result + 108) = 1;
      *(_DWORD *)(result + 84) = 2;
      *(_DWORD *)(result + 176) = 1;
      *(_DWORD *)(result + 180) = 1;
      *(_DWORD *)(result + 184) = 1;
      *(_DWORD *)(result + 188) = 1;
      *(_DWORD *)(result + 192) = 1;
      *(_DWORD *)(result + 168) = 3;
      a1[55] = 1;
      a1[15] = 4;
      *(_DWORD *)(result + 268) = 0;
      *(_DWORD *)(result + 272) = 0;
      *(_DWORD *)(result + 276) = 0;
      *(_DWORD *)(result + 252) = 4;
      *(_DWORD *)(result + 260) = 2;
      *(_DWORD *)(result + 264) = 2;
      break;
    default:
      v13 = *a1;
      *(_DWORD *)(v13 + 20) = 10;
      result = (*(int (__stdcall **)(int *))v13)(a1);
      break;
  }
  return result;
}
