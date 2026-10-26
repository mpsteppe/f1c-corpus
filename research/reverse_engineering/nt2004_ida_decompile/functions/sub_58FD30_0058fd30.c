int __cdecl sub_58FD30(int a1, int a2)
{
  int v2; // ebp
  int result; // eax
  int v4; // edi
  int v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // [esp+10h] [ebp-4h]

  v2 = *(unsigned __int8 *)(a1 + 4) >> 2;
  result = 0;
  v4 = 0;
  v9 = 0;
  if ( v2 )
  {
    while ( 1 )
    {
      v5 = *(unsigned __int8 *)(a1 + v4 + 8);
      v6 = *(unsigned __int8 *)(a1 + 4 * v5 + 2);
      v7 = a1 + 4 * v5;
      if ( v6 == a2 )
        return 1;
      v8 = 0;
      while ( *(unsigned __int8 *)(v7 + v8 + 8) != a2 )
      {
        if ( ++v8 >= 4 )
          goto LABEL_8;
      }
      v9 = 1;
LABEL_8:
      if ( ++v4 >= v2 )
        return v9;
    }
  }
  return result;
}
