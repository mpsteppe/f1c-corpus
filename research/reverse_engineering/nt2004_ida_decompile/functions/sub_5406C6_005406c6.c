int sub_5406C6()
{
  int (*v0)(); // eax

  if ( sub_54CBF1() )
  {
    v0 = (int (*)())sub_540578;
    off_617340 = (_DWORD (*)())sub_540578;
  }
  else
  {
    off_617340 = (_DWORD (*)())sub_540339;
    v0 = (int (*)())sub_540490;
  }
  off_617344 = v0;
  return v0();
}
