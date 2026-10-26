int __thiscall sub_561040(int *this)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  int v3; // eax
  const char *v4; // ecx
  _DWORD *v5; // ebx
  int v6; // ebp
  const char *v7; // eax
  int v8; // esi
  int *v9; // eax
  bool v10; // zf
  const char *v11; // eax
  int v12; // esi
  const char *v13; // edx
  const char *v14; // ecx
  int result; // eax
  char Buffer[512]; // [esp+4h] [ebp-20Ch] BYREF
  struct _EXCEPTION_REGISTRATION_RECORD *v17; // [esp+204h] [ebp-Ch]
  void *v18; // [esp+208h] [ebp-8h]
  int v19; // [esp+20Ch] [ebp-4h]

  v19 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v18 = &loc_6E9C4E;
  v17 = ExceptionList;
  sub_560FE0(this);
  v3 = sub_615460(512);
  v4 = (const char *)dword_91CAE8;
  v5 = 0;
  v6 = v3;
  if ( !dword_91CAE8 )
    v4 = WindowName;
  v7 = *(const char **)dword_91CA70;
  if ( !*(_DWORD *)dword_91CA70 )
    v7 = WindowName;
  sprintf(Buffer, "%s%s", v7, v4);
  sub_615FE0("*.tyr", 1, Buffer, 1);
  v8 = sub_615D30(&unk_FAECBC);
  *this = v8;
  v9 = (int *)operator new(36 * v8 + 4);
  v19 = 0;
  if ( v9 )
  {
    v5 = v9 + 1;
    *v9 = v8;
    sub_630A11(v9 + 1, 36, v8, sub_560F80, sub_560F20);
  }
  v10 = *this == 0;
  v19 = -1;
  this[1] = (int)v5;
  if ( (v10 || !v5)
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\tire_manager.cpp", 1116) )
  {
    sub_561210((int)byte_FAE910, "No tire brands (*.tyr) in %s or memory allocation error", (char)Buffer);
  }
  sub_615D10(&unk_FAECBC);
  v11 = (const char *)sub_615D40(&unk_FAECBC);
  if ( v11 )
  {
    v12 = 0;
    do
    {
      v13 = (const char *)dword_91CAE8;
      if ( !dword_91CAE8 )
        v13 = WindowName;
      v14 = *(const char **)dword_91CA70;
      if ( !*(_DWORD *)dword_91CA70 )
        v14 = WindowName;
      sprintf(Buffer, "%s%s%s", v14, v13, v11);
      v12 += 36;
      sub_560AE0();
      if ( !(unsigned __int8)sub_615CE0(&unk_FAECBC) )
        break;
      v11 = (const char *)sub_615D40(&unk_FAECBC);
    }
    while ( v11 );
  }
  result = sub_615FC0(&unk_FAECBC);
  if ( v6 != 512 )
    return sub_6154A0(v6);
  return result;
}
