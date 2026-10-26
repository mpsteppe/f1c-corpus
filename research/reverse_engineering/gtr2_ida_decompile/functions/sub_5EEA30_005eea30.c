int __userpurge sub_5EEA30@<eax>(int a1@<ecx>, int a2@<edi>, void *Block, char a4)
{
  int *v4; // edi
  void **v5; // eax
  char v8; // [esp+0h] [ebp-4h]

  if ( Block )
  {
    v4 = &dword_FB284C;
    if ( !a4 )
      v4 = &dword_FB27B4;
    sub_5EE890((int)Block);
    v5 = (void **)*v4;
    if ( !*v4 )
      goto LABEL_8;
    while ( !*v5 || *v5 != Block )
    {
      v5 = (void **)v5[1];
      if ( !v5 )
        goto LABEL_8;
    }
    if ( *v5 )
    {
      sub_5E2630(v4, (int)Block, 1);
      return 0;
    }
    else
    {
LABEL_8:
      sub_5EE840(Block, (__int32)Block, a2);
      j__free(Block);
      return 0;
    }
  }
  else
  {
    sub_5D8C80(a1, (char *)0xFFFFFFFF, "Invalid MAS file return pointer", v8);
    return -1;
  }
}
