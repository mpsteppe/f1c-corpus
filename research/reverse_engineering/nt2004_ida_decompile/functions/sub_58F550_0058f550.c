int __cdecl sub_58F550(int a1, int a2)
{
  int result; // eax
  int v3; // ebp
  int v4; // esi
  unsigned __int8 *v5; // ecx
  int v6; // edx
  unsigned __int8 *v7; // edi
  unsigned __int8 v8; // bl

  result = 0;
  v3 = 0;
  v4 = (*(unsigned __int8 *)(a1 + 4) >> 2) - 1;
  v5 = (unsigned __int8 *)(a2 + 8 * v4);
  v6 = v5[4] + v5[5];
  v7 = v5 + 4;
  do
  {
    v8 = v5[6] + 1;
    v5[6] = v8;
    if ( v8 < v6 )
      break;
    --v4;
    v7 -= 8;
    v5[6] = v5[4];
    if ( v4 < 0 )
    {
      v3 = 1;
      result = 1;
    }
    v6 = *v7 + v7[1];
    v5 = v7 - 4;
  }
  while ( !v3 );
  return result;
}
