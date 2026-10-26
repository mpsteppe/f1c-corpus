void InitializationLoop256_c300()
{
  int *v0; // esi
  int v1; // edi

  v0 = &dword_8C5F40;
  v1 = 256;
  do
  {
    v0 -= 26;
    EmptyStub_b160();
    --v1;
  }
  while ( v1 );
}

