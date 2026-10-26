// positive sp value has been detected, the output may be wrong!
int __stdcall sub_4C3DCF(int a1)
{
  int retaddr; // [esp+Ch] [ebp+0h]

  retaddr = 121;
  if ( operator new(0x120u) )
    return sub_48CD70();
  else
    return ((int (__stdcall *)(int))sub_4CC3A1)(a1);
}
