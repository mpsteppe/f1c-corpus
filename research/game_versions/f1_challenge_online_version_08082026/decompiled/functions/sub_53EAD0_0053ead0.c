int __thiscall sub_53EAD0(int *this, int a2)
{
  void *v3; // edi
  void *v4; // edi
  void *v5; // edi
  int result; // eax

  sub_53F270(0);
  if ( this[1355] )
  {
    sub_53F6E0(this[1355]);
    v3 = (void *)this[1355];
    if ( v3 )
    {
      j_nullsub_3(this[1355]);
      sub_587BCF(v3);
    }
    this[1355] = 0;
  }
  v4 = (void *)this[1353];
  if ( v4 )
  {
    j_nullsub_3(this[1353]);
    sub_587BCF(v4);
    this[1353] = 0;
  }
  v5 = (void *)this[1354];
  if ( v5 )
  {
    j_nullsub_3(this[1354]);
    sub_587BCF(v5);
    this[1354] = 0;
  }
  result = this[1088];
  if ( result )
  {
    result = (*(int (__stdcall **)(int))(*(_DWORD *)result + 8))(this[1088]);
    *this = result;
    this[1088] = 0;
  }
  return result;
}
