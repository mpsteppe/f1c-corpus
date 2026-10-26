bool __thiscall sub_463E00(void *this, int a2, float a3)
{
  if ( a3 < 0.0 )
    a3 = flt_769A90;
  sub_45DFA0((unsigned __int8 *)(*(_DWORD *)this + 27716), a2, (float *)&a2, 0.0);
  return a3 < fabs(*(float *)&a2);
}
