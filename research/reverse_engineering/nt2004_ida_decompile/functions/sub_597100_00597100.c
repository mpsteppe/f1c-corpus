int __thiscall sub_597100(void *this, _DWORD *a2, const char *a3)
{
  _DWORD *v4; // eax
  _DWORD *v5; // esi

  v4 = operator new(0x27Cu);
  if ( v4 && (v5 = sub_592FE0(v4)) != 0 )
  {
    *v5 = this;
    sub_593010((int)v5, a3);
    if ( a2 )
      *a2 = v5;
    return 0;
  }
  else
  {
    sub_591C60((int)this, -1, aErrorCreatingV_0);
    return -1;
  }
}
