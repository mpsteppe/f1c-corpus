int sub_492430()
{
  char *v0; // eax

  if ( !byte_B6CBCC )
    return 0;
  byte_B6CBCC = 0;
  v0 = sub_41D840(&byte_91CC38, "Lost connection with the Host");
  sub_615860(v0);
  sub_4E1810("Join Failure Page", 0);
  return -1;
}
