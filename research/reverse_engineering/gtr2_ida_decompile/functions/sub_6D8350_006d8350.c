int __stdcall sub_6D8350(_DWORD *a1, unsigned __int8 **a2, _DWORD *a3, int a4, int a5)
{
  int result; // eax
  int v6; // ecx
  int v7; // ebx
  _BYTE **v8; // edx
  int v9; // edi
  unsigned __int8 *v10; // esi
  _BYTE *v11; // ecx
  int v12; // edi
  int v13; // [esp+8h] [ebp-18h]
  int v14; // [esp+Ch] [ebp-14h]
  int v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+14h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-8h]
  int v18; // [esp+1Ch] [ebp-4h]
  int v19; // [esp+28h] [ebp+8h]
  int v20; // [esp+28h] [ebp+8h]
  int v21; // [esp+30h] [ebp+10h]
  int v22; // [esp+34h] [ebp+14h]
  int v23; // [esp+38h] [ebp+18h]

  v16 = a1[9];
  result = *(_DWORD *)(a1[90] + 8);
  v17 = a1[7];
  if ( a5 - 1 >= 0 )
  {
    v6 = a3[1];
    v7 = *a3 - v6;
    v8 = (_BYTE **)(v6 + 4 * a4);
    v22 = v7;
    v18 = a3[2] - v6;
    v21 = a5;
    while ( 1 )
    {
      v9 = *(int *)((char *)v8 + v7);
      v10 = *a2++;
      v11 = *v8;
      v19 = *(int *)((char *)v8++ + v18);
      if ( v17 )
      {
        v15 = v9 - (_DWORD)v11;
        v13 = v19 - (_DWORD)v11;
        v23 = v17;
        do
        {
          v12 = v10[2];
          v20 = *v10;
          v14 = v10[1];
          v11[v15] = (unsigned int)(*(_DWORD *)(result + 4 * v12)
                                  + *(_DWORD *)(result + 4 * v14 + 1024)
                                  + *(_DWORD *)(result + 4 * v20 + 2048)) >> 16;
          v10 += v16;
          *v11 = (unsigned int)(*(_DWORD *)(result + 4 * v12 + 3072)
                              + *(_DWORD *)(result + 4 * v14 + 4096)
                              + *(_DWORD *)(result + 4 * v20 + 5120)) >> 16;
          (v11++)[v13] = (unsigned int)(*(_DWORD *)(result + 4 * v12 + 5120)
                                      + *(_DWORD *)(result + 4 * v14 + 6144)
                                      + *(_DWORD *)(result + 4 * v20 + 7168)) >> 16;
          --v23;
        }
        while ( v23 );
      }
      if ( !--v21 )
        break;
      v7 = v22;
    }
  }
  return result;
}
