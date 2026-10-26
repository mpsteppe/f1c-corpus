void __cdecl sub_591830()
{
  char *v0; // esi
  int v1; // edi

  if ( (byte_7E8E15 & 1) == 0 )
  {
    byte_7E8E15 |= 1u;
    if ( unk_7E7F94 )
    {
      j_nullsub_6(unk_7E7F94);
      sub_5BE8AE();
      unk_7E7F94 = 0;
    }
    v0 = (char *)&unk_7E7F40;
    v1 = 8;
    do
    {
      v0 -= 68;
      nullsub_6(v0);
      --v1;
    }
    while ( v1 );
  }
}
