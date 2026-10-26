void __thiscall sub_594530(_DWORD *this)
{
  _DWORD *i; // edi
  int *v3; // eax
  int *v4; // esi

  for ( i = (_DWORD *)this[60]; i; i = (_DWORD *)i[13] )
  {
    v3 = (int *)sub_597960(*i + 184);
    v4 = v3;
    if ( v3 )
    {
      sub_5978A0(v3);
      sub_5944C0(this, v4);
    }
  }
}
