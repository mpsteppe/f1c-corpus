int RepeatedCallLoop()
{
  char *v0; // esi
  int v1; // edi
  int result; // eax

  v0 = (char *)&unk_5EC6D8;
  v1 = 104;
  do
  {
    result = VehicleObjectConstructor(v0);
    v0 += 18624;
    --v1;
  }
  while ( v1 );
  return result;
}
