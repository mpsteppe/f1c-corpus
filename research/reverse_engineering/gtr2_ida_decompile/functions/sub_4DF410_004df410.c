void __thiscall sub_4DF410(_DWORD *this, const char *a2)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // eax

  if ( a2 && strlen(a2) && *(_DWORD *)(this[6] + 68) )
  {
    v3 = sub_4DEF00(this, (int)a2);
    v4 = (_DWORD *)v3;
    if ( v3 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 132))(v3);
      this[8] = v4;
      v5 = v4[1];
      this[22] = v4[3];
      this[23] = v5;
      (*(void (__thiscall **)(_DWORD *))(*v4 + 136))(v4);
    }
  }
}
