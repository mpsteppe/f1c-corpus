int __usercall sub_519B5D@<eax>(sbdt::PlayerFile *this@<ecx>, int a2@<edi>)
{
  char *v3; // eax
  const char *v4; // edx
  const char *v5; // eax
  int v6; // eax
  int v7; // edi
  _BYTE v9[4]; // [esp+0h] [ebp-12Ch] BYREF
  char Buffer[32]; // [esp+4h] [ebp-128h] BYREF
  char v11[253]; // [esp+24h] [ebp-108h] BYREF
  __int16 v12; // [esp+121h] [ebp-Bh]
  char v13; // [esp+123h] [ebp-9h]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+128h] [ebp-4h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  sub_616390(v9);
  sprintf(Buffer, off_6FF8A4, ".PLR");
  v3 = dword_91CB00;
  if ( !dword_91CB00 )
    v3 = (char *)WindowName;
  sub_615FE0(Buffer, 1, v3, 1);
  sub_615F10(2);
  v4 = (const char *)sub_615D40(v9);
  if ( v4 )
  {
    memset(v11, 0, sizeof(v11));
    v12 = 0;
    v13 = 0;
    v5 = dword_91CB00;
    if ( !dword_91CB00 )
      v5 = WindowName;
    sprintf(v11, "%s%s", v5, v4);
    v6 = sub_514EC0((char *)this, v11, 1);
  }
  else
  {
    sbdt::PlayerFile::Create(this, "PlayerNameNeverUsed");
    v6 = sub_519B50(a2);
    *((_BYTE *)this + 28324) = 1;
    *((_BYTE *)this + 28325) = 1;
  }
  v7 = v6;
  sub_616450(v9);
  return v7;
}
