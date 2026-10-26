const CHAR *__thiscall sub_4DA220(_DWORD *this)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  int v3; // eax
  int v4; // esi
  unsigned __int64 v5; // rax
  int v6; // ebx
  const CHAR *result; // eax
  int v8; // edx
  void *v9; // ebx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  const char **v13; // edi
  const char *v14; // esi
  const char *v15; // eax
  int v16; // [esp-14h] [ebp-34h]
  int v17; // [esp+8h] [ebp-18h] BYREF
  int v18; // [esp+Ch] [ebp-14h] BYREF
  void *i; // [esp+10h] [ebp-10h]
  struct _EXCEPTION_REGISTRATION_RECORD *v20; // [esp+14h] [ebp-Ch]
  void *v21; // [esp+18h] [ebp-8h]
  int v22; // [esp+1Ch] [ebp-4h]

  v22 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v21 = &loc_6E5106;
  v20 = ExceptionList;
  if ( !this[67] )
  {
    v22 = 0;
    if ( operator new(0x70u) )
      v3 = sub_4D9F90();
    else
      v3 = 0;
    this[67] = v3;
    sub_615860("Root");
    i = operator new(0x70u);
    v22 = 1;
    if ( i )
      v4 = sub_4D9F90();
    else
      v4 = 0;
    v22 = -1;
    sub_615860("Empty");
    *(_DWORD *)(v4 + 24) = this[67];
    sub_5FDFB0(v4, 1);
  }
  sub_4D3610(this, this[67], this[3], this[1], 0.0);
  v16 = this[67];
  v17 = 0;
  v18 = 0;
  sub_4D3930(v16, &v17, &v18);
  v17 = (unsigned __int64)(800.0 / (double)*(int *)dword_903EB8 * (double)v17);
  v5 = (unsigned __int64)(600.0 / (double)dword_903EBC * (double)v18);
  HIDWORD(v5) = this[1];
  v18 = (unsigned __int64)(600.0 / (double)dword_903EBC * (double)v18);
  sub_4E2B30(v17 - this[3], v5 - HIDWORD(v5));
  sub_4D58D0();
  v6 = this[67];
  result = *(const CHAR **)(v6 + 16);
  if ( !result )
    result = WindowName;
  v8 = 0;
  if ( strcmp(result, WindowName) )
  {
    result = *(const CHAR **)(v6 + 40);
    if ( (int)result > 0 )
    {
      v9 = *(void **)(v6 + 16);
      for ( i = v9; ; v9 = i )
      {
        v10 = v8;
        if ( v8 < 0 )
          goto LABEL_21;
        v11 = this[67];
        if ( v8 >= *(_DWORD *)(v11 + 40) )
          goto LABEL_21;
        v12 = *(_DWORD *)(v11 + 28);
        if ( v8 > 0 )
          break;
LABEL_20:
        if ( !v12 )
          goto LABEL_21;
        v13 = *(const char ***)v12;
LABEL_23:
        v14 = *v13;
        if ( !*v13 )
          v14 = WindowName;
        v15 = (const char *)v9;
        if ( !v9 )
          v15 = WindowName;
        if ( !strcmp(v15, v14) )
          return (const CHAR *)sub_4D5AD0((int)v13);
        result = (const CHAR *)this[67];
        if ( ++v8 >= *((_DWORD *)result + 10) )
          return result;
      }
      while ( v12 )
      {
        v12 = *(_DWORD *)(v12 + 4);
        if ( --v10 <= 0 )
          goto LABEL_20;
      }
LABEL_21:
      v13 = 0;
      goto LABEL_23;
    }
  }
  return result;
}
