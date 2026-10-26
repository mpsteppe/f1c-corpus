void __thiscall sub_5BC8A0(void **this)
{
  void *v2; // ecx
  int v3; // edi
  _DWORD *v4; // eax

  v2 = this[2];
  if ( v2 )
  {
    v3 = 0;
    if ( sub_577650(v2) > 0 )
    {
      do
      {
        v4 = (_DWORD *)sub_5BE1B0(this[2], v3);
        sub_5BDB30(this, *v4);
        ++v3;
      }
      while ( v3 < sub_577650(this[2]) );
    }
    sub_5BE160(this[2]);
    this[2] = 0;
  }
}
