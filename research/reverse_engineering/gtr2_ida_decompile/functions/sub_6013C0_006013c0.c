int __thiscall sub_6013C0(_DWORD *this)
{
  int v2; // eax

  v2 = this[2386];
  if ( v2 )
  {
    this[2] = (*(int (__stdcall **)(int))(*(_DWORD *)v2 + 8))(v2);
    this[2386] = 0;
  }
  return 0;
}
