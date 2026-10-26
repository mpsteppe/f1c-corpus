void __cdecl sub_5917D0()
{
  int *v0; // esi
  int v1; // edi

  if ( (byte_7E8E14 & 2) == 0 )
  {
    byte_7E8E14 |= 2u;
    v0 = &dword_7E6B40;
    v1 = 42;
    do
    {
      v0 -= 19;
      j_nullsub_6(v0);
      --v1;
    }
    while ( v1 );
  }
}
