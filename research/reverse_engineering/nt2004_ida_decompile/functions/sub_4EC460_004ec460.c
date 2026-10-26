char *__stdcall sub_4EC460(int a1)
{
  int v1; // eax

  v1 = sub_4EC450() - 100;
  if ( a1 >= v1 )
    sprintf(byte_7D6B64, "%d", a1 - v1 + 100);
  else
    sprintf(byte_7D6B64, "%d", dword_610F1C[a1]);
  return byte_7D6B64;
}
