char __thiscall sub_491960(void *this, __int16 a2, __int16 a3, int a4, int a5)
{
  if ( a4 <= 0 || a5 <= 0 )
    return 0;
  sub_490EE0((void ***)(*(_DWORD *)this + 28), a2, a3, a4, a5);
  sub_490EE0((void ***)(*(_DWORD *)this + 44), a2, a3, a4, a5);
  return 1;
}
