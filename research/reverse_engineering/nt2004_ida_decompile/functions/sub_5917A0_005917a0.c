int sub_5917A0()
{
  char *v0; // esi
  int v1; // edi
  int result; // eax

  v0 = (char *)&unk_7E5EC8;
  v1 = 42;
  do
  {
    result = sub_5AC560(v0);
    v0 += 76;
    --v1;
  }
  while ( v1 );
  return result;
}
