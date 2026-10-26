void __thiscall sub_6167F0(_DWORD *this)
{
  __int32 i; // esi
  void ***v3; // edi
  int v4; // [esp+0h] [ebp-Ch]

  for ( i = 0; i < 9; ++i )
  {
    v3 = (void ***)this[i];
    if ( v3 )
    {
      sub_616710(v3[1]);
      sub_616710(v3[2]);
      sub_616580(i, v4);
      j__free(v3);
    }
    this[i] = 0;
  }
}
