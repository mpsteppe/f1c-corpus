int sub_42DD20()
{
  int v0; // edi
  char *v1; // esi
  int result; // eax

  byte_75AB9C = 0;
  v0 = 0;
  v1 = (char *)&unk_62BFBC;
  do
  {
    sub_4EDDB0(v0);
    result = sub_51BC20(-1, 0);
    v1 += 25304;
    ++v0;
  }
  while ( (int)v1 < (int)byte_75AB14 );
  return result;
}
