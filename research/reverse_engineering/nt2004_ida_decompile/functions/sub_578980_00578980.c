int __thiscall sub_578980(void *this)
{
  int *v1; // eax
  int v2; // eax

  v1 = *(int **)(*(_DWORD *)this + 8);
  if ( v1 && (v2 = *v1) != 0 )
    return v2 + 4;
  else
    return 0;
}
