int sub_4B1A40()
{
  int *v0; // esi
  int result; // eax
  void *v2; // edi

  v0 = dword_766080;
  do
  {
    if ( *v0 )
    {
      result = sub_506920(*v0);
      v2 = (void *)*v0;
      if ( *v0 )
      {
        sub_506920(*v0);
        result = sub_5BE8AE(v2);
      }
      *v0 = 0;
    }
    ++v0;
  }
  while ( (int)v0 < (int)&dword_7660CC );
  return result;
}
