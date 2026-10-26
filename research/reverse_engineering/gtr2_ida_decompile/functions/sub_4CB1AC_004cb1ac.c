// positive sp value has been detected, the output may be wrong!
int __stdcall sub_4CB1AC(int a1)
{
  int retaddr; // [esp+0h] [ebp+0h]

  retaddr = 572;
  if ( operator new(0x118u) )
    return sub_4BDEA0();
  else
    return ((int (__stdcall *)(int))sub_4CC3A1)(a1);
}
