int __cdecl sub_58A770(int *a1, int a2)
{
  int v2; // ebp
  int v3; // esi
  void (__stdcall *v4)(int *); // eax

  v2 = *a1;
  v3 = a1[6];
  if ( v3 != __readfsdword(0) )
    sub_588864((PVOID)a1[6]);
  if ( v3 )
  {
    if ( sub_593D53(a1 + 8) && a1[8] == 1447244336 )
    {
      v4 = (void (__stdcall *)(int *))a1[9];
      if ( v4 )
        v4(a1);
    }
    else
    {
      sub_5888A6(v3, a1[7]);
    }
  }
  sub_58893A(a1[5], v2, 0);
  return ((int (*)(void))a1[5])();
}
