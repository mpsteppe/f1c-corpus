void __thiscall sub_532290(_DWORD *this, _BYTE *a2, unsigned int a3)
{
  char *v3; // eax
  int v4; // eax

  if ( a2 )
  {
    *a2 = 0;
    v3 = (char *)this[2];
    if ( !v3 )
      v3 = (char *)WindowName;
    sub_539600(v3);
    v4 = sub_538790(&unk_BE1CDC);
    if ( v4 )
    {
      if ( a3 > 1 )
      {
        sub_630FE0(a2, v4 + 1724, a3 - 1);
        a2[a3 - 1] = 0;
      }
    }
  }
}
