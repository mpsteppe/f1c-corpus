void *__fastcall sub_4BF330(void *Block, __int32 a2, char a3)
{
  int v5; // [esp+0h] [ebp-4h]

  sub_4BF600(a2, v5);
  if ( (a3 & 1) != 0 )
    j__free(Block);
  return Block;
}
