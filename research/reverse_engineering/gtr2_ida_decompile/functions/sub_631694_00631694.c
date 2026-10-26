type_info *__thiscall sub_631694(type_info *Block, char a2)
{
  type_info::~type_info(Block);
  if ( (a2 & 1) != 0 )
    j__free(Block);
  return Block;
}
