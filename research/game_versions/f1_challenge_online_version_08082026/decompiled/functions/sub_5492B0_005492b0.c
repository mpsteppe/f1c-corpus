void __thiscall sub_5492B0(_DWORD *this)
{
  _DWORD *i; // edi
  int *v3; // eax
  int *v4; // esi

  for ( i = (_DWORD *)this[60]; i; i = (_DWORD *)i[13] )
  {
    v3 = (int *)sub_5456B0((_DWORD *)*this, (const char *)(*i + 88));
    v4 = v3;
    if ( v3 )
    {
      sub_5455F0((_DWORD *)*this, v3);
      sub_549250(this, v4);
    }
  }
}
