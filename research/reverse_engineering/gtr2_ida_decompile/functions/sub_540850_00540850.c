void __thiscall sub_540850(void *this, float a2)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  int v4; // eax
  double v5; // st7
  double v6; // st6
  float v7; // eax
  double v8; // st7
  const CHAR ***v9; // esi
  const CHAR **v10; // esi
  const CHAR *v11; // eax
  _BYTE v12[8]; // [esp+28h] [ebp-14h] BYREF
  struct _EXCEPTION_REGISTRATION_RECORD *v13; // [esp+30h] [ebp-Ch]
  void *v14; // [esp+34h] [ebp-8h]
  int v15; // [esp+38h] [ebp-4h]
  float v16; // [esp+40h] [ebp+4h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v15 = -1;
  v14 = &loc_6E97A8;
  v13 = ExceptionList;
  if ( a2 <= 0.0 )
  {
    if ( dbl_FB1D08 >= 0.1 )
      a2 = 0.1;
    else
      a2 = dbl_FB1D08;
  }
  if ( *((_BYTE *)this + 16) && dword_BE1D10 && *(float *)(dword_BE1D10 + 4) > 0.0 )
  {
    if ( !(*(int (**)(void))(*(_DWORD *)dword_BE1D10 + 8))() )
    {
      sub_40B430();
      if ( *((int *)this + 3) <= 0 )
      {
        sub_458030();
        if ( ++dword_BE1D08 >= 4 )
          dword_BE1D08 = 0;
      }
      else
      {
        if ( !sub_473B70() )
          *((_DWORD *)this + 2) = *(_DWORD *)this;
        v9 = (const CHAR ***)*((_DWORD *)this + 2);
        if ( v9 )
          v10 = *v9;
        else
          v10 = 0;
        v11 = *v10;
        if ( !*v10 )
          v11 = WindowName;
        sub_615860(v11);
      }
      (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)dword_BE1D10 + 4))(dword_BE1D10, v12, 1);
      v15 = -1;
      goto LABEL_28;
    }
    v4 = *((_DWORD *)this + 5);
    if ( v4 )
    {
      v5 = *(float *)(dword_BE1D10 + 4);
      v6 = a2 * *((float *)this + 6);
      if ( v4 == 1 )
      {
        v16 = v6 + v5;
        if ( v16 >= (double)flt_B709FC )
        {
          v7 = flt_B709FC;
          *((_DWORD *)this + 5) = 0;
          (*(void (__thiscall **)(int, float))(*(_DWORD *)dword_BE1D10 + 28))(dword_BE1D10, COERCE_FLOAT(LODWORD(v7)));
          goto LABEL_28;
        }
      }
      else
      {
        v8 = v5 - v6;
        v16 = v8;
        if ( v8 <= 0.0 )
        {
          *((_DWORD *)this + 5) = 0;
          v16 = 0.0;
          (*(void (__thiscall **)(int))(*(_DWORD *)dword_BE1D10 + 12))(dword_BE1D10);
          *((_BYTE *)this + 16) = 0;
        }
      }
      (*(void (__thiscall **)(int, float))(*(_DWORD *)dword_BE1D10 + 28))(dword_BE1D10, COERCE_FLOAT(LODWORD(v16)));
    }
LABEL_28:
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_BE1D10 + 24))(dword_BE1D10);
  }
}
