// positive sp value has been detected, the output may be wrong!
int __userpurge sub_496E97@<eax>(void *a1@<ebx>, int a2)
{
  void *v2; // eax

  v2 = operator new(0x138u);
  if ( v2 == a1 )
    return sub_49A511(a2);
  else
    return sub_48D5B0((int)v2);
}
