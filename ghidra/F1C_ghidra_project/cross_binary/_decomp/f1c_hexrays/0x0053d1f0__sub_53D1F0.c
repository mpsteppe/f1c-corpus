// f1c  0x0053d1f0  size=100
int __stdcall sub_53D1F0(const char *a1)
{
  int v1; // edi

  v1 = dword_8B8E20;
  if ( !dword_8B8E20 )
    return 0;
  while ( strcmp((const char *)(v1 + 20), a1) )
  {
    v1 = *(_DWORD *)(v1 + 2160);
    if ( !v1 )
      return 0;
  }
  return v1;
}
