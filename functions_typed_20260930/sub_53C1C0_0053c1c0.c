void sub_53C1C0()
{
  int *v0; // esi
  int v1; // edi

  if ( (byte_8B8EE4 & 2) == 0 )
  {
    byte_8B8EE4 |= 2u;
    v0 = dword_8B78A0;
    v1 = 42;
    do
    {
      v0 -= 19;
      EmptyStub_7470(v0);
      --v1;
    }
    while ( v1 );
  }
}

