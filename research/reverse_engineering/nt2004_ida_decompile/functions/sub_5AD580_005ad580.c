void __thiscall sub_5AD580(void **this)
{
  _DWORD *v2; // eax
  int v3; // ecx
  char *v4; // esi
  int v5; // ecx
  int v6; // edi

  if ( *this )
  {
    j_nullsub_6(*this);
    sub_5BE8AE();
  }
  v2 = this[6];
  *this = 0;
  if ( v2 )
  {
    v3 = *(v2 - 1);
    v4 = (char *)&v2[34 * v3];
    v5 = v3 - 1;
    if ( v5 >= 0 )
    {
      v6 = v5 + 1;
      do
      {
        v4 -= 136;
        j_nullsub_6(v4);
        --v6;
      }
      while ( v6 );
    }
    sub_5BE8AE();
  }
  this[6] = 0;
  nullsub_6(this);
}
