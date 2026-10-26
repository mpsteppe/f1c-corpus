int __thiscall sub_563000(_DWORD *this)
{
  int result; // eax

  for ( ; *this; result = SleepWrapper(0xAu) )
    sub_563410(this);
  return result;
}
