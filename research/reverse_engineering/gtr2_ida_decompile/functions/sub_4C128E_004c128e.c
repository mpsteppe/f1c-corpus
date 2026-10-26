// positive sp value has been detected, the output may be wrong!
int __stdcall sub_4C128E(int a1)
{
  int retaddr; // [esp+0h] [ebp+0h]

  retaddr = 4;
  if ( operator new(0x334u) )
    return sub_48D160();
  else
    return ((int (__stdcall *)(int))sub_4CC3A1)(a1);
}
