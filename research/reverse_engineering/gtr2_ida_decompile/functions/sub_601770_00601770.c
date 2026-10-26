char __thiscall sub_601770(int this, char a2)
{
  int v3; // eax

  if ( a2 || (LOBYTE(v3) = *(_BYTE *)(this + 4812), (_BYTE)v3) )
  {
    v3 = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 9548) + 168))(*(_DWORD *)(this + 9548));
    if ( !v3 )
      *(_BYTE *)(this + 4812) = 0;
  }
  return v3;
}
