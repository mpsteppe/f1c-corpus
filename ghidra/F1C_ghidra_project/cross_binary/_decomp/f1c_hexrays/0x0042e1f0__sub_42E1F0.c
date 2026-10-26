// f1c  0x0042e1f0  size=157
int __thiscall sub_42E1F0(char *this, int a2, int a3, int a4, double a5)
{
  double *v6; // edi
  int v7; // eax
  double v8; // st7
  int *v9; // edi
  int result; // eax
  int v11; // esi
  double v12; // [esp+Ch] [ebp-8h] BYREF

  if ( a3 )
  {
    v6 = (double *)(this + 8);
    if ( sub_565AA0(a3, this, this + 8, &v12, 0) )
    {
      v7 = sub_587BDC(v12);
      v8 = a5 * *(double *)this;
      *((_DWORD *)this + 4) = v7;
      *(double *)this = v8;
      *v6 = a5 * *v6;
    }
  }
  v9 = (int *)(this + 20);
  result = sub_565760(a4, this + 20, 0, 0, 0);
  if ( result )
  {
    v11 = *((_DWORD *)this + 4);
    if ( v11 <= 0 )
    {
      *v9 = 0;
    }
    else
    {
      result = *v9;
      if ( *v9 >= 0 )
      {
        if ( result >= v11 )
          result = v11 - 1;
        *v9 = result;
      }
      else
      {
        result = 0;
        *v9 = 0;
      }
    }
  }
  return result;
}
