char *__thiscall sub_673378(
        void *this,
        int a2,
        int a3,
        const char *ArgList,
        int a5,
        const char *a6,
        int a7,
        _DWORD *a8,
        _DWORD *a9)
{
  if ( a8 )
    *a8 = 0;
  if ( a9 )
    *a9 = 0;
  if ( ArgList )
    return sub_672E89((int)this, a2, a3, ArgList, 0, 0, 0, a5, a6, a7, a8, a9);
  else
    return (char *)-2005530516;
}
