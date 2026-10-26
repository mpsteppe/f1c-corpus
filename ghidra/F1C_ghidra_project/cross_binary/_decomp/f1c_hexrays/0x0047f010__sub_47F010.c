// f1c  0x0047f010  size=109
int sub_47F010()
{
  char *v0; // esi

  v0 = sub_462E00(dword_7CD25C);
  if ( v0 && strlen(v0) )
  {
    if ( sub_423A00(byte_5EC4C0, v0, byte_5EC4CC) )
      strcpy(byte_5EC4CC, v0);
    sub_488B40(byte_5EC4CC);
    return 0;
  }
  else
  {
    sub_488B40(byte_5EA438);
    return 0;
  }
}
