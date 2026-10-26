int __thiscall sub_565ED0(void *this)
{
  int *v1; // eax
  int v2; // eax

  v1 = *(int **)(*(_DWORD *)this + 8);
  if ( v1 && (v2 = *v1) != 0 )
    return v2 + 4;
  else
    return 0;
}

