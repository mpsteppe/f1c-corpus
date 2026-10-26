int __stdcall sub_676756(_DWORD *Block)
{
  int v1; // eax
  int v2; // esi

  v1 = Block[1];
  v2 = v1 - 1;
  Block[1] = v1 - 1;
  if ( v1 == 1 )
    sub_646093(Block, 1);
  return v2;
}
