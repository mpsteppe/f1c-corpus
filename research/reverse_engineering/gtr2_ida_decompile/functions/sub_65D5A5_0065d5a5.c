void __thiscall sub_65D5A5(void **this)
{
  void *v2; // edi

  if ( *this )
  {
    do
    {
      v2 = *(void **)*this;
      j__free(*this);
      *this = v2;
    }
    while ( v2 );
  }
  j__free(this[6]);
  j__free(this[7]);
}
