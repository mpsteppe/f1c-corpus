void __thiscall sub_5ECB80(void **this)
{
  void **v2; // eax

  v2 = (void **)this[113];
  if ( v2 )
  {
    j__free(v2[3]);
    j__free(this[113]);
    this[113] = 0;
  }
}
