int sub_494630()
{
  int i; // esi
  _DWORD *v1; // edi
  bool v2; // zf
  void *v3; // ebp
  int result; // eax

  for ( i = dword_7CDDF0; i; result = FreeWrapper_7bcf(v1) )
  {
    v1 = (_DWORD *)i;
    v2 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v2 )
    {
      v3 = (void *)*v1;
      if ( *v1 )
      {
        EmptyStub_7470(*v1);
        FreeWrapper_7bcf(v3);
      }
    }
  }
  dword_7CDDF0 = 0;
  dword_7CDDF4 = 0;
  dword_7CDDF8 = 0;
  dword_7CDDFC = 0;
  return result;
}

