// positive sp value has been detected, the output may be wrong!
int __thiscall sub_4D93B7(
        _DWORD *this,
        int a2,
        const CHAR *a3,
        int a4,
        int a5,
        int a6,
        int a7,
        char a8,
        char a9,
        char a10,
        char a11)
{
  const CHAR *v12; // eax
  const char *v13; // eax
  _BYTE *v15; // esi
  const CHAR *v16; // eax
  _DWORD *v17; // ecx
  _BYTE v19[61]; // [esp-8h] [ebp-4Ch] BYREF
  __int16 v20; // [esp+35h] [ebp-Fh]
  char v21; // [esp+37h] [ebp-Dh]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+38h] [ebp-Ch]
  int v23; // [esp+40h] [ebp-4h]
  void *v24; // [esp+48h] [ebp+4h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  memset(v19, 0, sizeof(v19));
  v20 = 0;
  v21 = 0;
  v12 = (const CHAR *)this[44];
  if ( !v12 )
    v12 = WindowName;
  sub_630FE0(v19, v12, 63);
  v21 = 0;
  v13 = (const char *)sub_6331DF(v19, CommandLine);
  if ( v13 )
    this[135] = j__atol(v13);
  if ( !a2 )
    return -1;
  v24 = operator new(0x130u);
  v23 = 0;
  if ( v24 )
    v15 = (_BYTE *)sub_4D8D70();
  else
    v15 = 0;
  v23 = -1;
  sub_615860(a2);
  v16 = a3;
  if ( !a3 )
  {
    v16 = (const CHAR *)this[42];
    if ( !v16 )
      v16 = WindowName;
  }
  sub_615860(v16);
  if ( a4 )
    sub_615860(a4);
  if ( a5 )
    sub_615860(a5);
  if ( a7 )
    sub_615860(a7);
  v15[301] = a9;
  v15[300] = a8;
  v15[302] = a10;
  v15[303] = a11;
  sub_4CD360();
  sub_4CE0F0(v17);
  (*(void (__thiscall **)(_DWORD *, int))(*this + 176))(this, a2);
  return 0;
}
