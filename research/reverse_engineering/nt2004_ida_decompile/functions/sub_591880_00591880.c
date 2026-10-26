int sub_591880()
{
  int *v0; // esi
  int v1; // edi
  int result; // eax

  v0 = &dword_7E4CC8;
  v1 = 32;
  do
  {
    result = sub_591D90(v0);
    v0 += 33;
    --v1;
  }
  while ( v1 );
  return result;
}
