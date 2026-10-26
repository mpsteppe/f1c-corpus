int __thiscall sub_681B0A(void *this, int a2, int a3, int a4)
{
  _DWORD *v5; // eax
  _DWORD *v6; // esi

  v5 = (_DWORD *)sub_681186(116);
  if ( v5 )
    v6 = sub_680CEC(v5);
  else
    v6 = 0;
  if ( !v6 )
    return -1;
  if ( sub_6811D1((char *)v6, a2, a3, a4, 0) < 0 )
  {
    sub_66238F(v6, 1);
    return -1;
  }
  return sub_681997((int)this, v6);
}
