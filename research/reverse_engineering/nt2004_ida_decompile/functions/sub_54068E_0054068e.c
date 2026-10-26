int sub_54068E()
{
  if ( sub_54CBF1() )
  {
    off_617340 = (_DWORD (*)())sub_540578;
    off_617344 = (int (*)())sub_540578;
  }
  else
  {
    off_617340 = (_DWORD (*)())sub_540339;
    off_617344 = (int (*)())sub_540490;
  }
  return off_617340();
}
