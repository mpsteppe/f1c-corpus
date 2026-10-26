void __thiscall sub_51C920(_DWORD *this)
{
  _DWORD *v2; // esi
  void *v3; // edi

  v2 = (_DWORD *)*this;
  if ( *this )
  {
    do
    {
      v3 = v2;
      v2 = (_DWORD *)v2[1];
      sub_51F400(v3);
      j__free(v3);
    }
    while ( v2 );
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
}
