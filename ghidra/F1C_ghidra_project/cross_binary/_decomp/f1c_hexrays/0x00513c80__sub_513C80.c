// f1c  0x00513c80  size=83
char *__cdecl sub_513C80(int a1, int a2, int a3)
{
  unsigned int v3; // esi
  char *v4; // edx
  char *result; // eax
  void *v6; // edi
  unsigned int v7; // ecx

  v3 = a3 * a2;
  v4 = (char *)sub_517E92(a1, a3 * a2);
  result = 0;
  if ( v4 )
  {
    v6 = v4;
    if ( v3 <= 0x8000 )
    {
      v7 = a3 * a2;
    }
    else
    {
      memset(v4, 0, 0x8000u);
      v7 = v3 - 0x8000;
      v6 = v4 + 0x8000;
    }
    memset(v6, 0, v7);
    return v4;
  }
  return result;
}
