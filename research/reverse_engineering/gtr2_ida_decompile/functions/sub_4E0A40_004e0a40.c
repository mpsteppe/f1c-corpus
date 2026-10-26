std::locale::_Locimp *__thiscall sub_4E0A40(std::locale::_Locimp *Block, char a2)
{
  sub_4DF6F0(Block);
  if ( (a2 & 1) != 0 )
    j__free(Block);
  return Block;
}
