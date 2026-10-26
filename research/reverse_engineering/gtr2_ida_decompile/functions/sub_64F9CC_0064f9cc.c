void __thiscall sub_64F9CC(void *this)
{
  bool v2; // zf
  unsigned int v3; // edi
  unsigned int j; // ebx
  int i; // [esp+4h] [ebp-4h]

  v2 = *((_DWORD *)this + 61) == 0;
  *(_DWORD *)this = &off_737514;
  if ( !v2 )
  {
    if ( *((_DWORD *)this + 62) )
    {
      v3 = *((_DWORD *)this + 53);
      for ( i = *((_DWORD *)this + 62); v3 < *((_DWORD *)this + 54); ++v3 )
      {
        for ( j = *((_DWORD *)this + 50); j < *((_DWORD *)this + 52); j += 4 )
        {
          j__free(*(void **)(i + 4));
          i += 8;
        }
      }
    }
  }
  j__free(*((void **)this + 60));
  j__free(*((void **)this + 62));
  sub_64EAFF(this);
}
