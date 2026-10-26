int __thiscall sub_5F19B0(_DWORD *this)
{
  int v1; // eax

  v1 = this[2387];
  if ( v1 )
    return (*(int (__stdcall **)(int))(*(_DWORD *)v1 + 16))(v1);
  else
    return 0;
}
