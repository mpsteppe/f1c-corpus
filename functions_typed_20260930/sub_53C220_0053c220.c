void sub_53C220()
{
  char *v0; // esi
  int v1; // edi

  if ( (byte_8B8EE5 & 1) == 0 )
  {
    byte_8B8EE5 |= 1u;
    v0 = (char *)&unk_8B8C38;
    v1 = 8;
    do
    {
      v0 -= 68;
      EmptyStub_0170();
      --v1;
    }
    while ( v1 );
  }
}

