DWORD __stdcall StartAddress(LPVOID lpThreadParameter)
{
  double v1; // st7
  bool v2; // c0
  char v3; // c2
  bool v4; // c3
  __int16 v5; // fps
  __int16 v6; // fps
  bool v7; // c0
  char v8; // c2
  bool v9; // c3
  int v10; // edi
  int v11; // edi
  double v12; // st7
  __int16 v13; // fps
  bool v14; // c0
  char v15; // c2
  bool v16; // c3
  float v18; // [esp+4h] [ebp-B4h]
  float v19; // [esp+8h] [ebp-B0h]
  _DWORD v20[20]; // [esp+Ch] [ebp-ACh] BYREF
  _DWORD v21[20]; // [esp+5Ch] [ebp-5Ch] BYREF
  int v22; // [esp+B4h] [ebp-4h]

  TimerInitWithSEH(v21);
  v22 = 0;
  TimerInitWithSEH(v20);
  LOBYTE(v22) = 1;
  v19 = 0.0;
  while ( !MutexProtectedDataReadWithTimedWait((int)lpThreadParameter, 0) )
  {
    v1 = FloatAdditionReturnsFUN00568d90Param1((char *)v20);
    v2 = v1 < 0.0078125;
    v3 = 0;
    v4 = v1 == 0.0078125;
    if ( (v5 & 0x4100) == 0 )
    {
      FloatSetWithTimingCall(v20, 0);
      SingleFunctionCallWrapper_3690((int)v21);
      v18 = v1;
      if ( v1 >= 0.0 )
      {
        v7 = v18 < 10.0;
        v8 = 0;
        v9 = v18 == 10.0;
        if ( (v6 & 0x4100) == 0 )
          v18 = 10.0;
      }
      else
      {
        v18 = 0.0;
      }
      MutexWaitWith1msTimeoutRelease(lpThreadParameter);
      sub_584110(v18);
      v10 = 0;
      if ( (*(unsigned __int8 (__thiscall **)(LPVOID))(*(_DWORD *)lpThreadParameter + 84))(lpThreadParameter) )
      {
        do
          ++v10;
        while ( v10 < 3
             && (*(unsigned __int8 (__thiscall **)(LPVOID))(*(_DWORD *)lpThreadParameter + 84))(lpThreadParameter) );
      }
      v11 = 0;
      if ( (*(unsigned __int8 (__thiscall **)(LPVOID))(*(_DWORD *)lpThreadParameter + 80))(lpThreadParameter) )
      {
        do
          ++v11;
        while ( v11 < 3
             && (*(unsigned __int8 (__thiscall **)(LPVOID))(*(_DWORD *)lpThreadParameter + 80))(lpThreadParameter) );
      }
      v12 = v18 + v19;
      v19 = v12;
      v14 = v12 < 0.333;
      v15 = 0;
      v16 = v12 == 0.333;
      if ( (v13 & 0x4100) == 0 )
      {
        EmptyStub_0170();
        sub_583F50(v19);
        (*(void (__thiscall **)(LPVOID, float))(*(_DWORD *)lpThreadParameter + 12))(
          lpThreadParameter,
          COERCE_FLOAT(LODWORD(v19)));
        v19 = 0.0;
      }
    }
    SleepEx(5u, 1);
  }
  LOBYTE(v22) = 0;
  SingleFunctionCallWrapper_3650();
  v22 = -1;
  SingleFunctionCallWrapper_3650();
  return 0;
}

