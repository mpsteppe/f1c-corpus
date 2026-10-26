void __cdecl sub_42DB00()
{
  int *v0; // esi
  int v1; // edi

  if ( (byte_62BF60 & 1) == 0 )
  {
    byte_62BF60 |= 1u;
    v0 = &dword_75AAC0;
    v1 = 49;
    do
    {
      v0 -= 6326;
      sub_4EDDA0((int)v0);
      --v1;
    }
    while ( v1 );
  }
}
