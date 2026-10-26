int __cdecl sub_55A9A6(int a1, int a2, int a3, int a4, int a5, int a6, _BYTE *a7)
{
  int result; // eax
  int v8; // ebx
  _DWORD *v9; // edx
  int v10; // ecx
  int v11; // esi
  int v12; // edx
  int v13; // eax
  int v14; // esi
  int v15; // edx
  int v16; // ecx
  _DWORD v17[128]; // [esp+4h] [ebp-228h] BYREF
  int v18; // [esp+204h] [ebp-28h]
  int v19; // [esp+208h] [ebp-24h]
  int v20; // [esp+20Ch] [ebp-20h]
  _BYTE *v21; // [esp+210h] [ebp-1Ch]
  int v22; // [esp+214h] [ebp-18h]
  int v23; // [esp+218h] [ebp-14h]
  int *v24; // [esp+21Ch] [ebp-10h]
  int v25; // [esp+220h] [ebp-Ch]
  int v26; // [esp+224h] [ebp-8h]
  int v27; // [esp+228h] [ebp-4h]

  v26 = 0;
  result = 0x7FFFFFFF;
  memset32(v17, 0x7FFFFFFF, 0x80u);
  if ( a5 > 0 )
  {
    do
    {
      v8 = *(unsigned __int8 *)(v26 + a6);
      v9 = *(_DWORD **)(a1 + 116);
      v10 = a2 - *(unsigned __int8 *)(v8 + *v9);
      v11 = 3 * (a3 - *(unsigned __int8 *)(v9[1] + v8));
      v12 = a4 - *(unsigned __int8 *)(v9[2] + v8);
      v10 *= 2;
      v13 = v10 * v10 + v11 * v11 + v12 * v12;
      v14 = 8 * (3 * v11 + 18);
      v15 = 16 * (v12 + 4);
      v24 = v17;
      v21 = a7;
      v27 = 32 * (v10 + 8);
      v19 = 4;
      do
      {
        v22 = v13;
        v25 = v14;
        v18 = 8;
        do
        {
          v16 = v22;
          v23 = v15;
          v20 = 4;
          do
          {
            if ( v16 < *v24 )
            {
              *v24 = v16;
              *v21 = v8;
            }
            v16 += v23;
            v23 += 128;
            ++v24;
            ++v21;
            --v20;
          }
          while ( v20 );
          v22 += v25;
          v25 += 288;
          --v18;
        }
        while ( v18 );
        v13 += v27;
        v27 += 512;
        --v19;
      }
      while ( v19 );
      result = ++v26;
    }
    while ( v26 < a5 );
  }
  return result;
}
