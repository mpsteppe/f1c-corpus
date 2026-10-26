char *__thiscall sub_431A50(char *this, char *Source)
{
  char *v2; // esi
  char *result; // eax

  v2 = this + 112;
  result = strncpy(this + 112, Source, 0x3Fu);
  v2[63] = 0;
  return result;
}
