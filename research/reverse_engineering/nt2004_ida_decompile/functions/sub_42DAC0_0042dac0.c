int sub_42DAC0()
{
  char *v0; // esi
  int v1; // edi
  int result; // eax

  v0 = (char *)&unk_62BF68;
  v1 = 49;
  do
  {
    result = sub_4EDD70(v0);
    v0 += 25304;
    --v1;
  }
  while ( v1 );
  return result;
}
