int __thiscall sub_463BD0(void *this)
{
  int v1; // esi
  char *v2; // ecx
  int v3; // edx
  int v4; // ecx

  v1 = 0;
  if ( *(int *)(*(_DWORD *)this + 6512) > 0 )
  {
    v2 = (char *)(*(_DWORD *)this + 752);
    do
    {
      if ( sub_462C60(v2, 2) )
        ++v1;
      v2 = (char *)(v4 + 116);
    }
    while ( v3 != 1 );
  }
  return v1;
}
