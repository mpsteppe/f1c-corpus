char *__fastcall sub_431E20(char *Destination, char *Source, size_t Count)
{
  char *result; // eax

  result = strncpy(Destination, Source, Count);
  Destination[Count] = 0;
  return result;
}
