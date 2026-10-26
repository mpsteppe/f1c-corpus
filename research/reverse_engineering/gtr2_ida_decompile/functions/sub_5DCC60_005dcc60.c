int __userpurge sub_5DCC60@<eax>(
        int a1@<ecx>,
        int a2@<ebp>,
        int **a3,
        char *a4,
        const char *ArgList,
        _DWORD *Block,
        __int16 a7)
{
  int *v8; // eax
  int *v9; // esi
  bool v10; // zf
  int v11; // eax

  v8 = (int *)operator new(0x28Cu);
  if ( v8 )
    v9 = sub_5DB7E0(v8);
  else
    v9 = 0;
  v9[155] = a1;
  sub_5DAC00((char *)v9, a4, a7);
  if ( sub_5DC7E0((int)v9, a2, ArgList, Block) )
  {
    sub_5DBA90(v9);
    j__free(v9);
    return -1;
  }
  else
  {
    v10 = (*(_BYTE *)v9 & 0x10) == 0;
    *v9 &= ~0x400u;
    if ( v10 )
    {
      sub_5FDFB0(v9, 1);
      v11 = *v9 | 0x200000;
    }
    else
    {
      sub_5FDFB0(v9, 1);
      v11 = *v9 | 0x100000;
    }
    *v9 = v11;
    if ( a3 )
      *a3 = v9;
    return 0;
  }
}
