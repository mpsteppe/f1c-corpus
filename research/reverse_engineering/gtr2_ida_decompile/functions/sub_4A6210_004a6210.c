int __thiscall sub_4A6210(int *this)
{
  int v1; // eax
  int v3; // eax

  if ( dword_B72338 )
  {
    v1 = *this;
    if ( dword_B72338 == 1 )
      this[67] = 1;
    else
      this[67] = 2;
    (*(void (__stdcall **)(int))(v1 + 44))(this[67]);
    return 0;
  }
  else
  {
    v3 = *this;
    this[67] = 0;
    (*(void (__stdcall **)(int))(v3 + 44))(this[67]);
    return 0;
  }
}
