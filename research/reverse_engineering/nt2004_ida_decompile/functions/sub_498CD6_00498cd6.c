// positive sp value has been detected, the output may be wrong!
int __userpurge sub_498CD6@<eax>(void *a1@<ebx>, int a2)
{
  void *v2; // eax

  v2 = operator new(0x364u);
  if ( v2 == a1 )
    return sub_49A511(a2);
  else
    return sub_4870F0((int)v2);
}
