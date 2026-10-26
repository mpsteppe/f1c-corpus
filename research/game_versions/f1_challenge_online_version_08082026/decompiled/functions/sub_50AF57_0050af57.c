void __thiscall sub_50AF57(_DWORD *this, int a2, int a3, void *a4)
{
  if ( sub_50AB51((int)this, this[1037] + a2, this[1040] + a3, 1) >= 0 )
  {
    qmemcpy(a4, (const void *)(this[1051] + 16 * (this[1036] - this[1052])), 16 * this[1046]);
    if ( this[4] )
      sub_507845((int)this, (unsigned int)a4);
  }
}
