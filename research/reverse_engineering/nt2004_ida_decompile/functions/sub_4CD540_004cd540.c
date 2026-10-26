int __stdcall sub_4CD540(const char *a1, char *Buffer)
{
  if ( !a1 || !Buffer )
    return -1;
  sub_4CD510(a1, Buffer);
  strcat(Buffer, a1);
  strcat(Buffer, ".PLR");
  return 0;
}
