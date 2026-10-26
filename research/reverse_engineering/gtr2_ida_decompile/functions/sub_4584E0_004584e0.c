void __thiscall sub_4584E0(void **this)
{
  int v1; // ebx
  void **v3; // esi

  v3 = this + 21;
  v1 = dword_16C9998;
  do
  {
    if ( *v3 )
    {
      sub_4584E0();
      j__free(*v3);
      *v3 = 0;
    }
    ++v3;
    --v1;
  }
  while ( v1 );
  if ( this[25] )
  {
    sub_4584E0();
    j__free(this[25]);
    this[25] = 0;
  }
}
