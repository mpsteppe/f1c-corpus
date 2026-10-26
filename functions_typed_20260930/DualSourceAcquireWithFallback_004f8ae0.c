int __thiscall sub_4F8AE0(void *this)
{
  int v2; // eax

  v2 = sub_4F8B50();
  *(_DWORD *)this = v2;
  if ( !v2 )
    *(_DWORD *)this = GlobalCallbackDispatcher(0);
  return *(_DWORD *)this;
}

