std::ios_base *__thiscall sub_5BCEA0(std::ios_base *Block, char a2)
{
  std::ios_base::~ios_base(Block);
  if ( (a2 & 1) != 0 )
    j__free(Block);
  return Block;
}
