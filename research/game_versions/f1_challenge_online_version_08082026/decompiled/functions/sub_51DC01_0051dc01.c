int __cdecl sub_51DC01(int a1, int a2, _DWORD *a3, int a4)
{
  int result; // eax
  int v5; // ecx
  unsigned __int8 *v6; // esi
  int v7; // ecx
  unsigned __int8 *v8; // esi
  int v9; // eax
  int v10; // edx
  _WORD *v11; // edi
  _BYTE *v12; // ecx
  bool v13; // zf
  int v14; // [esp+4h] [ebp-14h]
  int v15; // [esp+8h] [ebp-10h]
  int v16; // [esp+Ch] [ebp-Ch]
  int v17; // [esp+10h] [ebp-8h]
  _DWORD *v18; // [esp+14h] [ebp-4h]
  _BYTE *v19; // [esp+2Ch] [ebp+14h]

  result = a1;
  v15 = *(_DWORD *)(*(_DWORD *)(a1 + 420) + 24);
  v5 = *(_DWORD *)(a1 + 92);
  v14 = v5;
  if ( a4 > 0 )
  {
    result = a2 - (_DWORD)a3;
    v18 = a3;
    v16 = a4;
    do
    {
      v6 = *(unsigned __int8 **)((char *)v18 + result);
      v19 = (_BYTE *)*v18;
      if ( v5 )
      {
        v17 = v5;
        do
        {
          v7 = *v6 >> 3;
          v8 = v6 + 1;
          v9 = *v8++ >> 2;
          v10 = *v8 >> 3;
          v11 = (_WORD *)(*(_DWORD *)(v15 + 4 * v7) + 2 * (v10 + 32 * v9));
          v6 = v8 + 1;
          if ( !*v11 )
            sub_51DB31(v9, a1, v7, v10);
          v12 = v19++;
          v13 = v17-- == 1;
          *v12 = *(_BYTE *)v11 - 1;
        }
        while ( !v13 );
        v5 = v14;
        result = a2 - (_DWORD)a3;
      }
      ++v18;
      --v16;
    }
    while ( v16 );
  }
  return result;
}
