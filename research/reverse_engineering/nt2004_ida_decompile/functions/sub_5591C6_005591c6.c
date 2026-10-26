int __cdecl sub_5591C6(int a1, int a2, int a3, _BYTE ***a4)
{
  _BYTE **v5; // esi
  int result; // eax
  int v7; // ebx
  unsigned __int8 *v8; // eax
  int v9; // edx
  _BYTE *v10; // ecx
  unsigned __int8 *v11; // eax
  _BYTE *v12; // ecx
  int v13; // edi
  int v14; // edx
  _BYTE *v15; // ecx
  int v16; // edx
  int v17; // [esp+4h] [ebp-4h]
  int v18; // [esp+1Ch] [ebp+14h]

  v18 = 0;
  v5 = *a4;
  result = a1;
  if ( *(int *)(a1 + 272) > 0 )
  {
    v7 = a3 - (_DWORD)v5;
    do
    {
      v8 = *(_BYTE **)((char *)v5 + v7);
      v9 = *v8;
      v10 = *v5;
      *v10 = v9;
      v11 = v8 + 1;
      *++v10 = (3 * v9 + *v11 + 2) >> 2;
      v12 = v10 + 1;
      if ( *(_DWORD *)(a2 + 40) != 2 )
      {
        v17 = *(_DWORD *)(a2 + 40) - 2;
        do
        {
          v13 = *v11;
          v14 = *(v11++ - 1);
          v13 *= 3;
          *v12 = (v14 + v13 + 1) >> 2;
          v15 = v12 + 1;
          *v15 = (*v11 + v13 + 2) >> 2;
          v12 = v15 + 1;
          --v17;
        }
        while ( v17 );
      }
      v16 = *v11;
      ++v18;
      *v12 = (*(v11 - 1) + 3 * v16 + 1) >> 2;
      result = a1;
      v12[1] = v16;
      ++v5;
    }
    while ( v18 < *(_DWORD *)(a1 + 272) );
  }
  return result;
}
