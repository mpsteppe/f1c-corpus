int __cdecl sub_588F66(int a1, int a2)
{
  int v2; // edi
  int *v3; // esi
  int result; // eax
  int v5; // [esp-8h] [ebp-Ch]

  v2 = a2;
  if ( a2 > 0 )
  {
    v3 = &a2;
    do
    {
      v5 = v3[1];
      ++v3;
      result = sub_58FCB0(a1, v5);
      --v2;
    }
    while ( v2 );
  }
  return result;
}

