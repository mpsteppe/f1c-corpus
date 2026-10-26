void sub_4C2FC0()
{
  int v0; // eax
  void *v1; // ebx
  char *v2; // esi
  int v3; // eax
  int v4; // edi

  if ( dword_8AC394 )
  {
    v0 = *(_DWORD *)(dword_8AC394 - 4);
    v1 = (void *)(dword_8AC394 - 4);
    v2 = (char *)(dword_8AC394 + 1060 * v0);
    v3 = v0 - 1;
    if ( v3 >= 0 )
    {
      v4 = v3 + 1;
      do
      {
        v2 -= 1060;
        MultiFieldCleanup(v2);
        --v4;
      }
      while ( v4 );
    }
    FreeWrapper_7bcf(v1);
  }
}
