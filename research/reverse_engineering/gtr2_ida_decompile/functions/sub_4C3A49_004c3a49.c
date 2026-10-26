// positive sp value has been detected, the output may be wrong!
int __stdcall sub_4C3A49(int a1)
{
  int retaddr; // [esp+0h] [ebp+0h]

  retaddr = 107;
  if ( operator new(0x118u) )
    return sub_48CC90();
  else
    return ((int (__stdcall *)(int))sub_4CC3A1)(a1);
}
