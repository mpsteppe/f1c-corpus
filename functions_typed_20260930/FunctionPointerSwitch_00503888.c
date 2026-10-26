int sub_503888()
{
  if ( sub_50FC7D() )
  {
    off_5D76C0 = (_DWORD (*)())sub_503772;
    off_5D76C4 = (int (*)())sub_503772;
  }
  else
  {
    off_5D76C0 = (_DWORD (*)())ImageBlendingCompositing;
    off_5D76C4 = (int (*)())F_2DImageBoxFilter;
  }
  return off_5D76C0();
}

