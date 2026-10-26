const void **__cdecl sub_51593F(int a1, int a2, int a3, int a4, int a5, unsigned int a6)
{
  const void **result; // eax
  void **v7; // edx
  int v8; // [esp+Ch] [ebp+Ch]

  result = (const void **)(a1 + 4 * a2);
  v7 = (void **)(a3 + 4 * a4);
  if ( a5 > 0 )
  {
    v8 = a5;
    do
    {
      qmemcpy(*v7++, *result++, a6);
      --v8;
    }
    while ( v8 );
  }
  return result;
}
