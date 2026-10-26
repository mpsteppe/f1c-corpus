int __thiscall sub_5A59C0(int this, int a2)
{
  int result; // eax

  sub_5A6150(this, 0);
  if ( *(_DWORD *)(this + 8600) )
  {
    sub_5A65C0(this, *(_DWORD *)(this + 8600));
    if ( *(_DWORD *)(this + 8600) )
    {
      j_nullsub_6(*(void **)(this + 8600));
      sub_5BE8AE();
    }
    *(_DWORD *)(this + 8600) = 0;
  }
  if ( *(_DWORD *)(this + 8592) )
  {
    j_nullsub_6(*(void **)(this + 8592));
    sub_5BE8AE();
    *(_DWORD *)(this + 8592) = 0;
  }
  if ( *(_DWORD *)(this + 8596) )
  {
    j_nullsub_6(*(void **)(this + 8596));
    sub_5BE8AE();
    *(_DWORD *)(this + 8596) = 0;
  }
  result = *(_DWORD *)(this + 4448);
  if ( result )
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)result + 8))(*(_DWORD *)(this + 4448));
    *(_DWORD *)this = result;
    *(_DWORD *)(this + 4448) = 0;
  }
  return result;
}
