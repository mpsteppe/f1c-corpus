int __thiscall sub_5263E0(void *this)
{
  int v2; // eax

  v2 = sub_526450();
  *(_DWORD *)this = v2;
  if ( !v2 )
    *(_DWORD *)this = sub_526570(0);
  return *(_DWORD *)this;
}
