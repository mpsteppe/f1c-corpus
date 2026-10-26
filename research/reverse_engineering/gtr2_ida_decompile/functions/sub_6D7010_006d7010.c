int *__stdcall sub_6D7010(_DWORD *a1, int a2, int *a3, int *a4, int a5, int *a6, unsigned int a7)
{
  int *result; // eax
  _DWORD *v8; // ebx
  int *i; // edi
  unsigned int v10; // esi
  int v11; // edx
  int v12; // edx
  unsigned int v13; // ecx
  int v14; // eax
  int v15; // esi
  unsigned int v16; // edx
  int v17; // ebx
  bool v18; // cc
  int *v19; // esi
  int v20; // eax
  _DWORD *v21; // edx
  int v22; // eax
  int v23; // edi
  int v24; // ecx
  int v25; // edx
  unsigned int v26; // ecx
  int v27; // esi
  int v28; // [esp+8h] [ebp-14h]
  int v29; // [esp+Ch] [ebp-10h]
  unsigned int v30; // [esp+10h] [ebp-Ch]
  int *v31; // [esp+14h] [ebp-8h]
  int v32; // [esp+18h] [ebp-4h]
  int v33; // [esp+18h] [ebp-4h]
  int *v34; // [esp+24h] [ebp+8h]
  int v35; // [esp+28h] [ebp+Ch]
  int v36; // [esp+2Ch] [ebp+10h]
  unsigned int v37; // [esp+30h] [ebp+14h]

  result = a3;
  v8 = a1;
  for ( i = (int *)a1[87]; *a3 < (unsigned int)a4; result = a4 )
  {
    result = a6;
    if ( *a6 >= a7 )
      break;
    v10 = v8[61] - i[13];
    if ( v10 >= (unsigned int)a4 - *a3 )
      v10 = (unsigned int)a4 - *a3;
    (*(void (__stdcall **)(_DWORD *, int, int *, int, unsigned int))(v8[90] + 4))(v8, a2 + 4 * *a3, i + 2, i[13], v10);
    v11 = i[13];
    *a3 += v10;
    v12 = v10 + v11;
    v13 = i[12] - v10;
    i[13] = v12;
    i[12] = v13;
    if ( !v13 && v12 < v8[61] )
    {
      v32 = 0;
      if ( (int)v8[15] > 0 )
      {
        v31 = i + 2;
        do
        {
          v14 = v8[61];
          v15 = i[13];
          v16 = v8[7];
          v17 = *v31;
          v28 = v14;
          v30 = v16;
          if ( v15 < v14 )
          {
            v29 = v15 - 1;
            do
              sub_6B5FF0(v17, v29, v17, v15++, 1, v30);
            while ( v15 < v28 );
          }
          ++v31;
          v18 = ++v32 < a1[15];
          v8 = a1;
        }
        while ( v18 );
      }
      i[13] = v8[61];
    }
    v19 = a6;
    if ( i[13] == v8[61] )
    {
      (*(void (__stdcall **)(_DWORD *, int *, _DWORD, int, int))(v8[91] + 4))(v8, i + 2, 0, a5, *a6);
      v20 = *a6 + 1;
      i[13] = 0;
      *a6 = v20;
    }
    if ( !i[12] && *a6 < a7 )
    {
      result = (int *)v8[17];
      v33 = 0;
      if ( (int)v8[15] > 0 )
      {
        v21 = result + 3;
        v34 = result + 3;
        do
        {
          v22 = *v21 * *v19;
          v23 = a7 * *v21;
          v24 = v21[4];
          v25 = *(_DWORD *)(a5 + 4 * v33);
          v26 = 8 * v24;
          v37 = v26;
          v36 = v25;
          v27 = v22;
          if ( v22 < v23 )
          {
            v35 = v22 - 1;
            while ( 1 )
            {
              sub_6B5FF0(v25, v35, v25, v27++, 1, v26);
              if ( v27 >= v23 )
                break;
              v25 = v36;
              v26 = v37;
            }
          }
          v19 = a6;
          result = (int *)(v33 + 1);
          v21 = v34 + 21;
          v18 = ++v33 < v8[15];
          v34 += 21;
        }
        while ( v18 );
      }
      *v19 = a7;
      return result;
    }
  }
  return result;
}
