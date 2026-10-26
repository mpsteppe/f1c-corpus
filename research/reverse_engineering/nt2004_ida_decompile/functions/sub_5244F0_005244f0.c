void __cdecl sub_5244F0()
{
  char *v0; // esi
  int v1; // edi
  int v2; // eax

  v0 = (char *)&unk_7DA3BC;
  v1 = 45;
  do
  {
    v2 = *((_DWORD *)v0 - 5);
    v0 -= 20;
    if ( v2 )
      sub_5BE8AE();
    --v1;
  }
  while ( v1 );
}
