int __thiscall sub_501600(int *this)
{
  int v1; // eax

  v1 = *this;
  this[3] = 0;
  return (*(int (**)(void))(v1 + 16))();
}
