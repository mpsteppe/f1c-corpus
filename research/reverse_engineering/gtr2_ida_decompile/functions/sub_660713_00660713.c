void *__thiscall sub_660713(_DWORD *this)
{
  unsigned int i; // esi
  void *v3; // ecx
  void *result; // eax

  for ( i = 0; i < 7; ++i )
  {
    v3 = (void *)this[i];
    if ( v3 )
      result = sub_6606F2(v3, 1);
  }
  return result;
}
