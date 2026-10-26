_BYTE *__cdecl sub_51C653(int a1, int a2, int a3, _DWORD *a4, _BYTE *a5)
{
  int v5; // ebx
  _BYTE *result; // eax
  int v8; // edi
  int i; // esi
  _BYTE *v10; // ecx
  int v11; // [esp+4h] [ebp-8h]
  _BYTE *v12; // [esp+8h] [ebp-4h]
  int v13; // [esp+14h] [ebp+8h]
  int v14; // [esp+24h] [ebp+18h]

  v5 = *(_DWORD *)(a1 + 92);
  result = a5 - 1;
  v13 = *(_DWORD *)(a1 + 32);
  v11 = v5;
  if ( (int)(a5 - 1) >= 0 )
  {
    v8 = 4 * a3;
    result = a5;
    v12 = a5;
    do
    {
      for ( i = 0; i < v13; ++i )
      {
        v10 = *(_BYTE **)(v8 + *(_DWORD *)(a2 + 4 * i));
        result = (_BYTE *)(i + *a4);
        if ( v5 )
        {
          v14 = v5;
          do
          {
            *result = *v10;
            result += v13;
            ++v10;
            --v14;
          }
          while ( v14 );
          v5 = v11;
        }
      }
      v8 += 4;
      ++a4;
      --v12;
    }
    while ( v12 );
  }
  return result;
}
