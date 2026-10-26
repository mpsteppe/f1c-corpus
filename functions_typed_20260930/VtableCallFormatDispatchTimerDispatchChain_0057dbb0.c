int __thiscall sub_57DBB0(void *this, int a2, int a3, int a4, int a5)
{
  int v6; // edi
  float v8; // [esp+8h] [ebp-4h] BYREF

  v6 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 88))(this);
  sub_586800(0, 11, 0, 2, -1);
  v8 = MutexGuardedTimerRead(this);
  SingleFunctionCallWrapper_6a00(&v8, 4);
  NetworkPacketConstructor(*(_DWORD *)(v6 + 72), &a2);
  return ThreadSafeCallWithMutex(v6);
}

