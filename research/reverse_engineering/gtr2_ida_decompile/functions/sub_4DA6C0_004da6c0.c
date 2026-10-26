void __thiscall sub_4DA6C0(int this)
{
  int v2; // eax
  char *v3; // eax
  _DWORD *v4; // edi

  if ( *(_DWORD *)(this + 152) )
  {
    v2 = sub_5C2520();
    if ( v2 )
    {
      v3 = *(char **)(v2 + 36);
      if ( !v3 )
        v3 = (char *)WindowName;
      v4 = sub_4D39F0(*(_DWORD **)(this + 268), v3);
      if ( v4 )
      {
        sub_4DA470((int *)(this + 272));
        sub_4D5AD0((int)v4);
      }
    }
  }
}
