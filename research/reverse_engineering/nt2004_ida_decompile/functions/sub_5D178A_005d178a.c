_DWORD *__thiscall sub_5D178A(_DWORD *this, char *Buffer, int a3)
{
  FILE *v4; // eax

  v4 = (FILE *)this[20];
  if ( !v4 || setvbuf(v4, Buffer, 0, 2 * a3) )
    return 0;
  else
    return this;
}
