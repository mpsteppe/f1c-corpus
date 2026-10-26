// positive sp value has been detected, the output may be wrong!
int __stdcall sub_4CC2E5(int a1)
{
  int retaddr; // [esp+0h] [ebp+0h]

  retaddr = 643;
  if ( operator new(0x274u) )
    return sub_4BB460();
  else
    return ((int (__stdcall *)(int))sub_4CC3A1)(a1);
}
