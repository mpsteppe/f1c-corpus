int __cdecl sub_51E5D7(_DWORD *a1, int a2, _DWORD *a3, int a4)
{
  int v4; // esi
  int result; // eax
  _DWORD *v6; // ecx
  unsigned __int8 *v7; // edx
  int v8; // esi
  _BYTE *v9; // esi
  bool v10; // zf
  int v11; // [esp+4h] [ebp-14h]
  int v12; // [esp+8h] [ebp-10h]
  int v13; // [esp+Ch] [ebp-Ch]
  int v14; // [esp+10h] [ebp-8h]
  int v15; // [esp+14h] [ebp-4h]
  char v16; // [esp+20h] [ebp+8h]
  _BYTE *v17; // [esp+2Ch] [ebp+14h]

  v4 = a1[23];
  result = a1[25];
  v13 = *(_DWORD *)(a1[105] + 24);
  v11 = v4;
  v12 = result;
  if ( a4 > 0 )
  {
    v6 = a3;
    v14 = a4;
    do
    {
      v7 = *(unsigned __int8 **)((char *)v6 + a2 - (_DWORD)a3);
      v17 = (_BYTE *)*v6;
      if ( v4 )
      {
        v15 = v4;
        do
        {
          v16 = 0;
          v8 = 0;
          if ( result > 0 )
          {
            do
            {
              v16 += *(_BYTE *)(*(_DWORD *)(v13 + 4 * v8) + *v7);
              result = v12;
              ++v7;
              ++v8;
            }
            while ( v8 < v12 );
          }
          v9 = v17++;
          v10 = v15-- == 1;
          *v9 = v16;
        }
        while ( !v10 );
        v4 = v11;
      }
      ++v6;
      --v14;
    }
    while ( v14 );
  }
  return result;
}
