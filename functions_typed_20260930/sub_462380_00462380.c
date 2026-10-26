int __thiscall sub_462380(void *this)
{
  int v1; // esi
  char *v2; // ecx
  int v3; // edx
  int v4; // ecx

  v1 = 0;
  if ( *(int *)(*(_DWORD *)this + 15892) > 0 )
  {
    v2 = (char *)(*(_DWORD *)this + 916);
    do
    {
      if ( FlagBitTest(v2, 2) )
        ++v1;
      v2 = (char *)(v4 + 140);
    }
    while ( v3 != 1 );
  }
  return v1;
}

