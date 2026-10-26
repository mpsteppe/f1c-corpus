// f1c  0x004894d0  size=39
int __stdcall sub_4894D0(const char *a1)
{
  if ( !a1 )
    return -1;
  *(_WORD *)&a1[strlen(a1)] = word_5C692C;
  return 0;
}
