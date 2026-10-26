// f1c  0x005038c0  size=47
int sub_5038C0()
{
  int (*v0)(); // eax

  if ( sub_50FC7D() )
  {
    v0 = (int (*)())sub_503772;
    off_5D76C0 = (_DWORD (*)())sub_503772;
  }
  else
  {
    off_5D76C0 = (_DWORD (*)())sub_503533;
    v0 = (int (*)())sub_50368A;
  }
  off_5D76C4 = v0;
  return v0();
}
