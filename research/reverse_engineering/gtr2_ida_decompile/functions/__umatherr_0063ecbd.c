double __cdecl _umatherr(int a1, int a2, int a3, int a4, int a5, int a6, double a7, int a8)
{
  int v8; // eax
  _UNKNOWN **v9; // eax
  _DWORD v11[6]; // [esp+0h] [ebp-20h] BYREF
  double v12; // [esp+18h] [ebp-8h]

  v8 = 0;
  while ( dword_913480[2 * v8] != a2 )
  {
    if ( ++v8 >= 29 )
    {
      v9 = 0;
      goto LABEL_5;
    }
  }
  v9 = (&off_913484)[2 * v8];
LABEL_5:
  v11[1] = v9;
  if ( v9 )
  {
    v11[2] = a3;
    v11[3] = a4;
    v11[4] = a5;
    v11[5] = a6;
    v12 = a7;
    v11[0] = a1;
    _ctrlfp(a8, 0xFFFF);
    if ( !sub_6AB05A(v11) )
      sub_63EC68(a1);
    return v12;
  }
  else
  {
    _ctrlfp(a8, 0xFFFF);
    sub_63EC68(a1);
    return a7;
  }
}
