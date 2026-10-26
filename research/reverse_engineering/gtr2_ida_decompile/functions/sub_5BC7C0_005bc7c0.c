void __thiscall sub_5BC7C0(void *this)
{
  int v2; // eax
  void *v3; // esi

  if ( (*(int (__thiscall **)(void *))(*(_DWORD *)this + 12))(this) )
  {
    v2 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 12))(this);
    v3 = (void *)v2;
    if ( v2 )
    {
      sub_5C2630(v2);
      j__free(v3);
    }
  }
}
