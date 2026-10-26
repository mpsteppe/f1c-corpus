int sub_4B01A0()
{
  int v0; // eax
  char FileName[256]; // [esp+10h] [ebp-100h] BYREF

  sub_4ABA50();
  v0 = _chmod(FileName, 384);
  if ( v0 )
  {
    if ( v0 == -1 )
    {
      sub_4364D0();
      sub_437830();
    }
    return 0;
  }
  else
  {
    sub_4E1810("GARAGE_SAVE_FILE_OVERWRITE_CONFIRMATION", 0);
    return -1;
  }
}
