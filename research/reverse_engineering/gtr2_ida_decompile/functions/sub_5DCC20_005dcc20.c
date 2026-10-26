int __userpurge sub_5DCC20@<eax>(
        char *a1@<ecx>,
        int a2@<ebp>,
        char *a3,
        const char *ArgList,
        _DWORD *Block,
        __int16 a6)
{
  sub_5DAC00(a1, a3, a6);
  if ( sub_5DC7E0((int)a1, a2, ArgList, Block) )
    return -1;
  *(_DWORD *)a1 &= ~0x400u;
  return 0;
}
