int __stdcall sub_6D8780(int a1, int *a2, int a3, int a4, int a5)
{
  int v5; // ebx
  unsigned int v6; // edi
  int result; // eax
  int v8; // edx
  int v9; // esi
  unsigned int v10; // eax
  _BYTE *v11; // ecx
  bool v12; // zf
  int v13; // [esp+8h] [ebp-4h]
  int v14; // [esp+14h] [ebp+8h]
  int v15; // [esp+20h] [ebp+14h]

  v5 = *(_DWORD *)(a1 + 60);
  v6 = *(_DWORD *)(a1 + 28);
  result = a5 - 1;
  v13 = v5;
  if ( a5 - 1 >= 0 )
  {
    v14 = 4 * a4;
    result = 4;
    do
    {
      v8 = 0;
      if ( v5 > 0 )
      {
        v15 = *a2;
        do
        {
          v9 = *(_DWORD *)(v14 + *(_DWORD *)(a3 + 4 * v8));
          v10 = 0;
          if ( v6 )
          {
            v11 = (_BYTE *)(v8 + v15);
            do
            {
              *(_BYTE *)(v10 + v9) = *v11;
              v5 = v13;
              v11 += v13;
              ++v10;
            }
            while ( v10 < v6 );
          }
          ++v8;
        }
        while ( v8 < v5 );
        result = 4;
      }
      v12 = a5 == 1;
      ++a2;
      v14 += 4;
      --a5;
    }
    while ( !v12 );
  }
  return result;
}
