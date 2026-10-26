// f1c  0x0058a42f  size=182
int __cdecl sub_58A42F(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ebx
  int v10; // [esp+0h] [ebp-40h] BYREF
  int v11; // [esp+Ch] [ebp-34h]
  _DWORD v12[11]; // [esp+10h] [ebp-30h] BYREF
  int v13; // [esp+3Ch] [ebp-4h]
  int savedregs; // [esp+40h] [ebp+0h] BYREF

  v12[3] = sub_58A4E5;
  v12[4] = a5;
  v12[5] = a2;
  v12[6] = a6;
  v12[7] = a7;
  v13 = 0;
  v12[8] = &loc_58A4B7;
  v12[9] = &v10;
  v12[10] = &savedregs;
  v12[2] = NtCurrentTeb()->NtTib.ExceptionList;
  v11 = 1;
  v12[0] = a1;
  v12[1] = a3;
  v7 = sub_58E0C7(*a1, v12);
  (*(void (**)(void))(v7 + 104))();
  v11 = 0;
  if ( v13 )
  {
    ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
    ExceptionList->Next = ExceptionList->Next;
  }
  return v11;
}
