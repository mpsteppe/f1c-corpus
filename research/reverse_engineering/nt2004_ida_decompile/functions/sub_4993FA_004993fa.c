// positive sp value has been detected, the output may be wrong!
int __userpurge sub_4993FA@<eax>(void *a1@<ebx>, int a2)
{
  void *v2; // eax

  v2 = operator new(0x378u);
  if ( v2 == a1 )
    return sub_49A511(a2);
  else
    return ((int (__thiscall *)(void *))sub_49B310)(v2);
}
