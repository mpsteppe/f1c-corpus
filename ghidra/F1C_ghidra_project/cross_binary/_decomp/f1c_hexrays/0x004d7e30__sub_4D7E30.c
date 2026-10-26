// f1c  0x004d7e30  size=12
int __thiscall sub_4D7E30(int *this)
{
  int v1; // eax

  v1 = *this;
  this[3] = 0;
  return (*(int (**)(void))(v1 + 16))();
}
