int sub_4B1C00()
{
  char *v0; // esi
  int v1; // edi
  int result; // eax

  v0 = (char *)&unk_765D30;
  v1 = 6;
  do
  {
    result = sub_4B1C50(v0);
    v0 += 48;
    --v1;
  }
  while ( v1 );
  return result;
}
