// positive sp value has been detected, the output may be wrong!
int __stdcall sub_4C2A74(int a1)
{
  int retaddr; // [esp+0h] [ebp+0h]

  retaddr = 43;
  if ( operator new(0x118u) )
    return sub_4BD2B0();
  else
    return ((int (__stdcall *)(int))sub_4CC3A1)(a1);
}
