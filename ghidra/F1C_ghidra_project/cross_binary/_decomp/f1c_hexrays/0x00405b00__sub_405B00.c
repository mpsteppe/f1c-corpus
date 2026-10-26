// f1c  0x00405b00  size=71
int __thiscall sub_405B00(LPVOID *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // eax

  (*((void (__thiscall **)(LPVOID *))*this + 2))(this);
  v2 = this[23];
  if ( v2 )
  {
    --v2[1];
    v3 = this[23];
    if ( (int)v3[1] <= 0 )
    {
      AIL_mem_free_lock(*v3);
      if ( this[23] )
        sub_587BCF(this[23]);
    }
    this[23] = 0;
  }
  return sub_407BE0(this);
}
