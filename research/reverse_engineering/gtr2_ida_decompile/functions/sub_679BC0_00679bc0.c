_DWORD *__stdcall sub_679BC0(int *a1)
{
  _DWORD *result; // eax
  int v2; // ecx
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ecx
  int v6; // eax
  int v7; // eax

  result = (_DWORD *)a1[10];
  switch ( (unsigned int)result )
  {
    case 0u:
      result = (_DWORD *)sub_6798D0(a1, 0);
      break;
    case 1u:
    case 8u:
      v2 = a1[5];
      if ( v2 != 100 )
      {
        v3 = *a1;
        *(_DWORD *)(v3 + 20) = 20;
        *(_DWORD *)(v3 + 24) = v2;
        result = (_DWORD *)(*(int (__stdcall **)(int *))v3)(a1);
      }
      a1[16] = 1;
      a1[55] = 0;
      a1[56] = 1;
      a1[57] = 1;
      a1[52] = 1;
      a1[15] = 1;
      v4 = (_DWORD *)a1[17];
      *v4 = 1;
      v4[2] = 1;
      v4[3] = 1;
      v4[4] = 0;
      v4[5] = 0;
      v4[6] = 0;
      break;
    case 2u:
    case 3u:
    case 6u:
    case 7u:
      result = (_DWORD *)sub_6798D0(a1, 3);
      break;
    case 4u:
      result = (_DWORD *)sub_6798D0(a1, 4);
      break;
    case 5u:
      v5 = a1[5];
      if ( v5 != 100 )
      {
        v6 = *a1;
        *(_DWORD *)(v6 + 20) = 20;
        *(_DWORD *)(v6 + 24) = v5;
        (*(void (__stdcall **)(int *))v6)(a1);
      }
      result = (_DWORD *)a1[17];
      *result = 1;
      result[4] = 0;
      result[5] = 0;
      result[6] = 0;
      a1[16] = 5;
      a1[52] = 0;
      a1[56] = 1;
      a1[57] = 1;
      a1[55] = 1;
      a1[15] = 4;
      result[2] = 2;
      result[3] = 2;
      result[21] = 2;
      result[23] = 1;
      result[24] = 1;
      result[25] = 1;
      result[26] = 1;
      result[27] = 1;
      result[42] = 3;
      result[44] = 1;
      result[45] = 1;
      result[46] = 1;
      result[47] = 1;
      result[48] = 1;
      result[65] = 2;
      result[66] = 2;
      result[63] = 4;
      result[67] = 0;
      result[68] = 0;
      result[69] = 0;
      break;
    default:
      v7 = *a1;
      *(_DWORD *)(v7 + 20) = 9;
      result = (_DWORD *)(*(int (__stdcall **)(int *))v7)(a1);
      break;
  }
  return result;
}
