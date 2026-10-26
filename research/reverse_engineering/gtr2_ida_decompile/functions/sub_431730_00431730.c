int __thiscall sub_431730(char *this, int a2, char *a3, char *String2, double a5)
{
  double *v6; // edi
  double v7; // st7
  int *v8; // edi
  int result; // eax
  int v10; // esi
  int v11[2]; // [esp+Ch] [ebp-8h] BYREF

  if ( a3 )
  {
    v6 = (double *)(this + 8);
    if ( sub_6136D0(a3, (int)this, (int)(this + 8), (int)v11, 0) )
    {
      v7 = a5 * *(double *)this;
      *((_DWORD *)this + 4) = (unsigned __int64)*(double *)v11;
      *(double *)this = v7;
      *v6 = a5 * *v6;
    }
  }
  v8 = (int *)(this + 20);
  result = sub_6133A0(String2, (int)(this + 20), 0, 0, 0);
  if ( result )
  {
    v10 = *((_DWORD *)this + 4);
    if ( v10 <= 0 )
    {
      *v8 = 0;
    }
    else
    {
      result = *v8;
      if ( *v8 >= 0 )
      {
        if ( result >= v10 )
          result = v10 - 1;
        *v8 = result;
      }
      else
      {
        result = 0;
        *v8 = 0;
      }
    }
  }
  return result;
}
