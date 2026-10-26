void *__userpurge sub_4E23D0@<eax>(void *Block@<ecx>, __int32 a2@<ebx>, char a3)
{
  sub_4E2110((int)Block, a2);
  if ( (a3 & 1) != 0 )
    j__free(Block);
  return Block;
}
