unsigned __int8 *__stdcall sub_6D8470(int a1, unsigned __int8 **a2, _DWORD *a3, int a4, int a5)
{
  unsigned int v5; // edx
  unsigned __int8 *result; // eax
  int v7; // esi
  int *v8; // edi
  unsigned int v9; // ecx
  int v10; // ebx
  unsigned int v11; // [esp+4h] [ebp-4h]
  int v12; // [esp+10h] [ebp+8h]
  int v13; // [esp+20h] [ebp+18h]

  v5 = *(_DWORD *)(a1 + 28);
  result = (unsigned __int8 *)(a5 - 1);
  v7 = *(_DWORD *)(*(_DWORD *)(a1 + 360) + 8);
  v11 = v5;
  if ( a5 - 1 >= 0 )
  {
    v8 = (int *)(*a3 + 4 * a4);
    v12 = a5;
    do
    {
      result = *a2++;
      v13 = *v8++;
      v9 = 0;
      if ( v5 )
      {
        do
        {
          v10 = (*(_DWORD *)(v7 + 4 * *result)
               + *(_DWORD *)(v7 + 4 * result[1] + 1024)
               + *(_DWORD *)(v7 + 4 * result[2] + 2048)) >> 16;
          result += 3;
          *(_BYTE *)(v9 + v13) = v10;
          v5 = v11;
          ++v9;
        }
        while ( v9 < v11 );
      }
      --v12;
    }
    while ( v12 );
  }
  return result;
}
