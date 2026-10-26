_BYTE *__stdcall sub_6D2470(int a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  unsigned int v5; // edi
  _BYTE *result; // eax
  int *v7; // ebx
  int v8; // esi
  unsigned int v9; // edx
  char v10; // cl
  int v11; // [esp+Ch] [ebp+8h]

  v5 = *(_DWORD *)(a1 + 112);
  result = (_BYTE *)(a5 - 1);
  if ( a5 - 1 >= 0 )
  {
    v7 = (int *)(*a2 + 4 * a3);
    v11 = a5;
    do
    {
      v8 = *v7;
      result = *a4;
      ++v7;
      v9 = 0;
      ++a4;
      if ( v5 )
      {
        do
        {
          v10 = *(_BYTE *)(v9 + v8);
          result[2] = v10;
          result[1] = v10;
          *result = v10;
          result += 3;
          ++v9;
        }
        while ( v9 < v5 );
      }
      --v11;
    }
    while ( v11 );
  }
  return result;
}
