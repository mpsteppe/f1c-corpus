void __thiscall sub_4988D0(_DWORD *this, const char *a2)
{
  int v3; // eax
  _DWORD *v4; // esi

  if ( a2 && strlen(a2) && *(_DWORD *)(this[6] + 80) )
  {
    v3 = RenderingContextSetup(this, (int)a2);
    v4 = (_DWORD *)v3;
    if ( v3 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 140))(v3);
      Setter(this, (int)v4);
      TwoFieldSetter_3050(v4[3], v4[1]);
      (*(void (__thiscall **)(_DWORD *))(*v4 + 144))(v4);
    }
  }
}
