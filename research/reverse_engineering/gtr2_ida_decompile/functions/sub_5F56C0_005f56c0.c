int __stdcall sub_5F56C0(int a1, unsigned __int64 *a2)
{
  unsigned __int64 v2; // rax

  LODWORD(v2) = a1;
  if ( a1 )
  {
    LODWORD(v2) = a2;
    if ( a2 )
    {
      v2 = __rdtsc();
      *a2 = v2;
    }
  }
  return v2;
}
