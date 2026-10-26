int __stdcall sub_4B9830(int a1)
{
  char *v1; // eax

  v1 = (char *)lpPathName;
  if ( !lpPathName )
    v1 = byte_5EA438;
  StringCopyWithBufferRealloc(v1);
  return sub_5665B0(aVcrTmp);
}

