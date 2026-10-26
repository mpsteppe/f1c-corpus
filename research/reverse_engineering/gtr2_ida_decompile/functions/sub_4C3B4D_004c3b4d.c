// positive sp value has been detected, the output may be wrong!
int __stdcall sub_4C3B4D(int a1)
{
  int retaddr; // [esp+0h] [ebp+0h]

  retaddr = 111;
  if ( operator new(0x118u) )
    return sub_4BD5E0();
  else
    return ((int (__stdcall *)(int))sub_4CC3A1)(a1);
}
