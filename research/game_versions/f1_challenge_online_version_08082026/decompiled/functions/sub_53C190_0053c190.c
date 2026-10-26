int sub_53C190()
{
  char *v0; // esi
  int v1; // edi
  int result; // eax

  v0 = (char *)&unk_8B6C28;
  v1 = 42;
  do
  {
    result = sub_556220(v0);
    v0 += 76;
    --v1;
  }
  while ( v1 );
  return result;
}
