// positive sp value has been detected, the output may be wrong!
int __stdcall sub_4C26FA(int a1)
{
  int retaddr; // [esp+0h] [ebp+0h]

  retaddr = 30;
  if ( operator new(0x118u) )
    return sub_48D8E0();
  else
    return ((int (__stdcall *)(int))sub_4CC3A1)(a1);
}
