// f1c  0x004b01b0  size=103
int __stdcall sub_4B01B0(const char *a1, char *a2)
{
  if ( !a1 || !a2 )
    return -1;
  sub_4B0180(a1, (int)a2);
  strcat(a2, a1);
  strcat(a2, ".PLR");
  return 0;
}
