// f1c  0x004064c0  size=81
int __thiscall sub_4064C0(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // edi

  if ( this[3] )
    sub_406750(this);
  v2 = this + 7;
  v3 = 3;
  do
  {
    sub_566650(&byte_5EA438);
    *(v2 - 1) = -1;
    *v2 = -1;
    *((_BYTE *)v2 + 4) = 0;
    v2 += 5;
    --v3;
  }
  while ( v3 );
  return sub_406700(0);
}
