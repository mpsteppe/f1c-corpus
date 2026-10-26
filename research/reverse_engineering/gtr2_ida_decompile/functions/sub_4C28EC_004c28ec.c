// positive sp value has been detected, the output may be wrong!
int __stdcall sub_4C28EC(int a1)
{
  int retaddr; // [esp+0h] [ebp+0h]

  retaddr = 37;
  if ( operator new(0x25Cu) )
    return sub_48C250();
  else
    return ((int (__stdcall *)(int))sub_4CC3A1)(a1);
}
