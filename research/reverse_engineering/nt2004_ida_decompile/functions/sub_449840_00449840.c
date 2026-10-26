void __thiscall sub_449840(int this, char a2)
{
  bool v2; // c0
  int v3; // edx
  double v4; // st7

  v2 = *(double *)(this + 7936) < *(double *)(this + 7976);
  *(_BYTE *)(this + 7934) = 1;
  if ( a2 )
  {
    if ( v2 )
    {
      v3 = *(_DWORD *)(this + 7980);
      *(_DWORD *)(this + 7936) = *(_DWORD *)(this + 7976);
      *(_DWORD *)(this + 7940) = v3;
    }
  }
  else
  {
    if ( v2 )
    {
      v4 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
      *(double *)(this + 8116) = v4 * *(double *)(this + 8132) + *(double *)(this + 8140) + *(double *)(this + 8124);
    }
    sub_526050(40, 2, 1.0, 1065353216);
  }
}
