// positive sp value has been detected, the output may be wrong!
int __usercall sub_4435CB@<eax>(int a1@<edi>, int a2@<esi>, int a3, int a4, int a5, const char *a6, ...)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  _DWORD *v7; // edi
  int i; // esi
  int v9; // ecx
  int v11; // [esp-101Ch] [ebp-1030h] BYREF
  _DWORD v12[3]; // [esp-1018h] [ebp-102Ch] BYREF
  void *v13; // [esp-100Ch] [ebp-1020h] BYREF
  int v14; // [esp-FF4h] [ebp-1008h] BYREF
  char v15; // [esp-FF0h] [ebp-1004h] BYREF
  int v16; // [esp+4h] [ebp-10h]
  int v17; // [esp+10h] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+14h] [ebp+0h]
  va_list va; // [esp+28h] [ebp+14h] BYREF

  va_start(va, a6);
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v13 = &loc_6ED4D6;
  v12[2] = ExceptionList;
  sub_631BD0();
  v12[1] = a2;
  v17 = dword_912B08;
  v12[0] = a1;
  vsprintf(&v15, a6, va);
  sub_4050C0((int)WindowName);
  sub_4050C0((int)&v14);
  LOBYTE(retaddr) = 1;
  v7 = (_DWORD *)sub_5C6150();
  for ( i = 0; i < *v7; ++i )
  {
    v9 = *(_DWORD *)(v7[2] + 4 * i);
    if ( v9 )
      (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v9 + 4))(v9, v12);
  }
  LOBYTE(v17) = 0;
  sub_5A8840(&v11);
  v17 = -1;
  sub_5A8840(&v13);
  return ((int (__thiscall *)(int))sub_6349BB)(v16);
}
