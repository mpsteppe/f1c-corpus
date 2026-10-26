int __thiscall sub_4BACF0(_DWORD *this)
{
  const char *v2; // eax
  char v4[256]; // [esp+4h] [ebp-100h] BYREF

  sub_501490(v4, 256);
  v2 = (const char *)this[149];
  if ( !v2 )
    v2 = WindowName;
  if ( strcmp(v2, v4) )
    sub_4BA960();
  return 0;
}
