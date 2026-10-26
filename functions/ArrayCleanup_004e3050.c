void *__thiscall sub_4E3050(void **this)
{
  void **v1; // esi
  int v2; // edi
  void *result; // eax
  bool v4; // zf

  v1 = this + 125;
  v2 = 4;
  do
  {
    result = *v1;
    v4 = *v1 == 0;
    *(v1 - 1) = 0;
    if ( !v4 )
      result = (void *)FreeWrapper_7bcf(result);
    *v1 = 0;
    v1 += 74;
    --v2;
  }
  while ( v2 );
  return result;
}
