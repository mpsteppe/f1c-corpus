char __stdcall sub_45D040(const char *a1, const char *a2, char *Destination, int a4)
{
  char result; // al
  char Source[512]; // [esp+Ch] [ebp-200h] BYREF

  if ( a2 && strlen(a2) )
  {
    sub_45D000(a1, Source, 0x200u);
    strcat(Source, a2);
    strncpy(Destination, Source, a4 - 1);
    Destination[a4 - 1] = 0;
    return 1;
  }
  else
  {
    result = 0;
    *Destination = 0;
  }
  return result;
}
