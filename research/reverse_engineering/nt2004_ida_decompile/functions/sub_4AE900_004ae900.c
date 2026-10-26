void __thiscall sub_4AE900(_DWORD *this, char *String2)
{
  int v3; // eax
  int *v4; // esi

  if ( String2 && strlen(String2) && *(_DWORD *)(this[6] + 68) )
  {
    v3 = sub_4AD520(this, String2);
    v4 = (int *)v3;
    if ( v3 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 132))(v3);
      sub_4AD850(this, (int)v4);
      sub_4AE890(this, v4[3], v4[1]);
      (*(void (__thiscall **)(int *))(*v4 + 136))(v4);
    }
  }
}
