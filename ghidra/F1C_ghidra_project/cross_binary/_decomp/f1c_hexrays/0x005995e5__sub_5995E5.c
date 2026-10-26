// f1c  0x005995e5  size=48
void __thiscall sub_5995E5(_DWORD *this)
{
  _DWORD *v1; // esi
  char v2; // al
  char *v3; // eax

  v1 = (_DWORD *)this[1];
  if ( v1 )
  {
    v2 = *((_BYTE *)v1 - 1);
    if ( v2 )
    {
      if ( v2 != -1 )
      {
        sub_5993AF(this, 1);
        v3 = sub_58E1B0(v1);
        sub_599615(v1, v3);
      }
    }
  }
}
