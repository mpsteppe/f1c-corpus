unsigned __int8 *__stdcall sub_6D8510(_DWORD *a1, unsigned __int8 **a2, _DWORD *a3, int a4, int a5)
{
  int v5; // esi
  unsigned int v6; // edx
  unsigned __int8 *result; // eax
  int *v8; // edi
  unsigned int v9; // ecx
  int v10; // edi
  int v11; // ebx
  unsigned int v12; // [esp+4h] [ebp-8h]
  int v13; // [esp+8h] [ebp-4h]
  int v14; // [esp+14h] [ebp+8h]
  int *v15; // [esp+1Ch] [ebp+10h]
  int v16; // [esp+24h] [ebp+18h]

  v5 = *(_DWORD *)(a1[90] + 8);
  v6 = a1[7];
  result = (unsigned __int8 *)(a5 - 1);
  v13 = a1[9];
  v12 = v6;
  if ( a5 - 1 >= 0 )
  {
    v8 = (int *)(*a3 + 4 * a4);
    v14 = a5;
    do
    {
      result = *a2++;
      v16 = *v8++;
      v9 = 0;
      v15 = v8;
      if ( v6 )
      {
        do
        {
          v10 = result[2];
          v11 = *(_DWORD *)(v5 + 4 * result[1] + 1024) + *(_DWORD *)(v5 + 4 * *result + 2048);
          result += v13;
          *(_BYTE *)(v9 + v16) = (unsigned int)(*(_DWORD *)(v5 + 4 * v10) + v11) >> 16;
          v6 = v12;
          ++v9;
        }
        while ( v9 < v12 );
        v8 = v15;
      }
      --v14;
    }
    while ( v14 );
  }
  return result;
}
