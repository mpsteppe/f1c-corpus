void sub_4EF8A0()
{
  int v0; // ecx
  int v1; // eax

  v0 = dword_7D6BB0;
  if ( dword_7D6BB0 )
  {
    if ( !dword_7D6BB8 )
    {
      v1 = (*(int (**)(void))(*(_DWORD *)dword_7D6BB0 + 100))();
      v0 = dword_7D6BB0;
      dword_7D6BB8 = v1;
    }
    if ( !dword_7D6BBC )
      dword_7D6BBC = (*(int (__thiscall **)(int))(*(_DWORD *)v0 + 100))(v0);
  }
}
