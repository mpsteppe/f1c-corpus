int sub_57AB50()
{
  int i; // esi
  _BYTE *v1; // edi
  void *v2; // ebp
  int result; // eax

  for ( i = dword_8D3BFC; i; result = FreeWrapper_7bcf(v1) )
  {
    v1 = (_BYTE *)i;
    i = *(_DWORD *)(i + 4);
    if ( v1[12] )
    {
      v2 = *(void **)v1;
      if ( *(_DWORD *)v1 )
      {
        VTableDestructorThenNullPointer(*(_DWORD **)v1);
        FreeWrapper_7bcf(v2);
      }
    }
  }
  dword_8D3BFC = 0;
  dword_8D3C00 = 0;
  dword_8D3C04 = 0;
  dword_8D3C08 = 0;
  return result;
}
