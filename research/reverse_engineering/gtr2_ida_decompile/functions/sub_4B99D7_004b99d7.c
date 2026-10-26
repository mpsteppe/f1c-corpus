void __usercall sub_4B99D7(const CHAR ****a1@<ecx>, CHAR *a2@<esi>)
{
  const CHAR ****v3; // edi
  char *v4; // eax
  const CHAR **v5; // esi
  const CHAR *v6; // eax
  bool v7; // zf
  const CHAR *v8; // eax
  const CHAR ***v9; // eax
  int v11; // [esp+Ch] [ebp-968h] BYREF
  char v12[84]; // [esp+14h] [ebp-960h] BYREF
  _BYTE v13[8]; // [esp+68h] [ebp-90Ch] BYREF
  char v14[248]; // [esp+70h] [ebp-904h] BYREF
  char Str[2048]; // [esp+168h] [ebp-80Ch] BYREF
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+970h] [ebp-4h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v11 = -1;
  sub_615860("!");
  sub_613B30(v12);
  v3 = a1 + 150;
  Str[8] = 0;
  sub_409FB0(a1 + 150);
  ((void (__thiscall *)(const CHAR ****, char *, int))(*a1)[46])(a1, v14, 255);
  sub_615860(v13);
  if ( (unsigned __int8)sub_614460(v13, 1) && sub_613DE0(Str, 2047) )
  {
    do
    {
      v4 = strstr(Str, "\r");
      if ( v4 )
        *v4 = 0;
      v5 = (const CHAR **)operator new(8u);
      LOBYTE(ExceptionList) = 2;
      if ( v5 )
      {
        *v5 = 0;
        v5[1] = (const CHAR *)-1;
        sub_615860(Str);
      }
      else
      {
        v5 = 0;
      }
      v6 = *v5;
      v7 = *v5 == 0;
      LOBYTE(ExceptionList) = 1;
      if ( v7 || v6 == WindowName )
      {
        v8 = a2;
        if ( !a2 )
          v8 = WindowName;
        sub_615860(v8);
      }
      v9 = (const CHAR ***)operator new(0xCu);
      if ( v9 )
      {
        *v9 = v5;
        v9[1] = 0;
        *((_BYTE *)v9 + 8) = 1;
      }
      else
      {
        v9 = 0;
      }
      if ( *v3 )
      {
        v3[1][1] = (const CHAR **)v9;
      }
      else
      {
        *v3 = v9;
        v3[2] = v9;
      }
      v3[3] = (const CHAR ***)((char *)v3[3] + 1);
      v3[1] = v9;
    }
    while ( sub_613DE0(Str, 2047) );
  }
  LOBYTE(ExceptionList) = 0;
  sub_614140(&v11);
  if ( a2 )
    j_j__free(a2);
}
