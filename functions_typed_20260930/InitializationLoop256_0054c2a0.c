void InitializationLoop256()
{
  char *v0; // esi
  int v1; // edi

  v0 = (char *)&unk_8BF740;
  v1 = 256;
  do
  {
    v0 -= 104;
    EmptyStub_b160();
    --v1;
  }
  while ( v1 );
}

