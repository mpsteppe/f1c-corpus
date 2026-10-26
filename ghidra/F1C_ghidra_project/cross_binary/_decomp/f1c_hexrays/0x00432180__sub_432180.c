// f1c  0x00432180  size=152
char __thiscall sub_432180(char **this)
{
  char v3[512]; // [esp+10h] [ebp-200h] BYREF

  v3[0] = 0;
  sub_4B0220(v3, 512);
  strcat(v3, off_5C3FA0[0]);
  *(_WORD *)&v3[strlen(v3)] = word_5C2AAC;
  sub_566650(v3);
  sub_566650(&byte_5EA438);
  sub_431DB0(*this, 0);
  return 1;
}
