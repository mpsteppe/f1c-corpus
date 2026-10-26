int __stdcall sub_6D71F0(
        unsigned int *a1,
        int a2,
        unsigned int *a3,
        unsigned int a4,
        int a5,
        unsigned int *a6,
        unsigned int a7)
{
  _DWORD *v8; // ebx
  int result; // eax
  unsigned int v10; // edx
  int v11; // ecx
  unsigned int v12; // edi
  int v13; // eax
  int v14; // edi
  bool v15; // cc
  int v16; // ecx
  unsigned int v17; // eax
  int v18; // edi
  int v19; // edi
  unsigned int v20; // eax
  int v21; // edi
  int i; // [esp+8h] [ebp-18h]
  int v23; // [esp+Ch] [ebp-14h]
  int v24; // [esp+10h] [ebp-10h]
  unsigned int v25; // [esp+14h] [ebp-Ch]
  int *v26; // [esp+14h] [ebp-Ch]
  int *v27; // [esp+18h] [ebp-8h]
  int v28; // [esp+18h] [ebp-8h]
  int v29; // [esp+1Ch] [ebp-4h]
  unsigned int v30; // [esp+1Ch] [ebp-4h]
  int v31; // [esp+28h] [ebp+8h]
  int v32; // [esp+28h] [ebp+8h]

  v8 = (_DWORD *)a1[87];
  result = 3 * a1[61];
  for ( i = result; *a6 < a7; result = (int)a6 )
  {
    v10 = *a3;
    if ( *a3 >= a4 )
    {
      result = v8[12];
      if ( result )
        return result;
      if ( v8[13] < v8[15] )
      {
        v32 = 0;
        if ( (int)a1[15] > 0 )
        {
          v26 = v8 + 2;
          do
          {
            v18 = v8[13];
            v23 = v8[15];
            v30 = a1[7];
            v28 = *v26;
            if ( v18 < v23 )
            {
              v24 = v18 - 1;
              sub_6B5FF0(*v26, v18 - 1, *v26, v18, 1, v30);
              while ( ++v18 < v23 )
                sub_6B5FF0(v28, v24, v28, v18, 1, v30);
            }
            v15 = ++v32 < (int)a1[15];
            ++v26;
          }
          while ( v15 );
        }
        v8[13] = v8[15];
      }
    }
    else
    {
      v11 = v8[13];
      v12 = v8[15] - v11;
      v25 = v12;
      if ( v12 >= a4 - v10 )
      {
        v25 = a4 - v10;
        v12 = a4 - v10;
      }
      (*(void (__stdcall **)(unsigned int *, unsigned int, _DWORD *, int, unsigned int))(a1[90] + 4))(
        a1,
        a2 + 4 * v10,
        v8 + 2,
        v11,
        v12);
      if ( v8[12] == a1[8] )
      {
        v31 = 0;
        if ( (int)a1[15] > 0 )
        {
          v13 = a1[61];
          v27 = v8 + 2;
          do
          {
            v14 = 1;
            if ( v13 >= 1 )
            {
              v29 = -1;
              do
              {
                sub_6B5FF0(*v27, 0, *v27, v29, 1, a1[7]);
                v13 = a1[61];
                ++v14;
                --v29;
              }
              while ( v14 <= v13 );
            }
            v15 = ++v31 < (int)a1[15];
            ++v27;
          }
          while ( v15 );
          v12 = v25;
        }
      }
      v16 = v8[13];
      *a3 += v12;
      v17 = v8[12] - v12;
      v8[13] = v12 + v16;
      v8[12] = v17;
    }
    if ( v8[13] == v8[15] )
    {
      (*(void (__stdcall **)(unsigned int *, _DWORD *, _DWORD, int, unsigned int))(a1[91] + 4))(
        a1,
        v8 + 2,
        v8[14],
        a5,
        *a6);
      v19 = v8[14];
      ++*a6;
      v20 = a1[61];
      v21 = v20 + v19;
      v8[14] = v21;
      if ( v21 >= i )
        v8[14] = 0;
      if ( v8[13] >= i )
        v8[13] = 0;
      v8[15] = v20 + v8[13];
    }
  }
  return result;
}
