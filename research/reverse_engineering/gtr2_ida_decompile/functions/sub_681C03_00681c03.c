int __thiscall sub_681C03(void *this, _DWORD *a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi

  v3 = (_DWORD *)sub_681186(116);
  if ( v3 )
    v4 = sub_680CEC(v3);
  else
    v4 = 0;
  if ( !v4 )
    return -1;
  if ( sub_681430((char *)v4, a2) < 0 )
  {
    sub_66238F(v4, 1);
    return -1;
  }
  return sub_681997((int)this, v4);
}
