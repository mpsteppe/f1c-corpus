void __thiscall sub_5F2A30(_DWORD *this, int a2)
{
  int v2; // eax

  if ( this[1202] != a2 )
  {
    v2 = this[2387];
    this[1202] = a2;
    this[2] = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 22, a2);
  }
}
