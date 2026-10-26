int __stdcall sub_6D23B0(int a1, int a2, int a3, int *a4, int a5)
{
  int v5; // edx
  int v6; // edi
  int result; // eax
  int v8; // esi
  _BYTE *v9; // eax
  _BYTE *v10; // ecx
  bool v11; // zf
  int v12; // [esp+4h] [ebp-4h]
  int v13; // [esp+10h] [ebp+8h]
  int v14; // [esp+18h] [ebp+10h]

  v5 = *(_DWORD *)(a1 + 36);
  v6 = *(_DWORD *)(a1 + 112);
  result = a5 - 1;
  v12 = v6;
  if ( a5 - 1 >= 0 )
  {
    v13 = 4 * a3;
    result = 4;
    do
    {
      v8 = 0;
      if ( v5 > 0 )
      {
        v14 = *a4;
        do
        {
          v9 = *(_BYTE **)(v13 + *(_DWORD *)(a2 + 4 * v8));
          v10 = (_BYTE *)(v8 + v14);
          if ( v6 )
          {
            do
            {
              *v10 = *v9++;
              v10 += v5;
              --v6;
            }
            while ( v6 );
            v6 = v12;
          }
          ++v8;
        }
        while ( v8 < v5 );
        result = 4;
      }
      v11 = a5 == 1;
      v13 += 4;
      ++a4;
      --a5;
    }
    while ( !v11 );
  }
  return result;
}
