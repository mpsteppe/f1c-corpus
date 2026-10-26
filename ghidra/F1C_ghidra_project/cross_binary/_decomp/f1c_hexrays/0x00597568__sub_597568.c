// f1c  0x00597568  size=94
int __cdecl sub_597568(unsigned int *a1, unsigned int *a2)
{
  if ( sub_597547(*a1, *a2, a1) && sub_597547(a1[1], 1u, a1 + 1) )
    ++a1[2];
  if ( sub_597547(a1[1], a2[1], a1 + 1) )
    ++a1[2];
  return sub_597547(a1[2], a2[2], a1 + 2);
}
