_DWORD *__thiscall sub_5D0664(_DWORD *this, char *Buffer, size_t Size)
{
  FILE *v4; // eax

  v4 = (FILE *)this[20];
  if ( !v4 || setvbuf(v4, Buffer, 0, Size) )
    return 0;
  else
    return this;
}
