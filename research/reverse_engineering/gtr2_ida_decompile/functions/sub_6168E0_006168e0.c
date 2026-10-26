void __userpurge sub_6168E0(int a1@<esi>, _DWORD *Block)
{
  __int32 v2; // esi
  void *v3; // eax

  if ( Block )
  {
    v2 = Block[2];
    while ( v2 )
    {
      v3 = (void *)v2;
      v2 = *(_DWORD *)(v2 + 4);
      sub_6168E0(v3);
    }
    sub_616580(v2, a1);
    j__free(Block);
  }
}
