int __thiscall sub_4D7A00(int *this, int a2)
{
  int result; // eax

  result = sub_587C20(a2, aNotrace);
  if ( !result )
  {
    *this = 3000;
    return TraceLogInit(this);
  }
  return result;
}
