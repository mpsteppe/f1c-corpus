int __thiscall sub_4EDDD0(char *this, char *Source)
{
  char *v3; // edi

  v3 = this + 24772;
  strncpy(this + 24772, Source, 0x3Fu);
  v3[63] = 0;
  return sub_4EDF00(this);
}
