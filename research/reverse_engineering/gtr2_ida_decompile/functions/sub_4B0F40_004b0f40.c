int __thiscall sub_4B0F40(_DWORD *this)
{
  bool *v1; // eax

  if ( *(_DWORD *)dword_B72314 == 3 || *(_DWORD *)dword_B72314 == 5 )
  {
    v1 = (bool *)this[69];
    if ( v1 )
    {
      *v1 = !*v1;
      sub_49DC50(this);
    }
  }
  return 0;
}
