char __stdcall sub_478D30(void **Block)
{
  void **v1; // edi
  char result; // al
  void **i; // esi

  v1 = Block;
  result = *((_BYTE *)Block + 21);
  for ( i = Block; !result; v1 = i )
  {
    sub_478D30(i[2]);
    i = (void **)*i;
    j__free(v1);
    result = *((_BYTE *)i + 21);
  }
  return result;
}
