// f1c  0x004d7a00  size=66
int __thiscall sub_4D7A00(int *this, int a2)
{
  int result; // eax

  result = sub_587C20(a2, aNotrace);
  if ( !result )
  {
    *this = 3000;
    return sub_4D7960(this);
  }
  return result;
}
