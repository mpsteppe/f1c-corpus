int __cdecl sub_58F270(int a1, int a2)
{
  int result; // eax
  unsigned __int8 *v3; // ebp
  int v4; // esi
  int v5; // edi
  unsigned __int16 v6; // ax
  char v7; // cl
  int v8; // [esp+4h] [ebp+4h]

  result = *(unsigned __int8 *)(a1 + 4) >> 2;
  if ( result )
  {
    v3 = (unsigned __int8 *)(a2 + 5);
    v8 = *(unsigned __int8 *)(a1 + 4) >> 2;
    do
    {
      v4 = *v3;
      v5 = *(v3 - 1) + a2 + 98;
      if ( (unsigned int)v4 > 1 )
      {
        do
        {
          v6 = sub_58FAA0(v4, -1);
          v7 = *(_BYTE *)(v5 + v4-- - 1);
          *(_BYTE *)(v5 + v4) = *(_BYTE *)(v6 + v5);
          *(_BYTE *)(v6 + v5) = v7;
        }
        while ( v4 > 1 );
      }
      v3 += 8;
      result = --v8;
    }
    while ( v8 );
  }
  return result;
}
