// f1c  0x004dcd10  size=66
int __thiscall sub_4DCD10(_DWORD *this)
{
  int v2; // ecx
  void *v3; // edi

  v2 = this[1];
  if ( v2 )
  {
    sub_5502C0(v2);
    v3 = (void *)this[1];
    if ( v3 )
    {
      j_nullsub_3(this[1]);
      sub_587BCF(v3);
    }
  }
  if ( *this )
    sub_5539F0(*this);
  return sub_4DCB70(this);
}
