int __cdecl sub_58F360(int a1, __int16 *a2)
{
  int v2; // ebp
  __int16 *v3; // esi
  int v4; // edi
  _DWORD v6[4]; // [esp+4h] [ebp-10h] BYREF

  v2 = 0;
  if ( *(unsigned __int8 *)(a1 + 4) >> 2 )
  {
    v3 = a2;
    v4 = *(unsigned __int8 *)(a1 + 4) >> 2;
    do
    {
      if ( sub_58FF00(
             *(_DWORD *)(dword_7E483C + 4 * *v3),
             *((unsigned __int8 *)a2 + *((unsigned __int8 *)v3 + 6) + 98),
             v6) )
      {
        v2 += v6[0];
      }
      v3 += 4;
      --v4;
    }
    while ( v4 );
  }
  return sub_58E550(v2);
}
