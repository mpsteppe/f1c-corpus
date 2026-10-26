int __thiscall sub_561A50(int *this)
{
  int v1; // eax

  v1 = *this;
  this[3] = 0;
  return (*(int (**)(void))(v1 + 16))();
}
