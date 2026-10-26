_WORD *__cdecl sub_55A16A(int a1, _WORD *a2, int a3, int a4)
{
  _WORD *result; // eax
  int v5; // ebx
  int v6; // esi
  int i; // edi
  unsigned __int8 *v8; // ecx
  int v9; // [esp+14h] [ebp+8h]

  result = (_WORD *)a1;
  v5 = *(_DWORD *)(a1 + 92);
  v6 = *(_DWORD *)(*(_DWORD *)(a1 + 420) + 24);
  for ( i = 0; i < a4; ++i )
  {
    result = a2;
    v8 = *(unsigned __int8 **)&a2[2 * i];
    if ( v5 )
    {
      v9 = v5;
      do
      {
        result = (_WORD *)(*(_DWORD *)(v6 + 4 * (*v8 >> 3)) + 2 * ((v8[2] >> 3) + 32 * (v8[1] >> 2)));
        if ( !++*result )
          *result = -1;
        v8 += 3;
        --v9;
      }
      while ( v9 );
    }
  }
  return result;
}
