DWORD __stdcall StartAddress(char *lpThreadParameter)
{
  void *v1; // eax
  DWORD v2; // eax
  char *v3; // eax
  char v4; // bl
  double v5; // st7
  DWORD v6; // eax
  int v7; // edx
  int v8; // edi
  int v9; // edi
  double v10; // st7
  float v12; // [esp+10h] [ebp-C4h]
  float v13; // [esp+14h] [ebp-C0h]
  float v14; // [esp+18h] [ebp-BCh]
  _BYTE v15[80]; // [esp+20h] [ebp-B4h] BYREF
  _BYTE v16[80]; // [esp+78h] [ebp-5Ch] BYREF
  int v17; // [esp+D0h] [ebp-4h]

  sub_5A3E40();
  v17 = 1;
  sub_5A3E40();
  v13 = 0.0;
  while ( 1 )
  {
    v1 = (void *)*((_DWORD *)lpThreadParameter + 5);
    if ( v1 && ((v2 = WaitForSingleObject(v1, *((_DWORD *)lpThreadParameter + 6))) == 0 || v2 == 128) )
      v3 = lpThreadParameter + 16;
    else
      v3 = 0;
    v4 = *v3;
    if ( *((_DWORD *)lpThreadParameter + 5) )
      ReleaseMutex(*((HANDLE *)lpThreadParameter + 5));
    if ( v4 )
      break;
    if ( v14 + sub_617F80(v15) > 0.0078125 )
    {
      if ( lpThreadParameter )
        (*(void (__thiscall **)(char *))(*(_DWORD *)lpThreadParameter + 168))(lpThreadParameter);
      v14 = 0.0;
      sub_617E70(v15);
      v5 = sub_617ED0(v16);
      v12 = v5;
      if ( v5 >= 0.0 )
      {
        if ( v12 > 10.0 )
          v12 = 10.0;
      }
      else
      {
        v12 = 0.0;
      }
      v6 = WaitForSingleObject(*((HANDLE *)lpThreadParameter + 56), 1u);
      if ( v6 != 258 && v6 != -1 && *((_DWORD *)lpThreadParameter + 56) )
        ReleaseMutex(*((HANDLE *)lpThreadParameter + 56));
      v7 = *(_DWORD *)lpThreadParameter;
      v8 = 0;
      *((double *)lpThreadParameter + 30) = v12 + *((double *)lpThreadParameter + 30);
      if ( (*(unsigned __int8 (__thiscall **)(char *))(v7 + 84))(lpThreadParameter) )
      {
        do
          ++v8;
        while ( v8 < 3
             && (*(unsigned __int8 (__thiscall **)(char *))(*(_DWORD *)lpThreadParameter + 84))(lpThreadParameter) );
      }
      v9 = 0;
      if ( (*(unsigned __int8 (__thiscall **)(char *))(*(_DWORD *)lpThreadParameter + 80))(lpThreadParameter) )
      {
        do
          ++v9;
        while ( v9 < 3
             && (*(unsigned __int8 (__thiscall **)(char *))(*(_DWORD *)lpThreadParameter + 80))(lpThreadParameter) );
      }
      v10 = v12 + v13;
      v13 = v10;
      if ( v10 > 0.333 )
      {
        sub_5A4E50(lpThreadParameter, v13);
        (*(void (__thiscall **)(char *, float))(*(_DWORD *)lpThreadParameter + 12))(
          lpThreadParameter,
          COERCE_FLOAT(LODWORD(v13)));
        v13 = 0.0;
      }
    }
    SleepEx(5u, 1);
  }
  LOBYTE(v17) = 0;
  nullsub_7(v15);
  v17 = -1;
  nullsub_7(v16);
  return 0;
}
