int __thiscall sub_6ABEBF(char *this)
{
  unsigned int v2; // edi
  void *v3; // ecx
  unsigned int v4; // edi
  void *v5; // ecx
  void **v6; // edi
  int v7; // ebx
  void *v9; // [esp-4h] [ebp-10h]

  v9 = (void *)*((_DWORD *)this + 139);
  *(_DWORD *)this = &off_743628;
  j__free(v9);
  j__free(*((void **)this + 140));
  v2 = 0;
  if ( *((_DWORD *)this + 173) && *((_DWORD *)this + 176) )
  {
    do
    {
      v3 = *(void **)(*((_DWORD *)this + 173) + 4 * v2);
      if ( v3 )
        sub_66238F(v3, 1);
      ++v2;
    }
    while ( v2 < *((_DWORD *)this + 176) );
  }
  v4 = 0;
  if ( *((_DWORD *)this + 174) && *((_DWORD *)this + 175) )
  {
    do
    {
      v5 = *(void **)(*((_DWORD *)this + 174) + 4 * v4);
      if ( v5 )
        sub_663A9B(v5, 1);
      ++v4;
    }
    while ( v4 < *((_DWORD *)this + 175) );
  }
  v6 = (void **)(this + 708);
  v7 = 16;
  do
  {
    if ( *v6 )
      sub_66238F(*v6, 1);
    *v6++ = 0;
    --v7;
  }
  while ( v7 );
  j__free(*((void **)this + 173));
  j__free(*((void **)this + 174));
  return sub_6C6A29(this);
}
